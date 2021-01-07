import QtQuick 2.14
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12

Pane {
    id: control

    property color bkColor: BppMetrics.panelBackground
    property int bkElevation: BppMetrics.elevation

    background: Rectangle {
        color: bkColor
        radius: bkElevation > 0 ? 2 : 0

        layer.enabled: control.enabled && bkElevation > 0
        layer.effect: ElevationEffect {
            elevation: bkElevation
        }
    }
}
