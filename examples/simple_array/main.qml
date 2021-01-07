import QtQuick 2.12
import QtQuick.Window 2.12
import BppTable 0.1

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
                color: bGrid.getCellBk(row, highlight)

                CellText {
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: bGrid.getAlign(dataType)
                }

                CellClicker {
                    grid: bGrid
                }
            }
        }

        cellDelegate: cellItem

        fromArray: [
            { title: "ID", dataType: BTColumn.Int },
            { title: "Name", minWidth: 100 },
            { title: "Cost", dataType: BTColumn.Dbl }
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
