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

        dataHeight: 30

        Component {
            id: cellItem

            Rectangle {
                //cell rectangle
                implicitHeight: bGrid.dataHeight
                color: row % 2 == 0 ? bGrid.dataBkOdd : bGrid.dataBkEven

                Text {
                    //cell text
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: bGrid.getAlign(dataType)
                    verticalAlignment: Text.AlignVCenter
                    anchors.fill: parent
                    leftPadding: 5
                    rightPadding: 5
                    font.pointSize: 11
                    elide: Qt.ElideRight
                }

                Rectangle{
                    //cell separator
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    color: bGrid.dataLines
                    width: 1
                }

                MouseArea {
                    //cell interaction
                    anchors.fill: parent
                    onClicked: {
                        bGrid.setSelectedRow(row);
                    }
                }
            }
        }

        cellDelegate: cellItem

        columns: [
            { role: "pkid", title: "ID", dataType: BppTableModel.Int },
            { role: "name", minWidth: 140, title: "Name" },
            { role: "cost", title: "Cost", dataType: BppTableModel.Dbl }
         ]
    }

    Component.onCompleted: {
        //fill list with data
        var fruitList = [
            {pkid: 1, name: "Apple", cost: 2.45},
            {pkid: 2, name: "Orange", cost: 3.45},
            {pkid: 3, name: "Banana", cost: 1.459},
            {pkid: 4, name: "Strawberry", cost: 1.1467}
        ];
        bGrid.fillFromJson(fruitList);
    }
}
