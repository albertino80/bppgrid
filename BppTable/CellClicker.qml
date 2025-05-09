import QtQuick 2.0
//import BppTableModel 0.1
import BppTable 0.1

MouseArea {
    property CompGrid grid: null
    property bool linkEnabled: false
    property bool selEnabled: true

    signal doCommand();

    cursorShape: linkEnabled ? Qt.PointingHandCursor : Qt.ArrowCursor

    anchors.fill: parent
    onClicked: {
        if(grid){
            if(linkEnabled) {
                if(grid.selectedRow !== row)
                    grid.setSelectedRow(row, mouse.modifiers);
                doCommand()
            }
            else {
                if(selEnabled)
                    grid.setSelectedRow(row, mouse.modifiers);
            }
        }
    }
}
