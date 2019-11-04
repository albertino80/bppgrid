import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import BppTableModel 0.1
import BppTable 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var fruitList: [
        {pkid: 1, name: "Apple", cost: 2.45, prog: 80},
        {pkid: 2, name: "Orange", cost: 3.45, prog: 20},
        {pkid: 3, name: "Banana", cost: 1.459, prog: 100},
        {pkid: 4, name: "Strawberry", cost: 1.1467, prog: 50}
    ];

    CompGrid {
        id: bGrid
        anchors.fill: parent
        anchors.margins: 10

        dataHeight: 50

        Component {
            id: cellItem

            Rectangle {
                implicitHeight: bGrid.dataHeight
                color: bGrid.getCellBackground(row)

                CellText {
                    visible: view === Enums.CellView.SimpleText
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: bGrid.getAlign(dataType)
                }

                CellButton {
                    visible: view === Enums.CellView.CommandButton
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: Text.AlignHCenter
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

        cellDelegate: cellItem

        columns: [
            { role: "pkid", title: "ID", dataType: BppTableModel.Int },
            { role: "name", title: "Name", minWidth: 140, view: Enums.CellView.CommandButton, command: Enums.Commands.DoCmd1 },
            { role: "cost", title: "Cost", dataType: BppTableModel.Dbl },
            { role: "prog", title: "Progress", width: 100, dataType: BppTableModel.Int, view: Enums.CellView.ProgressView },
         ]
    }

    Component.onCompleted: {
        bGrid.fillFromJson(fruitList);
    }
}
