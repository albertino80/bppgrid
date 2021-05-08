import QtQuick 2.0
import QtQuick.Controls 2.14
import QtQuick.Controls.Material 2.12
import QtQuick.Layouts 1.14
import BppTable 0.1

Pane {
    property int tabId: 0

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 5

        CompGrid {
            id: bGrid
            Layout.fillWidth: true
            Layout.fillHeight: true

            dataHeight: 40

            //customize grid color for dark theme
            dataHighlight: Material.accent
            dataBkOdd: "#1E1E1E"
            dataBkEven: "#151515"
            dataBkSelOdd: Qt.darker(Material.accent)
            dataBkSelEven: Qt.darker(Material.accent)
            headingsBk: "#303030"
            headingsBkAlt: "#151515"
            headingsLines: "#404040"
            headingsTextColor: "#FEFEFE"
            headingsSortColor: "#FEFEFE"

            Component {
                id: cellItem

                Rectangle {
                    implicitHeight: bGrid.dataHeight
                    color: bGrid.getCellBk(row, highlight)

                    CellText {
                        visible: view === 0
                        text: bGrid.formatDisplay(display, dataType, 2)
                        horizontalAlignment: bGrid.getAlign(dataType)
                        color: "#FFFFFF"
                    }

                    Rectangle {
                        visible: view === 1
                        anchors.fill: parent
                        anchors.margins: 5
                        color: view === 1 ? display : ""
                        border.color: Qt.lighter(color)
                    }

                    CellClicker {
                        grid: bGrid
                    }
                }
            }

            cellDelegate: cellItem

            fromArray: [
                { role: "pkid",  title: "ID",    width: 80,     view: 0, dataType: BTColumn.Int },
                { role: "name",  title: "Name",  minWidth: 140, view: 0 },
                { role: "color", title: "Color", width: 80,     view: 1 },
             ]
        }

        Text{
            id: status
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            Layout.preferredHeight: 18

            font.pointSize: 14
            text: bGrid.selectedRow < 0 ? "No selected Item" : "Selected record %1 (tab %2)".arg(bGrid.selectedRow + 1).arg(tabId + 1)
            color: "#FFFFFF"
        }
    }

    Component.onCompleted: {
        bGrid.fillFromJson( cpp_be.getData(tabId) );
    }
}
