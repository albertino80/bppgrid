import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.12
import QtQuick.Controls 2.12
import BppTable 0.1

Item {
    id: mainItem
    property int dataHeight: 30
    property color dataHighlight: "darkturquoise"
    property color dataBkOdd: "#FFFFFF"     //data background odd row
    property color dataBkEven: "#F6F8FA"    //data background even row
    property color dataBkSelOdd: "#40ffa8"  //selection background odd row
    property color dataBkSelEven: "#3df5a1" //selection background even row

    property int headingsHeight: 30
    property int headingsFontSizePt: 11

    property color headingsBk: "#E7E7E7"
    property color headingsBkAlt: "white"   //heading hovered color
    property color headingsLines: "#C5C5C5" //no data space
    //property color headingsTextColor: "#313131"
    property color headingsTextColor: "black"
    property color headingsSortColor: "#000099"
    property color disabledTextColor: "gray"

    property string dateFormat: "dd/MM/yyyy"
    property string dateTimeFormat: "dd/MM/yyyy HH:mm:ss"

    property bool showOptionsButton: true
    property bool clickOnNothingClearSel: true
    property bool showHeadingColumns: true

    property string icoCopy: "qrc:/BppTable/assets/copy-solid.svg"
    property string ttCopy: qsTr("Copy current row")
    property string icoOptions: "qrc:/BppTable/assets/cog-solid.svg"
    property string ttOptions: qsTr("Options")
    property string icoCancel: "qrc:/BppTable/assets/icon-delete.svg"
    property string ttCancel: qsTr("Exit")

    property string fontButtonsPage: Qt.application.font.family
    property string txtPageNext: ">"
    property string txtPageLast: "»"
    property string txtPagePrev: "<"
    property string txtPageFirst: "«"

    property bool withMultiselection: false
    property bool withMultiselectionMobileMode: false
    property bool withOptionEvent: false

    property bool withPagination: false
    property int pageSize: 5
    property int pageCurrent: 0
    property int allPagesRecords: 0

    property var cellDelegate: null
    property int selectedRow: -1

    property var fromListModel: null
    property var fromArray: null

    property var selectedValueCache: null

    property ListModel columns: ListModel{}

    signal selectionChanged();
    signal openOptions();
    signal fetchPageRecords();

    function rows(){
        return gridDataModel.rowCount();
    }

    function cols(){
        return gridDataModel.columnCount();
    }

    function getColumnId(colName){
        return gridDataModel.getColumnId(colName);
    }

    function cellValue(row, col){
        var colId = 0;
        if (typeof col === 'string') {
            colId = gridDataModel.getColumnId(col);
            if(colId < 0) {
                console.log("WARNING bpp::grid setCellValue(%1,%2) Column not found".arg(row).arg(col));
                return 0;
            }
        }
        else
            colId = col;

        return gridDataModel.data( gridDataModel.index(row, colId), "display" );
    }

    function setCellValue(row, col, newCellVal){
        if (typeof col === 'string') {
            var colId = gridDataModel.getColumnId(col);
            if(colId >= 0)
                gridDataModel.setCellValue(row, colId, newCellVal);
            else {
                console.log("WARNING bpp::grid setCellValue(%1,%2,%3) Column not found".arg(row).arg(col).arg(newCellVal));
            }
        }
        else {
            gridDataModel.setCellValue(row, col, newCellVal);
        }
    }

    function selectByValue(columnRole, columnValue) {
        var colId = gridDataModel.getColumnId(columnRole);
        if(colId < 0){
            console.log("WARNING bpp::grid selectByValue(%1,...) Column not found".arg(columnRole));
            return false;
        }

        let toSel = -1;
        for(let iRow=0; iRow<gridDataModel.rowCount(); iRow++){
            if(gridDataModel.data( gridDataModel.index(iRow, colId), "display" ) === columnValue) {
                toSel = iRow;
                break;
            }
        }

        if(toSel >= 0) {
            setSelectedRow(toSel, 0);
            return true;
        }
        return false;
    }

    function setSelectedRow(row, modifiers) {
        if(arguments.length < 2) //no argument [modifiers] provided
            modifiers = 0;
        gridDataModel.setHighlightRow(row, modifiers);

        if(tview.contentY >= row * dataHeight) {
            if(row === 0)
                tview.contentY = 0
            else
                tview.contentY = row - 1 * dataHeight
        }
    }
    function setSelectedRows(doEmpty, rows) {
        gridDataModel.setHighlightRows(doEmpty, rows);
    }
    function clearSelection(){
        gridDataModel.setHighlightRow(-1, 0);
    }

    function selectionPushValue(columnRole){
        selectedValueCache = null
        if(selectedRow>=0)
            selectedValueCache = cellValue(selectedRow, columnRole);
    }

    function selectionPopValue(columnRole, gotoFirstIfNotFound){
        if(rows() > 0) {
            let selectionDone = false
            if(selectedValueCache != null)
                selectionDone = selectByValue(columnRole, selectedValueCache)
            if(!selectionDone && gotoFirstIfNotFound)
                setSelectedRow(0);
        }
    }

    function selectAll(){
        gridDataModel.setHighlightRow(-2, 0);
    }
    function countSelection(){
        return gridDataModel.countHighlightRows();
    }
    function getSelectedRows(){
        return gridDataModel.getHighlightRows();
    }
    function getRowObject(row){
        return gridDataModel.getRowObject(row);
    }

    function getCellBackground(row) {
        console.log('Warning deprecated function, use getCellBk(row, highlight)')
        return dataBkOdd;
    }

    function getCellBk(row, isHilighted) {
        if(isHilighted){
            if(row % 2 == 0)    return dataBkSelOdd;
            return dataBkSelEven;
        }

        if(row % 2 == 0)    return dataBkOdd;
        return dataBkEven;
    }

    function clearData(){
        gridDataModel.beginReset(false);
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
        gridDataModel.beginReset(false);
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

    function countFromQuery(theDb, theSql, theParameters){
        gridDataModel.setDbRef( theDb );
        return gridDataModel.countFromQuery(theSql, theParameters);
    }

    function fillFromJson(theJson, resetList){
        if(arguments.length < 2) resetList = true;
        gridDataModel.addFromList(theJson, resetList);
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

    function computeLayout(){
        tview.forceLayout();
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
        id: gridContainer
        border.color: headingsLines
        color: headingsLines
        anchors.fill: parent

        Flickable {
            id: headingsFlick
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: showHeadingColumns ? headingsHeight : 0
            anchors.leftMargin: 1
            anchors.rightMargin: 1
            topMargin: 1
            visible: showHeadingColumns

            contentWidth: tview.contentWidth
            boundsBehavior: Flickable.StopAtBounds
            clip: true

            RowLayout {
                id: headings
                spacing: 1

                Repeater {
                    id: colRepeater
                    model: columns //ListModel {}
                    Rectangle{
                        id: headingCell
                        Layout.minimumWidth: model.width;
                        Layout.minimumHeight: headingsFlick.height
                        color: model.index === currentResizeColumn ? headingsBkAlt : headingsBk
                        visible: model.visible
                        border.width: (mouseAreaColumn.isHovered || model.index === currentResizeColumn) ? 1 : 0
                        border.color: model.index === currentResizeColumn ? headingsBk : headingsBkAlt

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
                            font.pointSize: headingsFontSizePt
                            text: title
                            elide: Qt.ElideRight
                        }

                        Image {
                            id: sortImage
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.rightMargin: 5
                            visible: headingCell.sortIndicator !== 4 && headingCell.sortIndicator !== 0 && currentResizeColumn !== model.index

                            source: headingCell.sortIndicator === 1 ? "qrc:/BppTable/assets/sort-up.svg" : "qrc:/BppTable/assets/sort-down.svg"
                            width: 10; height: 10
                        }
                        ColorOverlay{
                            visible: sortImage.visible
                            anchors.fill: sortImage
                            source:sortImage
                            color: headingsSortColor
                            transform:rotation
                            antialiasing: true
                        }

                        MouseArea {
                            id: mouseAreaColumn
                            anchors.fill: parent
                            acceptedButtons: Qt.LeftButton | Qt.RightButton
                            hoverEnabled: true
                            property bool isHovered: false

                            onClicked:  setResizeColumn(index);

                            onEntered: isHovered = true
                            onExited: isHovered = false
                        }
                    }
                }
            }

            onContentXChanged: {
                if(contentX >= 0 && tview.contentX !== contentX)
                    tview.contentX = contentX
            }
        }

        Rectangle {
            id: selectionBar
            color: headingsBk
            border.color: headingsLines
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: headingsFlick.bottom
            height: withMultiselection ? headingsHeight : 0
            visible: withMultiselection
            RowLayout{
                id: selectionPanel
                anchors.fill: parent
                anchors.margins: 5
                Text {
                    text: qsTr("Select")
                    color: headingsTextColor
                }
                Repeater {
                    model: ListModel{
                        ListElement{
                            linkAction: "all"
                            linkText: qsTr("All")
                        }
                        ListElement{
                            linkAction: "none"
                            linkText: qsTr("None")
                        }
                    }
                    Text {
                        text: '<html><a href="%1">%2</a></html>'.arg(linkAction).arg(linkText)
                        linkColor: headingsTextColor
                        onLinkActivated: {
                            if(link === "all")  selectAll();
                            else if(link === "none")  clearSelection();
                        }
                        MouseArea {
                            anchors.fill: parent
                            acceptedButtons: Qt.NoButton // we don't want to eat clicks on the Text
                            cursorShape: parent.hoveredLink ? Qt.PointingHandCursor : Qt.ArrowCursor
                        }
                    }
                }
                Item {
                    Layout.fillWidth: true
                }
            }
        }

        TableView {
            id: tview
            columnSpacing: 1
            rowSpacing: 0
            clip: true
            boundsBehavior: Flickable.StopAtBounds
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: selectionBar.bottom
            anchors.bottom: statusBar.top
            anchors.leftMargin: 1
            anchors.rightMargin: 1

            columnWidthProvider: gridDataModel.getColWidth;

            model: gridDataModel
            reuseItems: true

            delegate: cellDelegate

            ScrollBar.horizontal: ScrollBar {
                visible: (tview.contentWidth > tview.width + 2)
                orientation: Qt.Horizontal
                policy: ScrollBar.AsNeeded
            }
            ScrollBar.vertical: ScrollBar {
                visible: (tview.contentHeight > tview.height + 2)
                orientation: Qt.Vertical
                id: verticalScrollbar
                policy: ScrollBar.AsNeeded
            }

            onContentXChanged: {
                if(contentX >= 0 && headingsFlick.contentX !== contentX)
                    headingsFlick.contentX = contentX
            }
        }

        Rectangle{
            id: statusBar
            color: headingsBk
            border.color: headingsLines
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            height: withPagination ? headingsHeight : 0
            visible: withPagination
            RowLayout{
                anchors.fill: parent
                anchors.leftMargin: 5
                anchors.rightMargin: 1
                spacing: 0

                Item {
                    Layout.fillWidth: true
                }

                Label{
                    Layout.alignment: Qt.AlignVCenter
                    text: qsTr("Showing rows %1 - %2 of %3")
                        .arg( (pageSize * pageCurrent) + 1 )
                        .arg( Math.min(allPagesRecords, pageSize * pageCurrent + pageSize) )
                        .arg( allPagesRecords );
                }

                Rectangle {
                    Layout.leftMargin: 20
                    Layout.preferredWidth: 1
                    height: headingsHeight - 2
                    color: headingsLines
                }

                GridStatusButton{
                    Layout.preferredWidth: headingsHeight - 2
                    height: headingsHeight - 2
                    color: dataBkEven
                    //border.color: headingsLines
                    fontSizePt: headingsFontSizePt * 1.4
                    textColor: headingsTextColor
                    textColorDisabled: disabledTextColor
                    enabled: pageCurrent >= 1
                    buttonText: txtPageFirst
                    buttonFontFamily: fontButtonsPage
                    onPressed: {
                        pageCurrent = 0;
                        fetchPageRecords();
                    }
                }
                GridStatusButton{
                    Layout.preferredWidth: headingsHeight - 2
                    height: headingsHeight - 2
                    color: dataBkEven
                    //border.color: headingsLines
                    fontSizePt: headingsFontSizePt * 1.4
                    textColor: headingsTextColor
                    textColorDisabled: disabledTextColor
                    enabled: pageCurrent >= 1
                    buttonText: txtPagePrev
                    buttonFontFamily: fontButtonsPage
                    onPressed: {
                        pageCurrent--;
                        fetchPageRecords();
                    }
                }

                Rectangle {
                    Layout.preferredWidth: 120
                    height: headingsHeight
                    color: dataBkOdd
                    border.color: headingsLines
                    Text {
                        anchors.fill: parent
                        text: qsTr("Page %1 of %2").arg(pageCurrent + 1).arg( Math.ceil(allPagesRecords / pageSize) )
                        font.pointSize: headingsFontSizePt
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        color: headingsTextColor
                    }
                }

                GridStatusButton{
                    Layout.preferredWidth: headingsHeight - 2
                    height: headingsHeight - 2
                    color: dataBkEven
                    //border.color: headingsLines
                    fontSizePt: headingsFontSizePt * 1.4
                    textColor: headingsTextColor
                    textColorDisabled: disabledTextColor
                    enabled: pageSize * (pageCurrent + 1) < allPagesRecords
                    buttonText: txtPageNext
                    buttonFontFamily: fontButtonsPage
                    onPressed: {
                        pageCurrent++;
                        fetchPageRecords();
                    }
                }

                GridStatusButton{
                    Layout.preferredWidth: headingsHeight - 2
                    height: headingsHeight - 2
                    color: dataBkEven
                    //border.color: headingsLines
                    fontSizePt: headingsFontSizePt * 1.4
                    textColor: headingsTextColor
                    textColorDisabled: disabledTextColor
                    enabled: pageSize * (pageCurrent + 1) < allPagesRecords
                    buttonText: txtPageLast
                    buttonFontFamily: fontButtonsPage
                    onPressed: {
                        pageCurrent = Math.ceil(allPagesRecords / pageSize) - 1;
                        fetchPageRecords();
                    }
                }
            }
        }

        MouseArea {
            enabled: clickOnNothingClearSel
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: tview.bottom
            height: tview.height - tview.contentHeight
            z:1
            propagateComposedEvents: true
            onClicked: {
                clearSelection();
            }
        }

        Rectangle {
            id: columnIndicator
            z:1
            border.width: 2
            border.color: dataHighlight

            y:0
            x: 0
            height: gridContainer.height

            width: 3
            visible: false
        }

        Rectangle {
            id: columnDragger
            z:2

            width: draggerSize
            height: draggerSize

            border.color: "#303030"
            color: "#C0C0C0"
            radius: draggerSize / 2

            Image {
                source: "qrc:/BppTable/assets/arrows-alt-h-solid.svg"
                anchors.centerIn: parent
                sourceSize: Qt.size(24,24)
            }

            DragHandler {
                yAxis.enabled: false
                xAxis.minimum: currentResizeLimit
            }

            onXChanged: {
                if(visible) {
                    xDelta = x - xStart

                    timerDrag.restart()
                    timerDrag.running = true
                }
            }

            visible: false
        }
        Rectangle {
            id: columnSorter
            z:2

            width: draggerSize
            height: draggerSize

            border.color: "#303030"
            color: "#C0C0C0"
            radius: draggerSize / 2
            property int currentSortValue: 0

            Image {
                source: columnSorter.currentSortValue === 0 ? "qrc:/BppTable/assets/sort-up-and-down.svg" :
                                                              (columnSorter.currentSortValue === 1 ? "qrc:/BppTable/assets/sort-up.svg" : "qrc:/BppTable/assets/sort-down.svg")
                anchors.centerIn: parent
                sourceSize: Qt.size(20,20)
            }

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    columnSorter.currentSortValue = (columnSorter.currentSortValue+1) % 3

                    //performance speedup
                    verticalScrollbar.setPosition(0);

                    gridDataModel.dataNeedSort();
                    columns.get(currentResizeColumn).sort = columnSorter.currentSortValue;
                }
            }

            visible: false
        }

        onWidthChanged: {
            fromColumnListModelToTable(false); //resize columns
        }

        RoundButton {
            id: btnOptions
            visible: showOptionsButton && (optionBehaviour > 0 || withOptionEvent)
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.rightMargin: 5
            anchors.bottomMargin: withPagination ? 35 : 10
            z:3

            property string currentIcoOptions: icoOptions
            property string currentTtOptions: ttOptions
            property int optionBehaviour: 0; //0=open popup; 1=copy to clipboard

            icon.source: currentIcoOptions
            padding: 0

            ToolTip.visible: hovered
            ToolTip.text: currentTtOptions
            onPressed: {
                    if(optionBehaviour === 0)
                        openOptions();
                    else if(optionBehaviour === 1)
                        gridDataModel.copyRowToClipboard(selectedRow);
            }
        }
    }

    function setOptionIcon() {
        if(selectedRow === -1) {
            btnOptions.optionBehaviour = 0;
            btnOptions.currentIcoOptions = icoOptions
            btnOptions.currentTtOptions = ttOptions
        }
        else {
            btnOptions.optionBehaviour = 1;
            btnOptions.currentIcoOptions = icoCopy
            btnOptions.currentTtOptions = ttCopy
        }
    }

    property BTModel gridDataModel: BTModel {
        hasMultiselection: withMultiselection
        multiselectionMobileMode: withMultiselectionMobileMode
    }

    Connections{
        target: columns
        onDataChanged: {
            fromColumnListModelToTable(true);
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

    property int currentResizeColumn: -1
    property real currentResizePos: 0
    property real currentResizeLimit: 0
    property real draggerSize: 30
    property real xStart: 0
    property real xDelta: 0

    function recalcDragger() {
        if(currentResizeColumn == -1) {
            columnIndicator.visible = false
            columnDragger.visible = false
            columnSorter.visible = false
        }
        else {
            if(currentResizeColumn === columns.count - 1){
                if(tview.contentWidth > tview.width) {
                    tview.contentX = tview.contentWidth - tview.width
                }
            }

            var curCol = null;
            var newPos = 0;
            var newLimit = 0
            for(var i=0; i<=currentResizeColumn; i++){
                curCol = columns.get(i);
                if(curCol.visible) {
                    newLimit = newPos
                    newPos += columns.get(i).width;
                    if(i < columns.count -1) newPos++;
                }
            }

            currentResizePos = newPos;
            currentResizeLimit = newLimit - columnDragger.width / 2;

            columnIndicator.visible = false
            columnDragger.visible = false
            columnSorter.visible = false

            columnIndicator.x = currentResizePos - columnIndicator.width / 2 - tview.contentX
            columnDragger.x = currentResizePos - columnDragger.width / 2 - tview.contentX
            columnDragger.y = 40
            columnSorter.x = columnDragger.x
            columnSorter.y = 0
            xStart = columnDragger.x
            xDelta = 0

            columnIndicator.visible = true
            columnDragger.visible = true
            if(columns.get(currentResizeColumn).sort !== 4) {
                columnSorter.currentSortValue = columns.get(currentResizeColumn).sort
                columnSorter.visible = true
            }
        }
        setOptionIcon();
    }

    function setResizeColumn(index) {
        if(currentResizeColumn !== index)
            currentResizeColumn = index;
        else
            currentResizeColumn = -1;
        recalcDragger();
    }

    Timer {
        id: timerDrag
        interval: 200
        running: false
        repeat: false

        onTriggered: {
            if(xDelta >= 1.0 || xDelta <= -1.0) {
                var oldW = columns.get(currentResizeColumn).width
                var oldFire = doFireColumnsChange
                doFireColumnsChange = false

                columns.get(currentResizeColumn).minWidth = 0
                columns.get(currentResizeColumn).width = oldW + xDelta

                doFireColumnsChange = oldFire

                fromColumnListModelToTable(false);
                gridDataModel.beginReset(true);
                gridDataModel.endReset();
                tview.forceLayout();

                recalcDragger();
            }
        }
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
        fromColumnListModelToTable(true);
    }

    function columnsFromArray(jsArray){
        if(jsArray === null) return;

        columns.clear();
        for(var i=0; i<jsArray.length; i++) {
            appendCol(jsArray[i], i);
        }
        fromColumnListModelToTable(true);
    }

    property bool doFireColumnsChange: true
    function setGridContentWidth(){
        let usedWidth = 0;
        let numVisible = 0;
        for(let i=0; i<columns.count; i++){
            let curCol = columns.get(i);
            if(curCol.visible) {
                numVisible++;
                usedWidth += columns.get(i).width;
            }
        }
        let colSpace = numVisible - 1;
        tview.contentWidth = usedWidth + colSpace;
    }

    function fromColumnListModelToTable(renewColumns){
        if(!columns) return;
        if(!doFireColumnsChange) return;

        var i;
        var availableSpace = tview.width;
        //tview.contentX = 0

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

        //console.log(doFireColumnsChange, columns.count, gridContainer.width, renewColumns)
        if(columns.count > 0 && availableSpace > 0){
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

                let numVisible = 0;
                var usedWidth = 0;
                for(i=0; i<columns.count; i++){
                    curCol = columns.get(i);
                    if(curCol.visible) {
                        numVisible++;
                        if(!curCol.minWidth)
                            usedWidth += columns.get(i).width;
                    }
                }

                let colSpace = numVisible - 1;
                var newWidth = availableSpace - colSpace - usedWidth;
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
                            calcWidth = availableSpace - colSpace - (allWidth + usedWidth)
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

        setGridContentWidth()

        if(renewColumns) {
            gridDataModel.clearColumnsDef();
            for(i=0; i<columns.count; i++) {
                var newCol = gridDataModel.addColumnDef();
                gridDataModel.setColumnDef(newCol, false, JSON.parse(JSON.stringify(columns.get(i))) )
            }
            gridDataModel.endUpdateColumns( );
        }
        else {
            for(i=0; i<columns.count; i++) {
                gridDataModel.setColumnDef(i, false, JSON.parse(JSON.stringify(columns.get(i))) )
            }
            gridDataModel.endUpdateColumns( );
        }

        if(currentResizeColumn >= 0) recalcDragger();
    }

    Connections {
        target: gridDataModel
        onHighlightRowChanged: {
            selectedRow = gridDataModel.highlightRow
            setOptionIcon();
            selectionChanged();
        }
    }
}
