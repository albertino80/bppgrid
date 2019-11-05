import QtQuick 2.0
import BppTableModel 0.1

MouseArea {
    id: theClicker

    property var grid: null
    property int viewCommand: -1
    property int commandId: -1
    property int viewId: -2
    property bool linkEnabled: true

    signal doCommand(int commandId);

    cursorShape: (linkEnabled && viewId === viewCommand) ? Qt.PointingHandCursor : Qt.ArrowCursor

    anchors.fill: parent
    onClicked: {
        if(grid){
            grid.setSelectedRow(row);
            if(viewId === viewCommand) {
                doCommand(commandId)
            }
        }
    }
}
