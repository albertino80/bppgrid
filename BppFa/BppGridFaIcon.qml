import QtQuick 2.0
import QtQuick.Controls 2.12

Text {
    property string ttip: ""

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter

    anchors.fill: parent

    anchors.leftMargin: 5
    anchors.rightMargin: 5

    color: BppMetrics.textColor
    font.pointSize: BppMetrics.cellDataFontSizePt
    font.family: Fa.solid

    ToolTip.visible: ma.visible && ma.containsMouse
    ToolTip.text: ttip
    MouseArea {
        id: ma
        acceptedButtons: Qt.NoButton
        visible: ttip.length > 0
        anchors.fill: parent
        hoverEnabled: true
    }
}
