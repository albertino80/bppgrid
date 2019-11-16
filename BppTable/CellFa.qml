import QtQuick 2.0

Text {
    id: theTxt

    property alias horizontalAlignment: theTxt.horizontalAlignment
    property alias fa_family: theTxt.font.family
    property alias fa_ico: theTxt.text
    property alias pointSize: theTxt.font.pointSize

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter;
    anchors.fill: parent
    anchors.leftMargin: 5
    anchors.rightMargin: 5

    font.pointSize: 14
    font.family: Fa.solid
}
