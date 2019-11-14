import QtQuick 2.0
import QtQuick.Controls 2.12

Text {
    id: theTxt

    property alias text: theTxt.text
    property alias horizontalAlignment: theTxt.horizontalAlignment

    verticalAlignment: Text.AlignVCenter
    anchors.fill: parent
    anchors.leftMargin: 5
    anchors.rightMargin: 5
    font.pointSize: 11
    font.underline: true
    color: "blue"
    elide: Qt.ElideRight
}
