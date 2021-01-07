import QtQuick 2.0
//import BppTableModel 0.1
import BppTable 0.1

MouseArea {
    property var grid: null
    property bool linkEnabled: false

    signal doCommand();

    cursorShape: linkEnabled ? Qt.PointingHandCursor : Qt.ArrowCursor

    anchors.fill: parent
    onClicked: {
        if(grid){
            grid.setSelectedRow(row, mouse.modifiers);
            if(linkEnabled) {
                doCommand()
            }
        }
    }
}
