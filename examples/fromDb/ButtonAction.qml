import QtQuick 2.0

Item {
    anchors.fill: parent
    property int commandId: -1

    function getButton(theCommand){
        if(theCommand === Enums.Commands.DoCmd1)
            return awesome.icons.fa_trash;

        if(theCommand === Enums.Commands.DoCmd2)
            return awesome.icons.fa_check;

        return null;
    }

    Rectangle {
        radius: 15
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#11ad11";
            }
            GradientStop {
                position: 1.00;
                color: "#008800";
            }
        }
        color: "#11ad11"
        border.color: "#515151"
        border.width: 2
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: 30
        height: 30
        Text {
            font.family: awesome.family
            font.pointSize: 12
            color: "#FFFFFF"
            text: getButton(commandId);
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
