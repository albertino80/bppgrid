import QtQuick 2.14
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Popup {
    id: popupPick
    width: 500
    height: 400
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    signal colorPicked;

    property color pickColor: "black"

    function openPicker(){
        cpick.initColor(pickColor)
        popupPick.open();
    }

    ColumnLayout {
        anchors.fill: parent
        BppColorPicker{
            id: cpick
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
        RowLayout{
            BppButton{
                Layout.preferredWidth: 120
                text: qsTr("Cancel")
                iconFa: Fa.fa_times
                onPressed:  popupPick.close();
            }

            Item {
                Layout.fillWidth: true
            }

            BppButton{
                Layout.preferredWidth: 120
                text: qsTr("Accept")
                iconFa: Fa.fa_check
                onPressed: {
                    popupPick.close();
                    pickColor = cpick.currentColor
                    colorPicked();
                }
            }
        }
    }
}
