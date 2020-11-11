import QtQuick 2.12
import QtQuick.Window 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import BppTableModel 0.1
import BppTable 0.1

ApplicationWindow {
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

    RowLayout {
        id: buttonBar
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 10

        CheckBox {
            id: chkMultiselection
            text: "Multiselection"
        }
        CheckBox {
            id: chkMultiselectionMobileMode
            enabled: chkMultiselection.checked
            text: "Mobile mode"
        }
        Button{
            text: qsTr("More data")
            onPressed: {
                bGrid.fillFromJson(fruitList, false);
            }
        }

        Item{ Layout.fillWidth: true }
        Text {
            text: qsTr("Keyboard modifiers")
        }
        Text {
            id: txtCtrl
            text: qsTr("CTRL")
        }
        Text {
            id: txtShift
            text: qsTr("SHIF")
        }
    }
    RowLayout {
        id: selResults
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: buttonBar.bottom
        anchors.margins: 10
        //height: 40

        Text {
            text: qsTr("Selected items:")
        }
        Text {
            id: numSelected
            text: qsTr("0")
        }
        Text {
            Layout.leftMargin: 20
            text: qsTr("Rows:")
        }
        Text {
            id: rowsSelected
            text: ""
        }
        Item{ Layout.fillWidth: true }
    }

    CompGrid {
        id: bGrid
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: selResults.bottom
        anchors.bottom: parent.bottom
        anchors.margins: 10

        dataHeight: 50
        withMultiselection: chkMultiselection.checked
        withMultiselectionMobileMode :chkMultiselectionMobileMode.checked

        Component {
            id: cellItem

            Rectangle {
                implicitHeight: bGrid.dataHeight
                color: bGrid.getCellBk(row, highlight)

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

        onSelectionChanged: {
            numSelected.text = bGrid.countSelection();
            var selRows = bGrid.getSelectedRows();
            var str = ""
            for(var i=0; i<selRows.length; i++) str += selRows[i] + ",";
            rowsSelected.text = str;
        }

        //the following block is only for display key modifier text, not necessary in real usage
        focus: true
        onFocusChanged: forceActiveFocus()
        Keys.onPressed: {
            if(event.modifiers & Qt.ControlModifier)
                txtCtrl.font.bold = true
            if(event.modifiers & Qt.ShiftModifier)
                txtShift.font.bold = true
        }
        Keys.onReleased: {
            txtCtrl.font.bold = false
            txtShift.font.bold = false
        }
    }

    Component.onCompleted: {
        bGrid.fillFromJson(fruitList);
    }
}
