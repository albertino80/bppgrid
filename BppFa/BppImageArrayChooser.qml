import QtQuick 2.12
import QtQuick.Layouts 1.12

RowLayout {
    id: container
    width: 200
    property alias imageModel: imgRep.model
    property int currentIndex: 0

    Repeater {
        id: imgRep
        Rectangle {
            width: schema_img.width + 8
            height: schema_img.height + 8
            border.width: 4
            border.color: model.index === currentIndex ? BppMetrics.listItemSelEven : BppMetrics.textColorDisabled
            Image {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                id: schema_img
                source: modelData
            }
            MouseArea {
                enabled: container.enabled;
                anchors.fill: parent;
                onPressed: {
                    currentIndex = index
                }
            }
        }
    }
}
