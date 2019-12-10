import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import BppTableModel 0.1
import BppTable 0.1

Window {
    visible: true
    width: 840
    height: 480
    title: qsTr("Hello World")

    function fillTable(){
        var parameters = [];
        var sqlQuery = "SELECT pkid,null,null,year,city,sport,gender,
            golds,
            silvers,
            bronzes,
            round(cast(golds as double) / (golds + silvers + bronzes) * 100.0) as p_golds,
            golds + silvers + bronzes as total
            FROM olimpic_ita_medals"

        if(txtSearch.text.length>0 || cmbGender.currentIndex > 0){
            sqlQuery += " where";
        }

        if(txtSearch.text.length>0){
            sqlQuery += " (city like '%' || ? || '%' or sport like '%' || ? || '%')";
            parameters.push( txtSearch.text.toLowerCase() )
            parameters.push( txtSearch.text.toLowerCase() )
        }

        if(cmbGender.currentIndex > 0) {
            if(txtSearch.text.length>0) sqlQuery += " AND"
            sqlQuery += " gender = ?";
            parameters.push( cmbGender.model[cmbGender.currentIndex] )
        }

        var startTime = new Date().getTime()

        bGrid.fillFromQuery( workDb, sqlQuery, parameters );

        console.log( new Date().getTime() - startTime + " ms" );

        txtInfo.text = 'Table has: ' + bGrid.rows() + " rows"
    }

    function formatGender(display, dataType){
        if(dataType === BTColumn.Str) {
            if(display === "Men")
                return Fa.fa_male;
            return Fa.fa_female;
        }
        return "";
    }

    function formatGenderColor(display, dataType){
        if(dataType === BTColumn.Str) {
            if(display === "Men")
                return "blue";
            return "deeppink";
        }
        return "black";
    }

    ColumnLayout {
        id: gridLayout
        anchors.fill: parent
        anchors.margins: 10

        RowLayout {
            Button {
                property bool colVisible: true
                text: colVisible ? "Hide City" : "Show City"
                onPressed: {
                    bGrid.columns.get(4).visible = !bGrid.columns.get(4).visible
                    colVisible = bGrid.columns.get(4).visible
                }
            }

            Button {
                text: "ID <-> PK"
                onPressed: {
                    if( bGrid.columns.get(0).title !== "ID" ) {
                        bGrid.columns.get(0).title = "ID"
                        bGrid.columns.get(0).width = 40
                    }
                    else {
                        bGrid.columns.get(0).title = "PK"
                        bGrid.columns.get(0).width = 50
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
            ComboBox{
                id: cmbGender
                Layout.minimumWidth: 140
                model: ["<gender>", "Men", "Women"]
                currentIndex: 0
            }
            TextField{
                id: txtSearch
                Layout.fillWidth: true
                placeholderText: qsTr("Enter search query on city/sport column")
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
            ListElement { width: 40; title: "ID"; dataType: BTColumn.Int; role: "id" }
            ListElement { width: 40; title: ""; sort: 4; view: Enums.CellView.CommandButton; command: Enums.Commands.DoCmd1; dataRef1: "id" }
            ListElement { width: 40; title: ""; sort: 4; view: Enums.CellView.CommandButton; command: Enums.Commands.DoCmd2; dataRef1: "id" }
            ListElement { width: 60; title: "Year"; dataType: BTColumn.Int }
            ListElement { minWidth: 120; title: "City" }
            ListElement { minWidth: 120; title: "Sport" }
            ListElement { width: 40; title: ""; view: Enums.CellView.GenderCell }
            ListElement { width: 70; title: "Golds"; dataType: BTColumn.Int }
            ListElement { width: 70; title: "Silv."; dataType: BTColumn.Int }
            ListElement { width: 70; title: "Bronz."; dataType: BTColumn.Int }
            ListElement { width: 70; title: "% Gold"; dataType: BTColumn.Int; view: Enums.CellView.ProgressView }
            ListElement { width: 50; title: "Tot"; dataType: BTColumn.Int }
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
                        font.capitalization: Font.Capitalize
                    }

                    CellText {
                        visible: view === Enums.CellView.GenderCell
                        font.family: Fa.solid
                        text: formatGender(display, dataType)
                        color: formatGenderColor(display, dataType)
                        horizontalAlignment: Text.AlignHCenter;
                        font.pointSize: 14
                    }

                    ButtonAction {
                        visible: view === Enums.CellView.CommandButton
                        commandId: command
                    }

                    ProgressBar {
                        id: control
                        visible: view === Enums.CellView.ProgressView
                        anchors.centerIn: parent
                        width: 60
                        from: 0
                        to: 100
                        value: dataType === BTColumn.Int ? display : 0

                        background: Rectangle {
                            implicitHeight: 18
                            color: "lavenderblush"
                        }

                        contentItem: Item {
                            Rectangle {
                                id: rectLeft
                                width: control.visualPosition * parent.width
                                height: parent.height
                                color: "gold"
                            }
                        }
                    }

                    CellClicker {
                        grid: bGrid
                        linkEnabled: view === Enums.CellView.CommandButton
                        onDoCommand: {
                            txtInfo.text = 'Clicked: ' + command + ', ID: ' + ref1 + ', Year: ' + bGrid.cellValue(row,3)
                        }
                    }
                }
            }

            cellDelegate: cellDelegate

            fromListModel: modColumns
        }
    }
}
