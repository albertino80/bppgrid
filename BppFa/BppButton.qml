import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Button{
    id: theMainBtn

    property alias fontFamily: theIcon.font.family
    property string iconFa: ""
    property int marginSize: 10

    contentItem: RowLayout {
        spacing: 0

        Text {
            id: lblText
            visible: theMainBtn.text.length > 0

            text: theMainBtn.text
            Layout.fillWidth: true
            font.pointSize: BppMetrics.fontSizePt
            color: theMainBtn.enabled ? BppMetrics.textColor : BppMetrics.textColorDisabled
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: theIcon
            visible: iconFa.length > 0
            Layout.fillWidth: lblText.visible ? false : true

            font.family: Fa.solid
            text: iconFa
            font.pointSize: BppMetrics.fontSizeCommandIcons
            color: theMainBtn.enabled ?
                       (hovered ? BppMetrics.accentColor : BppMetrics.textColor) :
                       BppMetrics.textColorDisabled
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
