import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

import BppFa 1.0

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

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 10

        BppPane{
            Layout.fillWidth: true
            RowLayout {
                anchors.fill: parent

                BppTextDate{
                    id: txtDate;
                    Layout.fillWidth: true
                    enabled: chkEnabled.checked
                    onDateChanged: {
                        txtLastDate.text = qsTr("Selected date: %1").arg(txtDate.toTextFmt("yyyy ddd d MMMM"));
                    }
                }
            }
        }

        BppPane{
            Layout.fillWidth: true
            Layout.fillHeight: true

            GridLayout{
                Layout.fillWidth: true
                Layout.fillHeight: true
                columns: 2

                CheckBox {
                    id: chkEnabled
                    text: qsTr("Enable date selector")
                    checked: true
                    Layout.columnSpan: 2
                }

                Label {
                    id: txtLastDate
                    text: qsTr("Last date selected")
                    Layout.columnSpan: 2
                }

                BppButton{
                    iconFa: Fa.fa_font
                    text: qsTr("MM/dd/yyyy")
                    ToolTip.text: qsTr("Change format")
                    ToolTip.visible: hovered
                    Layout.preferredWidth: 200
                    onPressed: {
                        txtDate.dateFormat = "MM/dd/yyyy";
                    }
                }
                BppButton{
                    iconFa: Fa.fa_font
                    text: qsTr("dd/MM/yyyy")
                    ToolTip.text: qsTr("Change format")
                    ToolTip.visible: hovered
                    Layout.preferredWidth: 200
                    onPressed: {
                        txtDate.dateFormat = "dd/MM/yyyy";
                    }
                }
                BppButton{
                    iconFa: Fa.fa_hammer
                    text: qsTr("13 Dec 2022")
                    ToolTip.text: qsTr("Set date")
                    ToolTip.visible: hovered
                    Layout.preferredWidth: 200
                    onPressed: {
                        txtDate.fromTextFmt("13/12/2022","dd/MM/yyyy")
                    }
                }
                BppButton{
                    iconFa: Fa.fa_glasses
                    text: qsTr("Read date")
                    ToolTip.text: qsTr("Get date")
                    ToolTip.visible: hovered
                    Layout.preferredWidth: 200
                    onPressed: {
                        if(!txtDate.isNull())
                            text = txtDate.toTextFmt("ddd MMMM d yy")
                        else
                            text = qsTr("NULL DATE")
                    }
                }
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

    Component.onCompleted: {
        BppStyleMaterial.setMode(switchDarkTheme.checked);
    }
}
