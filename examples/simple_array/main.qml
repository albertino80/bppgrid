import QtQuick 2.13
import QtQuick.Window 2.13
import BppTableModel 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    CompGrid {
        id: bGrid
        anchors.fill: parent
        anchors.margins: 10

        dataHeight: 30

        Component {
            id: cellItem

            Rectangle {
                implicitHeight: bGrid.dataHeight
                color: bGrid.getCellBackground(row)

                CellText {
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: bGrid.getAlign(dataType)
                }

                CellSeparator{
                    color: bGrid.dataLines
                }

                CellClicker {
                    grid: bGrid
                }
            }
        }

        cellDelegate: cellItem

        columns: [
            { title: "ID", dataType: BppTableModel.Int },
            { title: "Name" },
            { title: "Cost", dataType: BppTableModel.Dbl }
         ]
    }

    Component.onCompleted: {
        bGrid.fillFromArray([
            [1, "Apple", 2.45],
            [2, "Orange", 3.45],
            [3, "Banana", 1.459],
            [4, "Strawberry", 1.1467]
        ]);
    }
}
