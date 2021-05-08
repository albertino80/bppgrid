import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Material.theme: Material.Dark

    TabBar {
        id: bar
        width: parent.width

        Repeater {
            model: ["First", "Second", "Third"]

            TabButton {
                text: modelData
                width: Math.max(100, bar.width / 3)
            }
        }
    }

    StackLayout {
        anchors.top: bar.bottom
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right

        currentIndex: bar.currentIndex
        PanelResults {
            id: firstTab
            tabId: 0
        }
        PanelResults {
            id: secondTab
            tabId: 1
        }
        PanelResults {
            id: thirdTab
            tabId: 2
        }
    }
}
