import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtGraphicalEffects 1.12
import QtQuick.Controls 2.12
import BppTableModel 0.1

Item {
    id: mainItem
    property int dataHeight: 30
    property color dataHighlight: "darkturquoise"
    property color dataBkOdd: "#FFFFFF"
    property color dataBkEven: "#F6F8FA"
    property color dataBkSelOdd: "#40ffa8"
    property color dataBkSelEven: "#3df5a1"

    property int headingsHeight: 30
    property color headingsBk: "#E7E7E7"
    property color headingsLines: "#C5C5C5"
    //property color headingsTextColor: "#313131"
    property color headingsTextColor: "black"
    property color headingsSortColor: "#000099"
    property color headingsNoSortColor: "#777777"

    property string dateFormat: "dd/MM/yyyy"
    property string dateTimeFormat: "dd/MM/yyyy HH:mm:ss"

    property bool showOptionsButton: true
    property string icoCopy: "qrc:/BppTable/assets/copy-solid.svg"
    property string ttCopy: qsTr("Copy current row")
    property string icoOptions: "qrc:/BppTable/assets/cog-solid.svg"
    property string ttOptions: qsTr("Options")
    property string icoCancel: "qrc:/BppTable/assets/icon-delete.svg"
    property string ttCancel: qsTr("Exit")

    property bool withMultiselection: false
    property bool withMultiselectionMobileMode: false

    property var cellDelegate: null
    property int selectedRow: -1

    property var fromListModel: null
    property var fromArray: null

    property ListModel columns: ListModel{}

    signal selectionChanged();

    function rows(){
        return gridDataModel.rowCount();
    }

    function cellValue(row, col){
        return gridDataModel.data( gridDataModel.index(row, col), "display" );
    }

    function setSelectedRow(row, modifiers) {
        if(arguments.length < 2) //no argument [modifiers] provided
            modifiers = 0;
        gridDataModel.setHighlightRow(row, modifiers);
    }
    function clearSelection(){
        gridDataModel.setHighlightRow(-1, 0);
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

                                MouseArea {
                                    id: mouseAreaColumn
                                    anchors.fill: parent
                                    acceptedButtons: Qt.LeftButton | Qt.RightButton

                                    onClicked: {
                                        if(mouse.button === Qt.RightButton) {
                                            setResizeColumn(index);
                                        }
                                        else {
                                            if(optionsPopup.clickColumnAction === 1 || columnDragger.visible) {
                                                setResizeColumn(index);
                                            }
                                            else {
                                                if(sortIndicator !== 4) {
                                                    var newSort = columns.get(index).sort;
                                                    newSort++;
                                                    if(newSort > 2) newSort = 0;

                                                    gridDataModel.dataNeedSort();
                                                    columns.get(index).sort = newSort;
                                                }
                                            }
                                        }
                                    }
                                    onPressAndHold: {
                                        setResizeColumn(index);
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

                Rectangle {
                    color: headingsBk
                    border.color: headingsLines
                    Layout.fillWidth: true
                    height: headingsHeight
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

                    /*
                    Rectangle {
                        id: highlightRect
                        border.width: 2
                        border.color: dataHighlight
                        color: "transparent"
                        radius: 5
                        anchors.left: parent.left
                        width: tview.width
                        //anchors.right: parent.right
                        z:2
                        y:0
                        height: 100
                        visible: false
                    }
                    */
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

        onWidthChanged: {
            fromColumnListModelToTable(false); //resize columns
        }

        Popup {
            id: optionsPopup
            anchors.centerIn: parent
            width: 300
            height: 200
            modal: true
            focus: visible
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

            property int clickColumnAction: 0 //0=sort; 1=resize

            ColumnLayout {
                anchors.fill: parent
                Label {
                    text: qsTr("Tap/Click on column")
                    font.pointSize: Qt.application.font.pointSize * 1.5
                    font.bold: true
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    RadioButton {
                        checked: true
                        text: qsTr("Sort")
                        onClicked: optionsPopup.clickColumnAction = 0
                    }
                    RadioButton {
                        text: qsTr("Resize")
                        onClicked: optionsPopup.clickColumnAction = 1
                    }
                }

                Item {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                }

                RowLayout {
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignCenter
                    Button {
                        text: qsTr("Done")
                        onPressed: optionsPopup.close()
                    }
                }
            }
        }

        RoundButton {
            id: btnOptions
            visible: showOptionsButton
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10
            z:3

            property string currentIcoOptions: icoOptions
            property string currentTtOptions: ttOptions
            property int optionBehaviour: 0; //0=open popup; 1=copy to clipboard; 2 cancel column resize

            icon.source: currentIcoOptions
            padding: 0

            ToolTip.visible: hovered
            ToolTip.text: currentTtOptions
            onPressed: {
                    if(optionBehaviour === 0)
                        optionsPopup.open();
                    else if(optionBehaviour === 1)
                        gridDataModel.copyRowToClipboard(selectedRow);
                    else if(optionBehaviour === 2)
                        setResizeColumn(-1);
            }
        }
    }

    function setOptionIcon() {
        if(columnIndicator.visible) {
            btnOptions.optionBehaviour = 2;
            btnOptions.currentIcoOptions = icoCancel
            btnOptions.currentTtOptions = ttCancel
        }
        else {
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
    }

    property BTModel gridDataModel: BTModel {
        hasMultiselection: withMultiselection
        multiselectionMobileMode: withMultiselectionMobileMode
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
        }
        else {
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

            columnIndicator.x = currentResizePos - columnIndicator.width / 2
            columnDragger.x = currentResizePos - columnDragger.width / 2
            columnDragger.y = 40
            xStart = columnDragger.x
            xDelta = 0

            columnIndicator.visible = true
            columnDragger.visible = true
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

                columnIndicator.x += xDelta
                xDelta = 0
                xStart = columnDragger.x

                fromColumnListModelToTable(false);
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
        fromColumnListModelToTable(false);
    }

    function columnsFromArray(jsArray){
        if(jsArray === null) return;

        columns.clear();
        for(var i=0; i<jsArray.length; i++) {
            appendCol(jsArray[i], i);
        }
        fromColumnListModelToTable(false);
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

        if(currentResizeColumn >= 0)
            recalcDragger();
    }

    Connections {
        target: gridDataModel
        onHighlightRowChanged: {
            selectedRow = gridDataModel.highlightRow
            /*
            highlightRect.y = gridDataModel.highlightRow * dataHeight;
            highlightRect.height = dataHeight;
            highlightRect.width = tview.width
            highlightRect.visible = gridDataModel.highlightRow >= 0
            */
            setOptionIcon();
            selectionChanged();
        }
    }
}
