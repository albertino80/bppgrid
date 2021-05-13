import QtQuick 2.0

Rectangle {
    id: container
    property int fontSizePt: 11
    property color textColor: "black"
    property color textColorDisabled: "gray"
    property alias buttonText: txt.text
    property alias buttonFontFamily: txt.font.family

    signal pressed();

    Text {
        id: txt
        anchors.fill: parent
        font.pointSize: fontSizePt
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: container.enabled ? textColor : textColorDisabled
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: containsMouse ? Qt.PointingHandCursor : Qt.ArrowCursor
        onClicked: container.pressed();
    }
}
