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

    property bool showCopyPasteCommands: true
    property bool showOnlyAvailableCpliboardCommands: false

    implicitWidth: textInput.implicitWidth + btnClip.implicitWidth + 5
    implicitHeight: Math.max(textInput.implicitHeight, btnClip.implicitHeight)

    signal focusLost()

    function valueOrNull(){
        if(textInput.text.trim().length > 0)
            return textInput.text.trim();
        return null;
    }

    function valueOrNullUc(){
        if(textInput.text.trim().length > 0)
            return textInput.text.trim().toLocaleUpperCase();
        return null;
    }

    function valueOrNullLc(){
        if(textInput.text.trim().length > 0)
            return textInput.text.trim().toLocaleLowerCase();
        return null;
    }

    function toInt(){
        if(textInput.text.length > 0)
            return parseInt(textInput.text);
        return 0;
    }

    function toDouble(){
        if(textInput.text.length > 0){
            var theVal = textInput.text.trim().replace(",", ".")
            return parseFloat(theVal)
        }
        return 0;
    }

    function toCm(){
        if(textInput.text.length > 0) {
            var theVal = textInput.text.trim().replace(",", ".");
            return Math.floor(parseFloat(theVal) * 100.0);
        }
        return 0;
    }

    function cmToText(cmValue) {
        if(cmValue < 0.001) {
            textInput.text = "";
        }
        else {
            textInput.text = (cmValue / 100.0).toFixed(2);
            if( textInput.text.endsWith(".00") )
                textInput.text = textInput.text.substr(0, textInput.text.length - 3);
        }
    }

    function setText(aTxtOrNull){
        if(aTxtOrNull)
            textInput.text = aTxtOrNull
        else
            textInput.text = ""
    }

    Component {
        id: clipMenu
        Menu {
            //id: contextMenu
            MenuItem {
                text: qsTr("Cut")
                enabled: textInput.enabled
                height: showOnlyAvailableCpliboardCommands && !enabled ? 0 : implicitHeight
                onTriggered: {
                    textInput.selectAll()
                    textInput.cut()
                    textInput.deselect()
                }
            }
            MenuItem {
                text: qsTr("Copy")
                enabled: textInput.text.length > 0
                height: showOnlyAvailableCpliboardCommands && !enabled ? 0 : implicitHeight
                onTriggered: {
                    textInput.selectAll()
                    textInput.copy()
                    textInput.deselect()
                }
            }
            MenuItem {
                text: qsTr("Paste")
                enabled: textInput.enabled
                height: showOnlyAvailableCpliboardCommands && !enabled ? 0 : implicitHeight
                onTriggered: {
                    textInput.paste()
                }
            }
            MenuItem {
                text: qsTr("Clear and paste")
                enabled: textInput.enabled
                height: showOnlyAvailableCpliboardCommands && !enabled ? 0 : implicitHeight
                onTriggered: {
                    textInput.clear()
                    textInput.paste()
                }
            }
            MenuItem {
                text: qsTr("Clear")
                enabled: textInput.enabled
                height: showOnlyAvailableCpliboardCommands && !enabled ? 0 : implicitHeight
                onTriggered: {
                    textInput.clear()
                }
            }
        }
    }

    RowLayout {
        anchors.fill: parent
        spacing: 0

        TextField
        {
            id: textInput
            Layout.fillWidth: true
            selectByMouse: true
            color: enabled ? BppMetrics.textColor : BppMetrics.textColorDisabled
            onActiveFocusChanged: {
                if(!activeFocus) focusLost()
            }
        }

        Loader {
            id: menuLoader
        }

        BppToolButtonFa {
            id: btnClip
            activeFocusOnTab: false
            text: Fa.fa_clipboard
            font.family: Fa.regular
            visible: showCopyPasteCommands
            enabled: textInput.enabled || textInput.text.length > 0
            ToolTip.text: qsTr("Copy/Paste options")
            onPressed: {
                menuLoader.sourceComponent = clipMenu
                menuLoader.item.popup(btnClip);
                //contextMenu.popup(btnClip);
            }
        }
    }
}
