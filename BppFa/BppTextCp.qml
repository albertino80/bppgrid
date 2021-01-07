import QtQuick 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12

Item {
    property alias placeholderText: textInput.placeholderText
    property alias text: textInput.text
    property alias enabled: textInput.enabled
    property alias horizontalAlignment: textInput.horizontalAlignment
    property alias inputMethodHints: textInput.inputMethodHints
    property alias echoMode: textInput.echoMode
    property bool showIncrDecr: false

    implicitWidth: textInput.implicitWidth + btnClip.implicitWidth + 5
    implicitHeight: Math.max(textInput.implicitHeight, btnClip.implicitHeight)

    function valueOrNull(){
        if(textInput.text.length > 0)
            return textInput.text;
        return null;
    }

    function valueOrNullUc(){
        if(textInput.text.length > 0)
            return textInput.text.toLocaleUpperCase();
        return null;
    }

    function toInt(){
        if(textInput.text.length > 0)
            return parseInt(textInput.text);
        return 0;
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        TextField
        {
            id: textInput
            Layout.fillWidth: true
            selectByMouse: true

            Menu {
                id: contextMenu
                MenuItem {
                    text: qsTr("Cut")
                    enabled: textInput.enabled
                    onTriggered: {
                        textInput.selectAll()
                        textInput.cut()
                        textInput.deselect()
                    }
                }
                MenuItem {
                    text: qsTr("Copy")
                    enabled: textInput.text.length > 0
                    onTriggered: {
                        textInput.selectAll()
                        textInput.copy()
                        textInput.deselect()
                    }
                }
                MenuItem {
                    text: qsTr("Paste")
                    enabled: textInput.enabled
                    onTriggered: {
                        textInput.paste()
                    }
                }
                MenuItem {
                    text: qsTr("Clear and paste")
                    enabled: textInput.enabled
                    onTriggered: {
                        textInput.clear()
                        textInput.paste()
                    }
                }
                MenuItem {
                    text: qsTr("Clear")
                    enabled: textInput.enabled
                    onTriggered: {
                        textInput.clear()
                    }
                }
            }
        }

        BppToolButtonFa {
            id: btnClip
            text: Fa.fa_clipboard
            font.family: Fa.regular
            ToolTip.text: qsTr("Copy/Paste options")
            onPressed: {
                contextMenu.popup(btnClip);
            }
        }

        BppToolButtonFa {
            text: Fa.fa_plus
            visible: showIncrDecr && textInput.enabled
            ToolTip.text: qsTr("Increment")
            onPressed: {
                if(isNaN(parseInt(textInput.text)))
                    textInput.text = "0";
                else
                    textInput.text = parseInt(textInput.text) + 1;
            }
        }

        BppToolButtonFa {
            text: Fa.fa_minus
            visible: showIncrDecr && textInput.enabled
            ToolTip.text: qsTr("Decrement")
            onPressed: {
                if(isNaN(parseInt(textInput.text)))
                    textInput.text = "0";
                else
                    textInput.text = parseInt(textInput.text) - 1;
            }
        }
    }
}
