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
                            font.bold: true
                            verticalAlignment: Text.AlignVCenter
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
            Layout.fillWidth: true
            Layout.fillHeight: true
            columnSpacing: 0
            rowSpacing: 0
            clip: true

            columnWidthProvider: gridDataModel.getColWidth;

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
            //resizeColumns(mainColumn.width);
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

    function columnsFromListModel(aListModel){
        columns.clear();
        for(var i=0; i<aListModel.count; i++) {
            var newColumn = {
                "width": 100,
                "minWidth": 0,
                "title": "",
                "sort": 0,
                "dataType": BTColumn.Str,
                "view": 0,
                "command": 0,
                "role": "col" + i,
                "visible": true
            };

            if(aListModel.get(i).width !== undefined)   newColumn.width = aListModel.get(i).width;
            if(aListModel.get(i).minWidth !== undefined)   newColumn.minWidth = aListModel.get(i).minWidth;
            if(aListModel.get(i).title !== undefined)   newColumn.title = aListModel.get(i).title;
            if(aListModel.get(i).sort !== undefined)   newColumn.sort = aListModel.get(i).sort;
            if(aListModel.get(i).dataType !== undefined)   newColumn.dataType = aListModel.get(i).dataType;
            if(aListModel.get(i).view !== undefined)   newColumn.view = aListModel.get(i).view;
            if(aListModel.get(i).command !== undefined)   newColumn.command = aListModel.get(i).command;
            if(aListModel.get(i).role !== undefined && newColumn.role.length > 0)   newColumn.role = aListModel.get(i).role;
            if(aListModel.get(i).visible !== undefined)   newColumn.visible = aListModel.get(i).visible;

            if(newColumn.width === 0) newColumn.width = 100;

            columns.append(newColumn);
        }
    }

    function columnsFromArray(jsArray){
        columns.clear();

        for(var i=0; i<jsArray.length; i++) {
            var newColumn = {
                "width": 100,
                "minWidth": 0,
                "title": "",
                "sort": 0,
                "dataType": BTColumn.Str,
                "view": 0,
                "command": 0,
                "role": "col" + i,
                "visible": true
            };

            if(jsArray[i].width !== undefined)   newColumn.width = jsArray[i].width;
            if(jsArray[i].minWidth !== undefined)   newColumn.minWidth = jsArray[i].minWidth;
            if(jsArray[i].title !== undefined)   newColumn.title = jsArray[i].title;
            if(jsArray[i].sort !== undefined)   newColumn.sort = jsArray[i].sort;
            if(jsArray[i].dataType !== undefined)   newColumn.dataType = jsArray[i].dataType;
            if(jsArray[i].view !== undefined)   newColumn.view = jsArray[i].view;
            if(jsArray[i].command !== undefined)   newColumn.command = jsArray[i].command;
            if(jsArray[i].role !== undefined && newColumn.role.length > 0)   newColumn.role = jsArray[i].role;
            if(jsArray[i].visible !== undefined)   newColumn.visible = jsArray[i].visible;

            if(newColumn.width === 0) newColumn.width = 100;

            columns.append(newColumn);
        }
    }

    property bool doFireColumnsChange: true
    function fromColumnListModelToTable(resetDefaults){
        if(!columns) return;
        if(!doFireColumnsChange) return;

        var i;
        if(columns.count > 0 && mainColumn.width > 0){
            var minWidth = 0;
            var toResize = new Set();

            for(i=0; i<columns.count; i++){
                if(columns.get(i).minWidth && columns.get(i).visible) {
                    toResize.add(i);
                    minWidth += columns.get(i).minWidth;
                }
            }

            if(toResize.size > 0) {
                doFireColumnsChange = false;

                var usedWidth = 0;
                for(i=0; i<columns.count; i++){
                    if(!toResize.has(i) && columns.get(i).visible) {
                        usedWidth += columns.get(i).width;
                    }
                }

                var newWidth = mainColumn.width - usedWidth;
                if( newWidth < minWidth ) {
                    //mantain minWidth
                    for (var iCol1 of toResize) {
                        if(columns.get(iCol1).width !== columns.get(iCol1).minWidth)
                            columns.get(iCol1).width = columns.get(iCol1).minWidth;
                    }
                }
                else {
                    var factor = newWidth / minWidth;
                    for (var iCol2 of toResize) {
                        if(columns.get(iCol2).width !== columns.get(iCol2).minWidth * factor)
                            columns.get(iCol2).width = columns.get(iCol2).minWidth * factor;
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
