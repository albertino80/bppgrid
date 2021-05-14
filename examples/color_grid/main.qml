import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

import BppFa 1.0
import BppTable 0.1

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Material.theme: BppStyleMaterial.whatTheme
    Material.accent: BppMetrics.accentColor
    Material.primary: BppMetrics.buttonBackground
    Material.foreground: BppMetrics.textColor
    Material.background: BppMetrics.windowBackground

    property var fruitList: [
        {pkid: 1, name: "Apple", cost: 2.45, color: "#5555ff"},
        {pkid: 2, name: "Orange", cost: 3.45, color: "#5555ff"},
        {pkid: 3, name: "Banana", cost: 1.459, color: "#5555ff"},
        {pkid: 4, name: "Strawberry", cost: 1.1467, color: "#5555ff"}
    ];

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 10

        BppPane{
            Layout.fillWidth: true
            //Layout.preferredHeight: 50
            RowLayout {
                anchors.fill: parent
                Item {Layout.fillWidth: true;}

                Label{
                    text: "Current color:"
                }
                Rectangle{
                    id: rectColor
                    Layout.preferredHeight: btnChange.height - btnChange.verticalPadding
                    Layout.preferredWidth: Layout.preferredHeight
                    color: "#5555ff"
                }
                BppButton{
                    id: btnChange
                    Layout.preferredWidth: 100
                    text: "Select"
                    iconFa: Fa.fa_palette
                    onPressed: {
                        popupPick.pickColor = rectColor.color
                        popupPick.openPicker();
                    }
                }

                Item {Layout.fillWidth: true;}

                BppButton{
                    iconFa: Fa.fa_table
                    ToolTip.text: "Set on selected rows"
                    ToolTip.visible: hovered
                    onPressed: {
                        if(bGrid.selectedRow === -1) {
                            mdlg.doMessage("Error", "No selected row")
                            return;
                        }

                        var selRows = bGrid.getSelectedRows();
                        for(var i=0; i<selRows.length; i++)
                            bGrid.setCellValue(selRows[i], "color", rectColor.color)
                    }
                }

                BppButton{
                    iconFa: Fa.fa_highlighter
                    ToolTip.text: "Set as primary theme color"
                    ToolTip.visible: hovered
                    onPressed: {
                        mdlg.doYesNo("Warning", "Ok to use current color as theme accent color?",
                                     function(){
                                         BppMetrics.accentColor = rectColor.color
                                     },
                                     function(){});
                    }
                }
                BppButton{
                    iconFa: Fa.fa_font
                    ToolTip.text: "Set as text theme color"
                    ToolTip.visible: hovered
                    onPressed: {
                        mdlg.doYesNo("Warning", "Ok to use current color as theme text color?",
                                     function(){
                                         BppMetrics.textColor = rectColor.color
                                     },
                                     function(){});
                    }
                }


                Item {Layout.fillWidth: true;}
            }
        }

        BppPane{
            Layout.fillWidth: true
            Layout.fillHeight: true

            BppGrid {
                id: bGrid
                anchors.fill: parent
                withMultiselection: true

                Component {
                    id: cellItem

                    Rectangle {
                        implicitHeight: bGrid.dataHeight
                        color: bGrid.getCellBk(row, highlight)

                        BppGridText {
                            visible: model.view === 0
                            text: bGrid.formatDisplay(display, dataType, 2)
                            horizontalAlignment: bGrid.getAlign(dataType)
                        }

                        Rectangle{
                            anchors.fill: parent
                            anchors.margins: 3
                            visible: model.view === 1
                            color: model.view === 1 ? display : "#000000"
                        }

                        CellClicker {
                            grid: bGrid
                        }
                    }
                }

                cellDelegate: cellItem

                fromArray: [
                    { view: 0, role: "pkid", title: "ID", dataType: BTColumn.Int },
                    { view: 0, role: "name", title: "Name", minWidth: 100 },
                    { view: 0, role: "cost", title: "Cost", dataType: BTColumn.Dbl },
                    { view: 1, role: "color", title: "Color", dataType: BTColumn.Str },
                 ]
            }
        }

        BppPane{
            Layout.fillWidth: true

            RowLayout {
                anchors.fill: parent

                Item {Layout.fillWidth: true;}
                Label {
                    text: "Light theme"
                }
                Switch{
                    id: switchDarkTheme
                    padding: 0
                    checked: false
                    onCheckedChanged: {
                        BppStyleMaterial.setMode(checked);
                    }
                }
            }
        }
    }

    BppColorPickerDialog {
        id: popupPick
        width: 500
        height: 400
        anchors.centerIn: parent
        onColorPicked: {
            rectColor.color = pickColor;
        }
    }

    BppMsgBox {
        id: mdlg
        visible: false
        width: 400
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
    }

    function myPrepareColorsMaterial() {
        BppStyleMaterial.prepareColors();
        if(BppStyleMaterial.whatTheme === BppStyleMaterial.lightTheme) {
            BppMetrics.accentColor = "red"
        }
        else {
            BppMetrics.accentColor = "yellow"
        }
        BppMetrics.cellHeadingsFontSizePt = 18
        BppMetrics.cellDataFontSizePt = 18
        BppMetrics.cellDataHeight = 50
        BppMetrics.cellHeadingsHeight = 50
    }

    Component.onCompleted: {
        //BppStyleMaterial.setInitFunction(myPrepareColorsMaterial); //uncomment this, for enable Material theme customization

        BppStyleMaterial.setMode(switchDarkTheme.checked);
        bGrid.fillFromJson(fruitList);
    }
}
