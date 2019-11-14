import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import BppTableModel 0.1
import BppTable 0.1

import "assets/font-awesome-qml"

Window {
    visible: true
    width: 840
    height: 480
    title: qsTr("Hello World")

    FontAwesome {
       id: awesome
       resource: "qrc:/assets/font-awesome-qml/fontawesome-webfont.ttf"
    }

    function fillTable(){
        var parameters = [];
        var sqlQuery = "select col1,col6,col2,col3,col4,round( (col1 / 200.0) * 10 ) * 10 ,col8,col9 from table1"

        if(txtSearch.text.length>0){
            sqlQuery = sqlQuery + " where upper(col4) like '%' || ? || '%'";
            parameters.push( txtSearch.text.toUpperCase() )
        }

        bGrid.fillFromQuery( workDb, sqlQuery, parameters );

        txtInfo.text = 'Table has: ' + bGrid.rows() + " rows"
    }

    ColumnLayout {
        id: gridLayout
        anchors.fill: parent
        anchors.margins: 10

        RowLayout {
            Button {
                text: "Hide Cost"
                onPressed: {
                    bGrid.columns.get(1).visible = !bGrid.columns.get(1).visible
                }
            }

            Button {
                text: "Cost <-> Price"
                onPressed: {
                    if( bGrid.columns.get(1).title !== "Price" ) {
                        bGrid.columns.get(1).title = "Price"
                        bGrid.columns.get(1).width = 80
                    }
                    else {
                        bGrid.columns.get(1).title = "Cost"
                        bGrid.columns.get(1).width = 100
                    }
                }
            }

            Text {
                id: txtInfo
                font.pointSize: 11
                text: ""
            }
        }

        RowLayout{
            Layout.fillWidth: true
            TextField{
                id: txtSearch
                Layout.fillWidth: true
                placeholderText: qsTr("Enter search query on name column")
            }
            Button{
                text: "Fill table"
                onPressed: {
                    fillTable();
                }
            }
        }

        ListModel{
            id: modColumns
            ListElement { width: 50; title: "ID"; dataType: BTColumn.Int }
            ListElement { title: "Cost"; dataType: BTColumn.Dbl }
            ListElement { width: 40; title: ""; sort: 4; view: Enums.CellView.CommandButton; command: Enums.Commands.DoCmd1 }
            ListElement { width: 40; title: ""; sort: 4; view: Enums.CellView.CommandButton; command: Enums.Commands.DoCmd2 }
            ListElement { minWidth: 140; title: "Name" }
            ListElement { title: "Progress"; dataType: BTColumn.Int ; view: Enums.CellView.ProgressView }
            ListElement { minWidth: 120; title: "Date"; dataType: BTColumn.Date }
            ListElement { width: 170; title: "DateTime"; dataType: BTColumn.DateTime }
        }

        CompGrid {
            id: bGrid
            Layout.fillWidth: true
            Layout.fillHeight: true

            dataHeight: 40
            dateFormat: "MMM yyyy"

            Component {
                id: cellDelegate

                Rectangle {
                    id: cellContainer
                    implicitHeight: bGrid.dataHeight
                    color: row % 2 == 0 ? bGrid.dataBkOdd : bGrid.dataBkEven
                    visible: model.visible

                    CellText {
                        visible: view === Enums.CellView.SimpleText
                        text: bGrid.formatDisplay(display, dataType, 2)
                        horizontalAlignment: bGrid.getAlign(dataType)
                    }

                    ButtonAction {
                        visible: view === Enums.CellView.CommandButton
                        commandId: command
                    }

                    ProgressBar {
                        visible: view === Enums.CellView.ProgressView
                        anchors.centerIn: parent
                        width: 80
                        from: 0
                        to: 100
                        value: dataType === BTColumn.Int ? display : 0
                    }

                    CellSeparator{
                        color: bGrid.dataLines
                    }

                    CellClicker {
                        grid: bGrid
                        viewCommand: Enums.CellView.CommandButton
                        viewId: view
                        commandId: command
                        onDoCommand: {
                            txtInfo.text = 'Clicked: ' + commandId + ', value: ' + display + ', ID: ' + bGrid.cellValue(row,0)
                        }
                    }
                }
            }

            cellDelegate: cellDelegate

            fromListModel: modColumns
        }
    }
}
