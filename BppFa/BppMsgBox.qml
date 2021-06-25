import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Dialog {
    id: messageDialog

    visible: true

    title: "Dialog"

    property var funzYes: null
    property var funzNo: null

    standardButtons: Dialog.NoButton
    modal: false
    //padding: 5

    onAccepted: {
        if(funzYes && typeof funzYes === "function") {
            funzYes();
        }
        else
            exitWithYes();
    }
    onRejected: {
        if(funzNo && typeof funzNo === "function") {
            funzNo();
        }
        else
            exitWithNo();
    }

    signal exitWithYes();
    signal exitWithNo();

    function doMessageM(pTitle, pText) {
        doMessageInt(pTitle, pText, true)
    }

    function doMessage(pTitle, pText) {
        doMessageInt(pTitle, pText, false)
    }

    function doMessageInt(pTitle, pText, pModality) {
        modal = pModality
        closePolicy = Popup.CloseOnEscape | Popup.CloseOnPressOutside
        standardButtons = Dialog.Ok

        funzYes = null
        funzNo = null

        title = pTitle
        txtContent.text = pText

        gotoPos("C", "C");
        open();
    }

    function doYesNoCT(pTitle, pText, functOnYes, functOnNo) {
        modal = true
        closePolicy = Popup.CloseOnEscape

        funzYes = functOnYes
        funzNo = functOnNo

        standardButtons = Dialog.Yes | Dialog.No

        title = pTitle
        txtContent.text = pText

        gotoPos("C", "T");
        open();
    }

    function doYesNo(pTitle, pText, functOnYes, functOnNo) {
        modal = true
        closePolicy = Popup.CloseOnEscape

        funzYes = functOnYes
        funzNo = functOnNo

        standardButtons = Dialog.Yes | Dialog.No

        title = pTitle
        txtContent.text = pText

        gotoPos("C", "C");
        open();
    }

    function gotoPos(posH, posV) {
        if(posH === "C") {
            messageDialog.x = (messageDialog.parent.width - messageDialog.width) / 2;
        }
        else if(posH === "L") {
            messageDialog.x = 0;
        }
        else if(posH === "R") {
            messageDialog.x = messageDialog.parent.width - messageDialog.width;
        }

        if(posV === "C") {
            messageDialog.y = (messageDialog.parent.height - messageDialog.height) / 2
        }
        else if(posV === "T") {
            messageDialog.y = 0
        }
        else if(posV === "B") {
            messageDialog.y = messageDialog.parent.height - messageDialog.height
        }
    }

    Menu {
        id: contextMenu
        MenuItem { text: qsTr("Center"); onPressed: { gotoPos("C", "C"); } }
        MenuItem { text: qsTr("Move top left"); onPressed: { gotoPos("L", "T"); } }
        MenuItem { text: qsTr("Move top right"); onPressed: { gotoPos("R", "T"); } }
        MenuItem { text: qsTr("Move bottom left"); onPressed: { gotoPos("L", "B"); } }
        MenuItem { text: qsTr("Move bottom right"); onPressed: { gotoPos("R", "B"); } }
    }

    header: Rectangle {
        color: BppMetrics.windowBackgroundAlt
        height: 40
        implicitHeight: 40
        border.width: 1
        border.color: BppMetrics.windowBackground

        RowLayout {
            anchors.fill: parent

            Label {
                text: title
                Layout.fillWidth: true
                Layout.fillHeight: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                //color: BppMetrics.accentColor
                font.bold: true
            }
            BppToolButtonFa {
                Layout.fillHeight: true
                text: Fa.fa_arrows_alt
                ToolTip.text: qsTr("Sposta")
                onClicked: {
                    contextMenu.popup()
                }
            }
        }
    }

    contentItem: Label {
        id: txtContent
        //anchors.centerIn: parent
        //anchors.fill: parent
        //anchors.margins: 5
        //verticalAlignment: Text.AlignVCenter
        //horizontalAlignment: Text.AlignHCenter

        wrapMode: Text.Wrap
        font.pointSize: BppMetrics.fontSizePt
        color: BppMetrics.textColor
    }
}
