import QtQuick 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: treeContainer

    property int rowHeight: BppMetrics.cellDataHeight
    property int indentWidth: 15
    property var nullCode: -1
    property bool withExtraDescription: false
    property int extraDescriptionWidth: 120
    property bool extraDescriptionFillWidth: false
    property bool useDynamicRolesForCode: false

    property int textHeight: BppMetrics.fontSizePtMedium
    property color textColor: BppMetrics.textColor

    property int extraTextHeight: BppMetrics.fontSizePtMedium
    property color extraTextColor: BppMetrics.textColorDisabled

    property string expanderFontFamily: ""
    property int expanderTextHeight: BppMetrics.fontSizePtBig
    property int expanderWidth: 20
    property color expanderTextColor: BppMetrics.textColorDisabled
    property string expanderOpened: "▼"
    property string expanderClosed: "►"

    property color bkSelColor: BppMetrics.listItemSelOdd
    property alias bkColor: treeContainer.color

    property alias selectedRow: listComponent.currentIndex

    property var depMap: new Map();
    property var codeMap: new Map();
    property var orphanChilds: [];

    color: BppMetrics.windowBackgroundAlt

    ListModel {
        id: treeModel
        dynamicRoles: useDynamicRolesForCode

//        let newItem = {
//            "visible": true,
//            "opened": true,
//            "indentation": 0,
//            "num_childs": 0,
//            "code": itemCode,
//            "descr": itemDescription,
//            "edescr": extraDescr,
//            "edata": extraData,
//            "code_parent": itemCodeParent
//        }
    }

    function rows(){
        return treeModel.count
    }

    function getItemByCode(itemCode){
        if(!codeMap.has(itemCode)) return null
        let itemIndex = codeMap.get(itemCode)
        return treeModel.get(itemIndex)
    }

    function getItemByIndex(itemIndex){
        return treeModel.get(itemIndex)
    }

    function selectByCode(itemCode){
        if(!codeMap.has(itemCode)) return
        let itemIndex = codeMap.get(itemCode)
        listComponent.currentIndex = itemIndex
    }

    function selectByIndex(itemIndex){
        listComponent.currentIndex = itemIndex
    }

    function collapseItem(itemCode, alsoChilds){
        if(!codeMap.has(itemCode)) return
        let itemIndex = codeMap.get(itemCode)
        setClosed(itemIndex, false)
        if(alsoChilds){
            if(depMap.has(itemCode)) {
                let childsSet = depMap.get(itemCode)
                for (let item of childsSet) {
                    collapseItem(item, alsoChilds)
                }
            }
        }
    }

    function expandItem(itemCode, alsoChilds){
        if(!codeMap.has(itemCode)) return
        let itemIndex = codeMap.get(itemCode)
        setOpened(itemIndex)
        if(alsoChilds){
            if(depMap.has(itemCode)) {
                let childsSet = depMap.get(itemCode)
                for (let item of childsSet) {
                    expandItem(item, alsoChilds)
                }
            }
        }
    }

    function collapseAll(alsoChilds){
        let childsSet = depMap.get(nullCode)
        for (let item of childsSet) {
            collapseItem(item, alsoChilds)
        }
    }

    function expandAll(alsoChilds){
        let childsSet = depMap.get(nullCode)
        for (let item of childsSet) {
            expandItem(item, alsoChilds)
        }
    }

    function selectItem(itemCode){
        if(!codeMap.has(itemCode)) return
        let itemIndex = codeMap.get(itemCode)
        listComponent.currentIndex = itemIndex
    }

    function clearTree(newNullValue){
        listComponent.model = null;
        treeModel.clear();

        if(newNullValue !== undefined)
            nullCode = newNullValue;

        orphanChilds = [];
        depMap = new Map();
        codeMap = new Map();
    }

    function computeHierarchy(){
        //resolve orphans
        let tryAgain = true
        while(tryAgain && orphanChilds.length > 0){
            let newOrphanChilds = []

            let howManyBefore = orphanChilds.length;
            for(let iArr=0; iArr<orphanChilds.length; iArr++) {
                let itemToTry = orphanChilds[iArr]
                if(!internalAppendElement(itemToTry.code, itemToTry.descr, itemToTry.code_parent, itemToTry.edata, itemToTry.edescr, false))
                    newOrphanChilds.push(itemToTry);
            }
            orphanChilds = newOrphanChilds;
            let howManyAfter = orphanChilds.length;
            tryAgain = howManyAfter !== howManyBefore;
        }

        if(orphanChilds.length > 0){
            console.log('WARNING BppTreeView.qml ORPHANS WITHOUT VALID PARENT:')
            for(let iOrp=0; iOrp<orphanChilds.length; iOrp++) {
                let itemToTry = orphanChilds[iOrp]
                console.log('code:', itemToTry.code, ' - parent:', itemToTry.code_parent);
            }
        }

        buildIndexMap();
        calcItemProperties();
        listComponent.model = treeModel
    }

    function addRelation(code, code_parent) {
        let childsSet = null;
        if(!depMap.has(code_parent)) {
            childsSet = new Set();
            depMap.set(code_parent, childsSet);
        }
        else {
            childsSet = depMap.get(code_parent)
        }
        childsSet.add(code)
    }

    function appendElement(itemCode, itemDescription, itemCodeParent, extraData, extraDescr){
        return internalAppendElement(itemCode, itemDescription, itemCodeParent, extraData, extraDescr, true)
    }

    function internalAppendElement(itemCode, itemDescription, itemCodeParent, extraData, extraDescr, doSaveOrphans){
        let insertedOk = false;

        let newItem = {
            "visible": true,
            "opened": true,
            "indentation": 0,
            "num_childs": 0,
            "code": itemCode,
            "descr": itemDescription,
            "edescr": extraDescr,
            "edata": extraData,
            "code_parent": itemCodeParent
        }

        if(itemCodeParent !== nullCode) {

            let posParent = -1;
            for(let i = 0; i < treeModel.count; i++){
                let curItem = treeModel.get(i);
                if(curItem.code === itemCodeParent) {
                    posParent = i;
                    break;
                }
            }

            if(posParent >= 0 ){
                addRelation(itemCode, itemCodeParent)
                let numChilds = countChilds(itemCodeParent)
                let appendPos = posParent + numChilds
                treeModel.insert(appendPos, newItem);
                insertedOk = true;
            }
            else {
                //parent not found
                if(doSaveOrphans)   orphanChilds.push(newItem);
            }
        }
        else {
            addRelation(itemCode, itemCodeParent)
            treeModel.append(newItem);
            insertedOk = true;
        }
//DEBUG MESSAGES
//        console.log('INSERT ', itemCode, orphanChilds.length)
//        for(let iArr=0; iArr<orphanChilds.length; iArr++) {
//            let itemToTry = orphanChilds[iArr]
//            console.log(itemToTry.code);
//        }
        return insertedOk;
    }

    function countChilds(code){
        let numChilds = 0;
        if(depMap.has(code)) {
            let childsSet = depMap.get(code);
            numChilds = childsSet.size;
            for (let item of childsSet) {
                numChilds += countChilds(item);
            }
        }
        return numChilds;
    }

    function buildIndexMap(){
        codeMap = new Map();
        for(let i = 0; i < treeModel.count; i++){
            let curItem = treeModel.get(i);
            codeMap.set(curItem.code, i);
        }
    }

    function calcLevel(itemCode){
        if(!codeMap.has(itemCode)) return 0;

        let itemIndex = codeMap.get(itemCode)
        let parentCode = treeModel.get(itemIndex).code_parent;

        if(depMap.has(parentCode)) {
            return 1 + calcLevel(parentCode);
        }
        else
            return 0;
    }

    function calcItemProperties(){
        for(let i = 0; i < treeModel.count; i++){
            let curItem = treeModel.get(i);

            let itemLevel = calcLevel(curItem.code)
            //console.log(curItem.code + ' lev ' + itemLevel)
            curItem.indentation = indentWidth * (itemLevel - 1);

            if(depMap.has(curItem.code)) {
                let childsSet = depMap.get(curItem.code)
                treeModel.setProperty(i, "num_childs", childsSet.size)
            }
            else {
                treeModel.setProperty(i, "num_childs", 0)
            }
        }
    }

    function setOpened(index){
        treeModel.setProperty(index, "opened", true)
        let curItem = treeModel.get(index);

        if(depMap.has(curItem.code)) {
            let childsSet = depMap.get(curItem.code)
            for (let childCode of childsSet) {
                let childIndex = codeMap.get(childCode)
                let childItem = treeModel.get(childIndex);
                treeModel.setProperty(childIndex, "visible", true)
                if(childItem.opened)
                    setOpened(childIndex)
            }
        }
    }

    function setClosed(index, onlyVisibility){
        if(!onlyVisibility) treeModel.setProperty(index, "opened", false)
        let curItem = treeModel.get(index);

        if(depMap.has(curItem.code)) {
            let childsSet = depMap.get(curItem.code)
            for (let childCode of childsSet) {
                let childIndex = codeMap.get(childCode)
                treeModel.setProperty(childIndex, "visible", false)
                setClosed(childIndex, true);
            }
        }
    }

    Component {
        id: treeItemDelegate

        Item {
            width: treeContainer.width
            height: model.visible ? treeContainer.rowHeight : 0
            visible: model.visible
            readonly property ListView __lv: ListView.view

            MouseArea {
                anchors.fill: parent
                onClicked: __lv.currentIndex = index
            }

            RowLayout {
                anchors.fill: parent
                anchors.leftMargin: 5
                anchors.rightMargin: 5
                Item {
                    Layout.minimumWidth: model.indentation
                }
                Text {
                    Layout.minimumWidth: expanderWidth
                    font.family: expanderFontFamily
                    font.pointSize: expanderTextHeight
                    color: expanderTextColor
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                    text: model.num_childs === 0
                          ? ""
                          : model.opened ? expanderOpened : expanderClosed
                    MouseArea {
                        anchors.fill: parent
                        propagateComposedEvents: true
                        onClicked: {
                            //__lv.currentIndex = index
                            if(!opened)
                                setOpened(index)
                            else
                                setClosed(index, false)
                            mouse.accepted = false
                        }
                    }
                }

                Text {
                    Layout.fillWidth: extraDescriptionFillWidth ? true : false
                    text: model.descr;
                    font.pointSize: treeContainer.textHeight
                    color: treeContainer.textColor
                    verticalAlignment: Text.AlignVCenter
                    elide: Qt.ElideRight
                }
                Text {
                    Layout.minimumWidth: extraDescriptionWidth
                    Layout.fillWidth: extraDescriptionFillWidth ? false : true
                    visible: withExtraDescription
                    text: model.edescr;
                    font.pointSize: treeContainer.extraTextHeight
                    color: treeContainer.extraTextColor
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignRight
                    elide: Qt.ElideRight
                }
            }
        }
    }

    ListView {
        id: listComponent
        //model: treeModel
        delegate: treeItemDelegate
        anchors.fill: parent
        focus: true
        clip: true
        highlightMoveDuration: 500
        highlight: Rectangle {
            color: treeContainer.bkSelColor
            width: listComponent.width
        }
    }

}
