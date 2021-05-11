import QtQuick 2.12

Item {
    id: container

    property alias label: labelText.text
    //property color tint: "transparent"
    property color tint: BppMetrics.accentColor
    property color disabledTint: BppMetrics.textColorDisabled
    property alias imagePath: mainImage.source
    property bool isMouseOverMe: false
    signal clicked

    width: 180 + 10 ; height: 100 + 10

    BorderImage {
        anchors { fill: container; leftMargin: -6; topMargin: -6; rightMargin: -8; bottomMargin: -8 }
        source: 'assets/box-shadow.png'
        border.left: 10; border.top: 10; border.right: 10; border.bottom: 10
    }

    Image { id: mainImage; source: "assets/BtnMap.png"; anchors.fill: parent; antialiasing: true }

    Rectangle {
        anchors.fill: container;
        color: container.enabled ? container.tint : container.disabledTint;
        visible: isMouseOverMe || !container.enabled
        opacity: 0.25
    }

    Text {
        id: labelText;
        text: "Text";
        font.pixelSize: 15;
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.margins: 8
    }

    MouseArea {
        anchors { fill: parent; leftMargin: -20; topMargin: -20; rightMargin: -20; bottomMargin: -20 }
        hoverEnabled: true
        onClicked: container.clicked()
        onEntered: {
            isMouseOverMe = true;
        }
        onExited: {
            isMouseOverMe = false;
        }
    }
}
