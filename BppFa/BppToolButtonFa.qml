import QtQuick 2.0
import QtQuick.Controls 2.13

ToolButton {
    id: container

    property alias iconFa: container.text

    font.family: Fa.solid
    font.pointSize: BppMetrics.fontSizeCommandIcons
    text: Fa.fa_plus
    ToolTip.visible: hovered && ToolTip.text.length > 0
}
