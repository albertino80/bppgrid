import QtQuick 2.12
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import BppTableModel 0.1
import BppTable 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var fruitList: [
        {pkid: 1, name: "Apple",  cost: 2.45, ico: Fa.fa_apple_alt, prog: 80, color: "green"},
        {pkid: 2, name: "Carrot", cost: 3.45, ico: Fa.fa_carrot, prog: 20, color: "orange"},
        {pkid: 3, name: "Lemon", cost: 1.459, ico: Fa.fa_lemon, prog: 100, color: "yellow"},
        {pkid: 4, name: "Pepper", cost: 1.1467, ico: Fa.fa_pepper_hot, prog: 50, color: "#bb00ff"}
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

                CellFa {
                    visible: view === Enums.CellView.FaView
                    text: display
                    color: ref1
                }

                CellButton {
                    visible: view === Enums.CellView.CommandButton
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: Text.AlignHCenter
                }

                ProgressBar {
                    visible: view === Enums.CellView.ProgressView
                    anchors.centerIn: parent
                    width: parent.width - 10
                    from: 0
                    to: 100
                    value: dataType === BTColumn.Int ? display : 0
                }

                CellClicker {
                    grid: bGrid
                    linkEnabled: view === Enums.CellView.CommandButton
                    onDoCommand: {
                        console.log('Clicked:', command, display)
                    }
                }
            }
        }

        cellDelegate: cellItem

        fromArray: [
            { role: "pkid", title: "ID", dataType: BTColumn.Int },
            { role: "name", title: "Name", minWidth: 140, view: Enums.CellView.CommandButton, command: Enums.Commands.DoCmd1 },
            { role: "ico", title: "", width: 40, view: Enums.CellView.FaView, sort: 4, dataRef1: "color" },
            { role: "cost", title: "Cost", dataType: BTColumn.Dbl },
            { role: "prog", title: "Progress", minWidth: 100, dataType: BTColumn.Int, view: Enums.CellView.ProgressView },
            { role: "color", visible: false, dataType: BTColumn.String }
         ]
    }

    Component.onCompleted: {
        bGrid.fillFromJson(fruitList);
    }
}
