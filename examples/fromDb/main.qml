import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.13
import BppTableModel 0.1
import BppTable 0.1

import "assets/font-awesome-qml"

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    FontAwesome {
       id: awesome
       resource: "qrc:/assets/font-awesome-qml/fontawesome-webfont.ttf"
    }

    ColumnLayout {
        id: gridLayout
        anchors.fill: parent
        anchors.margins: 10

        RowLayout {
            Button {
                text: "fillDb"
                onPressed: {
                    bGrid.fillFromQuery( workDb,
                                        "select col1,col6,col2,col3,col4,round( (col1 / 200.0) * 10 ) * 10 ,col8,col9 from table1 where col1>=? and col1<?",
                                        [0, 150]
                    );
                }
            }

            Button {
                text: "changeHead"
                onPressed: {
                    var newCols = bGrid.columns;
                    newCols[1].title = "Price";
                    newCols[1].width = 180;
                    bGrid.columns = newCols;
                }
            }
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
                        value: dataType === BppTableModel.Int ? display : 0
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
                            console.log('Clicked:', commandId, display)
                        }
                    }
                }
            }

            cellDelegate: cellDelegate

            columns: [
                { width: 50, title: "ID", dataType: BppTableModel.Int, role: "pkid" },
                { title: "Cost", dataType: BppTableModel.Dbl, role: "cost" },
                { width: 40, title: "", sort: 4, view: Enums.CellView.CommandButton, command: Enums.Commands.DoCmd1 },
                { width: 40, title: "", sort: 4, view: Enums.CellView.CommandButton, command: Enums.Commands.DoCmd2 },
                { minWidth: 140, title: "Name", role: "name" },
                { title: "Progress", dataType: BppTableModel.Int , view: Enums.CellView.ProgressView },
                { minWidth: 120, title: "Date", dataType: BppTableModel.Date, role: "dt" },
                { width: 170, title: "DateTime", dataType: BppTableModel.DateTime, role: "dtt" }
             ]
        }
    }
}
