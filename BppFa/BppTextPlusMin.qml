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
    property double incrDecrAmount: 1

    property bool incrDecrHasMaximun: false
    property bool incrDecrHasMinimum: false
    property int incrDecrMaximun: 9999
    property int incrDecrMinimum: 0

    implicitWidth: textInput.implicitWidth + btnPlus.implicitWidth + 5
    implicitHeight: Math.max(textInput.implicitHeight, btnPlus.implicitHeight)

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

    function toInt(){
        if(textInput.text.length > 0)
            return parseInt(textInput.text);
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

    RowLayout {
        anchors.fill: parent
        spacing: 0

        TextField
        {
            id: textInput
            Layout.fillWidth: true
            selectByMouse: true
            inputMethodHints: Qt.ImhFormattedNumbersOnly
            color: enabled ? BppMetrics.textColor : BppMetrics.textColorDisabled
        }

        BppToolButtonFa {
            id: btnPlus
            text: Fa.fa_plus
            activeFocusOnTab: false
            visible: textInput.enabled
            ToolTip.text: qsTr("Increment")
            onPressed: {
                var theVal = textInput.text.trim().replace(",", ".");
                if(isNaN(parseFloat(theVal)))
                    textInput.text = incrDecrMinimum;
                else {
                    textInput.text = parseFloat(theVal) + incrDecrAmount;
                    if(incrDecrHasMaximun && parseFloat(textInput.text) > incrDecrMaximun)
                        textInput.text = incrDecrMaximun;
                }
            }
        }

        BppToolButtonFa {
            text: Fa.fa_minus
            activeFocusOnTab: false
            visible: textInput.enabled
            ToolTip.text: qsTr("Decrement")
            onPressed: {
                var theVal = textInput.text.trim().replace(",", ".");
                if(isNaN(parseFloat(theVal)))
                    textInput.text = incrDecrMinimum;
                else {
                    textInput.text = parseFloat(theVal) - incrDecrAmount;
                    if(incrDecrHasMinimum && parseFloat(textInput.text) < incrDecrMinimum)
                        textInput.text = incrDecrMinimum;
                }
            }
        }
    }
}
