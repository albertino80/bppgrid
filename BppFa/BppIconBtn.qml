import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Button{
    id: container
    property alias fontFamily: theIcon.font.family
    property string iconFa: ""

    contentItem: Label {
        id: theIcon
        anchors.centerIn: parent
        font.family: Fa.solid
        text: container.iconFa
        font.pointSize: BppMetrics.fontSizeCommandIcons
        color: enabled ? BppMetrics.accentColor : BppMetrics.textColorDisabled
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
