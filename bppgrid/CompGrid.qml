import QtQuick 2.13
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.13
import BppTableModel 0.1

Item {
    property int dataHeight: 30
    property color dataHighlight: "darkturquoise"
    property color dataBkOdd: "#FFFFFF"
    property color dataBkEven: "#F6F8FA"
    property color dataLines: "#E5E5E5"

    property int headingsHeight: 30
    property color headingsBk: "#D7D7D7"
    property color headingsLines: "#C5C5C5"
    property color headingsTextColor: "#515151"
    property color headingsSortColor: "#000099"
    property color headingsNoSortColor: "#888888"

    property var columns: null;
    property var cellDelegate: null
    property int selectedRow: -1

    function setSelectedRow(row) {
        gridDataModel.setHighlightRow(row);
    }

    function getCellBackground(row) {
        return row % 2 == 0 ? dataBkOdd : dataBkEven;
    }

    function fillFromArray(theArr){
        gridDataModel.beginReset();
        for(var i = 0; i < theArr.length; i++) {
            gridDataModel.addRecord(theArr[i]);
        }
        gridDataModel.endReset();
    }

    function fillFromQuery(theDb, theSql, theParameters){
        gridDataModel.setDbRef( theDb );
        gridDataModel.addFromQuery(theSql, theParameters);
    }

    function fillFromJson(theJson){
        gridDataModel.addFromList(theJson);
    }

    function fillFromListModel(theModel){
        var records = [];
        for (var i=0; i < theModel.count; i++) {
            records.push( JSON.parse(JSON.stringify(theModel.get(i))) )
        }
        gridDataModel.addFromList(records);
    }

    function formatDisplay(display, dataType, decimals){
        if( dataType === BppTableModel.Str )
            return display;
        if( dataType === BppTableModel.Int )
            return display;
        if( dataType === BppTableModel.Dbl )
            return display.toFixed(decimals);
        if( dataType === BppTableModel.Date )
            return Qt.formatDate(display, "dd/MM/yyyy");
        if( dataType === BppTableModel.DateTime )
            return Qt.formatDateTime(display, "dd/MM/yyyy HH:mm:ss");

        return display;
    }

    function getAlign(dataType){
        if( dataType === BppTableModel.Str )
            return Text.AlignLeft;
        if( dataType === BppTableModel.Int )
            return Text.AlignRight;
        if( dataType === BppTableModel.Dbl )
            return Text.AlignRight;
        if( dataType === BppTableModel.Date )
            return Text.AlignHCenter;
        if( dataType === BppTableModel.DateTime )
            return Text.AlignHCenter;

        return Text.AlignLeft;
    }

    ColumnLayout {
        id: mainColumn
        anchors.fill: parent
        anchors.margins: 1
        spacing: 0

        Flickable {
            id: headingsFlick
            Layout.fillWidth: true
            height: headingsHeight
            contentWidth: tview.contentWidth
            clip: true

            RowLayout {
                id: headings
                Layout.fillWidth: true
                spacing: 0

                Repeater {
                    id: colRepeater
                    model: null
                    Rectangle{
                        Layout.minimumWidth: getColWidth(index)
                        Layout.minimumHeight: headingsFlick.height
                        color: headingsBk

                        property int sortIndicator: getColSort(index)
                        property string colTitle: modelData.title

                        Text{
                            color: headingsTextColor
                            anchors{
                                left: parent.left
                                top: parent.top
                                bottom: parent.bottom
                                right: sortImage.left
                            }

                            leftPadding: 5
                            font.bold: true
                            verticalAlignment: Text.AlignVCenter
                            text: colTitle
                            elide: Qt.ElideRight
                        }

                        Image {
                            id: sortImage
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.rightMargin: 5
                            visible: sortIndicator !== 4

                            source: sortIndicator === 0 ? "qrc:/assets/sort-up-and-down.svg" :
                                    (
                                        sortIndicator === 1 ? "qrc:/assets/sort-up.svg" :
                                                              "qrc:/assets/sort-down.svg"
                                    )
                            width: 10; height: 10
                        }
                        ColorOverlay{
                            visible: sortIndicator !== 4
                            anchors.fill: sortImage
                            source:sortImage
                            color: sortIndicator === 0 ? headingsNoSortColor : headingsSortColor
                            transform:rotation
                            antialiasing: true
                        }

                        Rectangle{
                            anchors.right: parent.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            color: headingsLines
                            width: 1
                        }

                        MouseArea {
                            anchors.fill: parent
                            visible: sortIndicator !== 4
                            onClicked: {
                                tableHead.clickedOnColumn(index);
                            }
                        }
                    }
                }
            }

            onContentXChanged: {
                if(contentX >= 0 && tview.contentX !== contentX)
                    tview.contentX = contentX
            }
        }

        TableView {
            id: tview
            Layout.fillWidth: true
            Layout.fillHeight: true
            columnSpacing: 0
            rowSpacing: 0
            clip: true

            columnWidthProvider: getColWidth

            model: gridDataModel
            reuseItems: true

            delegate: cellDelegate //tableViewDelegate

            onContentXChanged: {
                if(contentX >= 0 && headingsFlick.contentX !== contentX)
                    headingsFlick.contentX = contentX
            }

            Rectangle {
                id: highlightRect
                border.width: 2
                border.color: dataHighlight
                color: "transparent"
                radius: 5
                anchors.left: parent.left
                anchors.right: parent.right
                z:2
                y:0
                height: 100
                visible: false
            }
            Rectangle {
                z:2
                border.width: 1
                border.color: headingsLines
                color: "transparent"
                anchors.fill: parent
            }
        }

        onWidthChanged: {
            resizeColumns(mainColumn.width);
        }
    }

    property var tableHead: BppTableHeading {
        onColumnsChanged: {
            colRepeater.model = getColumns();
            gridDataModel.setSortColumns( getSortColumns() );
            gridDataModel.setTypeColumns( getRoleColumns("dataType") );
            gridDataModel.setActionColumns( getRoleColumns("view") );
            gridDataModel.setCommandColumns( getRoleColumns("command") );
            gridDataModel.setRoleColumns( getRoleColumnsStr("role") );
            gridDataModel.updateLayout();
        }
    }

    property var gridDataModel: BppTableModel {}

    onColumnsChanged: {
        tableHead.setColumns(columns);
    }

    function getColWidth(column) {
        if(!colRepeater.model || column >= colRepeater.model.length)
            return 100;

        return colRepeater.model[column].width;
    }

    function getColSort(column) {
        if(!colRepeater.model || column >= colRepeater.model.length)
            return 0;

        return colRepeater.model[column].sort;
    }

    function resizeColumns(theWidth) {
        if(!columns) return;
        if(columns.length === 0) return;
        if(theWidth <= 0) return;

        var minWidth = 0;
        var toResize = new Set();
        var i;

        for(i=0; i<columns.length; i++){
            if(columns[i].minWidth) {
                toResize.add(i);
                minWidth += columns[i].minWidth;
            }
        }

        if(toResize.size === 0) return;

        var usedWidth = 0;
        for(i=0; i<columns.length; i++){
            if(!toResize.has(i)) {
                if(columns[i].width)
                    usedWidth += columns[i].width;
                else
                    usedWidth += 100;
            }
        }

        var newCols = columns;

        var newWidth = theWidth - usedWidth;
        if( newWidth < minWidth ) {
            //mantain min
            for (let iCol1 of toResize) {
                newCols[iCol1].width = columns[iCol1].minWidth;
            }
        }
        else {
            var factor = newWidth / minWidth;
            for (let iCol2 of toResize) {
                newCols[iCol2].width = columns[iCol2].minWidth * factor;
            }
        }

        columns = newCols;
    }

    Connections {
        target: gridDataModel
        onHighlightRowChanged: {
            selectedRow = gridDataModel.highlightRow
            highlightRect.y = gridDataModel.highlightRow * dataHeight;
            highlightRect.height = dataHeight;
            highlightRect.visible = gridDataModel.highlightRow >= 0
        }
    }
}
