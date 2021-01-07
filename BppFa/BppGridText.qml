import QtQuick 2.0

Text {
    verticalAlignment: Text.AlignVCenter
    anchors.fill: parent
    anchors.leftMargin: 5
    color: BppMetrics.textColor
    anchors.rightMargin: 5
    font.pointSize: BppMetrics.cellDataFontSizePt
    elide: Qt.ElideRight
}
