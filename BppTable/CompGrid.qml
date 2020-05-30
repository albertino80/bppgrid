import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.12
import QtQuick.Controls 2.12
import BppTableModel 0.1

Item {
    property int dataHeight: 30
    property color dataHighlight: "darkturquoise"
    property color dataBkOdd: "#FFFFFF"
    property color dataBkEven: "#F6F8FA"
    property color dataLines: "#E5E5E5"

    property int headingsHeight: 30
    property color headingsBk: "#E7E7E7"
    property color headingsLines: "#C5C5C5"
    //property color headingsTextColor: "#313131"
    property color headingsTextColor: "black"
    property color headingsSortColor: "#000099"
    property color headingsNoSortColor: "#888888"

    property string dateFormat: "dd/MM/yyyy"
    property string dateTimeFormat: "dd/MM/yyyy HH:mm:ss"

    property var cellDelegate: null
    property int selectedRow: -1

    property var fromListModel: null
    property var fromArray: null

    property ListModel columns: ListModel{}

    function rows(){
        return gridDataModel.rowCount();
    }

    function cellValue(row, col){
        return gridDataModel.data( gridDataModel.index(row, col), "display" );
    }

    function setSelectedRow(row) {
        gridDataModel.setHighlightRow(row);
    }

    function getCellBackground(row) {
        return row % 2 == 0 ? dataBkOdd : dataBkEven;
    }

    function clearData(){
        gridDataModel.beginReset();
        gridDataModel.endReset();
        tview.contentY = 0;
    }

    function setFrontRecords(theArr){
        gridDataModel.setFrontRecords(theArr);
    }

    function clearFrontRecords(theArr){
        gridDataModel.setFrontRecords([]);
    }

    function fillFromArray(theArr){
        gridDataModel.beginReset();
        for(var i = 0; i < theArr.length; i++) {
            gridDataModel.addRecord(theArr[i]);
        }
        gridDataModel.endReset();
        ensureVisible();
    }

    function fillFromQuery(theDb, theSql, theParameters){
        gridDataModel.setDbRef( theDb );
        gridDataModel.addFromQuery(theSql, theParameters);
        ensureVisible();
    }

    function fillFromJson(theJson){
        gridDataModel.addFromList(theJson);
        ensureVisible();
    }

    function fillFromListModel(theModel){
        var records = [];
        for (var i=0; i < theModel.count; i++) {
            records.push( JSON.parse(JSON.stringify(theModel.get(i))) )
        }
        gridDataModel.addFromList(records);
        ensureVisible();
    }

    function formatDisplay(display, dataType, decimals){
        if( dataType === BTColumn.Str )
            return display;
        if( dataType === BTColumn.Int )
            return display;
        if( dataType === BTColumn.Dbl )
            return display.toFixed(decimals);
        if( dataType === BTColumn.Date )
            return Qt.formatDate(display, dateFormat);
        if( dataType === BTColumn.DateTime )
            return Qt.formatDateTime(display, dateTimeFormat);

        return display;
    }

    function getAlign(dataType){
        if( dataType === BTColumn.Str )
            return Text.AlignLeft;
        if( dataType === BTColumn.Int )
            return Text.AlignRight;
        if( dataType === BTColumn.Dbl )
            return Text.AlignRight;
        if( dataType === BTColumn.Date )
            return Text.AlignHCenter;
        if( dataType === BTColumn.DateTime )
            return Text.AlignHCenter;

        return Text.AlignLeft;
    }

    Rectangle {
        border.color: headingsLines
        //border.color: "black"
        color: headingsLines
        //color: "transparent"
        anchors.fill: parent

        ColumnLayout {
            id: mainColumn
            anchors.fill: parent
            /*
            anchors.leftMargin: 1
            anchors.rightMargin: 1
            anchors.bottomMargin: 1
            */
            anchors.margins: 1

            spacing: 0
            clip: true

                Flickable {
                    id: headingsFlick
                    Layout.fillWidth: true
                    height: headingsHeight
                    contentWidth: tview.contentWidth
                    boundsBehavior: Flickable.StopAtBounds
                    clip: true

                    RowLayout {
                        id: headings
                        Layout.fillWidth: true
                        spacing: 1

                        Repeater {
                            id: colRepeater
                            model: columns //ListModel {}
                            Rectangle{
                                Layout.minimumWidth: model.width;
                                Layout.minimumHeight: headingsFlick.height
                                color: headingsBk
                                visible: model.visible

                                property int sortIndicator: sort;

                                Text{
                                    color: headingsTextColor
                                    anchors{
                                        left: parent.left
                                        top: parent.top
                                        bottom: parent.bottom
                                        right: sortImage.left
                                    }

                                    leftPadding: 5
                                    //font.bold: true
                                    verticalAlignment: Text.AlignVCenter
                                    font.pointSize: 11
                                    text: title
                                    elide: Qt.ElideRight
                                }

                                Image {
                                    id: sortImage
                                    anchors.right: parent.right
                                    anchors.verticalCenter: parent.verticalCenter
                                    anchors.rightMargin: 5
                                    visible: sortIndicator !== 4

                                    source: sortIndicator === 0 ? "qrc:/BppTable/assets/sort-up-and-down.svg" :
                                            (
                                                sortIndicator === 1 ? "qrc:/BppTable/assets/sort-up.svg" :
                                                                      "qrc:/BppTable/assets/sort-down.svg"
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

                                /*
                                Rectangle{
                                    anchors.right: parent.right
                                    anchors.top: parent.top
                                    anchors.bottom: parent.bottom
                                    color: headingsLines
                                    width: 1
                                }
                                */

                                MouseArea {
                                    anchors.fill: parent
                                    visible: sortIndicator !== 4
                                    onClicked: {
                                        var newSort = columns.get(index).sort;
                                        newSort++;
                                        if(newSort > 2) newSort = 0;

                                        gridDataModel.dataNeedSort();
                                        columns.get(index).sort = newSort;
                                        gridDataModel.updateLayout();
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
                    columnSpacing: 1
                    rowSpacing: 0
                    clip: true
                    boundsBehavior: Flickable.StopAtBounds
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    columnWidthProvider: gridDataModel.getColWidth;

                    model: gridDataModel
                    reuseItems: true

                    delegate: cellDelegate

                    ScrollBar.horizontal: ScrollBar { orientation: Qt.Horizontal }
                    ScrollBar.vertical: ScrollBar { }

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
                }
        }

        onWidthChanged: {
            fromColumnListModelToTable(false); //resize columns
        }
    }

    property var gridDataModel: BTModel {
    }

    Connections{
        target: columns
        onDataChanged: {
            fromColumnListModelToTable(false);
        }
    }

    onFromListModelChanged: {
        columnsFromListModel(fromListModel);
    }

    onFromArrayChanged: {
        columnsFromArray(fromArray);
    }

    function ensureVisible(){
        if(tview.contentY >= gridDataModel.rowCount() * dataHeight)
            tview.contentY = 0;
    }

    function appendCol(aColumn, i){
        var newColumn = {
            "width": 100,
            "minWidth": 0,
            "title": "",
            "sort": 0,
            "dataType": BTColumn.Str,
            "view": 0,
            "command": 0,
            "role": "col" + i,
            "visible": true,
            "dataRef1": ""
        };

        if(aColumn.width !== undefined)   newColumn.width = aColumn.width;
        if(aColumn.minWidth !== undefined)   newColumn.minWidth = aColumn.minWidth;
        if(aColumn.title !== undefined)   newColumn.title = aColumn.title;
        if(aColumn.sort !== undefined)   newColumn.sort = aColumn.sort;
        if(aColumn.dataType !== undefined)   newColumn.dataType = aColumn.dataType;
        if(aColumn.view !== undefined)   newColumn.view = aColumn.view;
        if(aColumn.command !== undefined)   newColumn.command = aColumn.command;
        if(aColumn.role !== undefined && newColumn.role.length > 0)   newColumn.role = aColumn.role;
        if(aColumn.visible !== undefined)   newColumn.visible = aColumn.visible;
        if(aColumn.dataRef1 !== undefined)   newColumn.dataRef1 = aColumn.dataRef1;

        if(newColumn.width === 0) newColumn.width = 100;
        if(!newColumn.visible && !gridDataModel.canHideColumns()){
            console.log('BppGrid: detected column with visible=false, require Qt 5.13')
            newColumn.visible = true;
        }

        columns.append(newColumn);
    }

    function columnsFromListModel(aListModel){
        if(aListModel === null) return;

        columns.clear();
        for(var i=0; i<aListModel.count; i++) {
            appendCol(aListModel.get(i), i);
        }
    }

    function columnsFromArray(jsArray){
        if(jsArray === null) return;

        columns.clear();
        for(var i=0; i<jsArray.length; i++) {
            appendCol(jsArray[i], i);
        }
    }

    property bool doFireColumnsChange: true
    function fromColumnListModelToTable(resetDefaults){
        if(!columns) return;
        if(!doFireColumnsChange) return;

        var i;

        if(!gridDataModel.canHideColumns()) {
            doFireColumnsChange = false
            for(i=0; i<columns.count; i++){
                if(!columns.get(i).visible) {
                    console.log('BppGrid: detected column with visible=false, require Qt 5.13')
                    columns.get(i).visible = true;
                }
            }
            doFireColumnsChange = true;
        }

        if(columns.count > 0 && mainColumn.width > 0){
            var minWidth = 0;
            var toResize = [];
            var curCol = null;

            for(i=0; i<columns.count; i++){
                curCol = columns.get(i);
                if(curCol.minWidth && curCol.visible) {
                    toResize.push(i);
                    minWidth += columns.get(i).minWidth;
                }
            }

            if(toResize.length > 0) {
                doFireColumnsChange = false;

                var colSpace = 0;
                var usedWidth = 0;
                for(i=0; i<columns.count; i++){
                    curCol = columns.get(i);
                    if(curCol.visible) {
                        if(i < columns.count -1) colSpace++;
                        if(!curCol.minWidth)
                            usedWidth += columns.get(i).width;
                    }
                }

                var newWidth = mainColumn.width - colSpace - usedWidth;
                if( newWidth < minWidth ) { //mantain minWidth
                    for(i=0; i<toResize.length; i++) {
                        curCol = columns.get( toResize[i] );
                        if(curCol.width !== curCol.minWidth)
                            curCol.width = curCol.minWidth;
                    }
                }
                else {
                    var allWidth = 0;
                    var factor = newWidth / minWidth;
                    for(i=0; i < toResize.length; i++) {
                        curCol = columns.get( toResize[i] );

                        var calcWidth = Math.floor(curCol.minWidth * factor);
                        if(i === toResize.length - 1) {
                            //due to previous roundings, last resize column get all available space
                            calcWidth = mainColumn.width - colSpace - (allWidth + usedWidth)
                        }
                        else
                            allWidth += calcWidth;

                        if(curCol.width !== calcWidth)
                            curCol.width = calcWidth;
                    }
                }

                doFireColumnsChange = true;
            }
        }

        gridDataModel.clearColumnsDef();
        for(i=0; i<columns.count; i++) {
            var newCol = gridDataModel.addColumnDef();
            gridDataModel.setColumnDef(newCol, resetDefaults, JSON.parse(JSON.stringify(columns.get(i))) )
        }
        gridDataModel.endUpdateColumns( );
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
