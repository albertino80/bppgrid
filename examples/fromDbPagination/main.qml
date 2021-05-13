import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import BppTable 0.1

Window {
    visible: true
    width: 840
    height: 480
    title: qsTr("Hello World")

    function buildQuery(){
        var parameters = [];

        var sqlData = "SELECT pkid,null,null,year,city,sport,gender,
            golds,
            silvers,
            bronzes,
            round(cast(golds as double) / (golds + silvers + bronzes) * 100.0) as p_golds,
            golds + silvers + bronzes as total
            FROM olimpic_ita_medals";

        var sqlCount = "SELECT count(*) FROM olimpic_ita_medals"
        var sqlLimit = "LIMIT ? OFFSET ?"

        var sqlWhere = "";
        if(txtSearch.text.length>0 || cmbGender.currentIndex > 0){
            sqlWhere += "where";
        }

        if(txtSearch.text.length>0){
            sqlWhere += " (city like '%' || ? || '%' or sport like '%' || ? || '%')";
            parameters.push( txtSearch.text.toLowerCase() )
            parameters.push( txtSearch.text.toLowerCase() )
        }

        if(cmbGender.currentIndex > 0) {
            if(txtSearch.text.length>0) sqlWhere += " AND"
            sqlWhere += " gender = ?";
            parameters.push( cmbGender.model[cmbGender.currentIndex] )
        }

        sqlData += " " + sqlWhere;
        sqlData += " order by year desc";
        if(bGrid.withPagination) sqlData += " " + sqlLimit;

        var parametersCount = parameters.slice();

        if(bGrid.withPagination) {
            parameters.push(bGrid.pageSize); //LIMIT
            parameters.push(bGrid.pageCurrent * bGrid.pageSize) //OFFSET
        }

        sqlCount += " " + sqlWhere;

        return {
            'dataSql': sqlData,
            'countSql': sqlCount,
            'dataParameters': parameters,
            'countParameters': parametersCount
        }
    }

    function fillTable(resetPagination){
        var startTime = new Date().getTime()
        var qry = buildQuery();

        if(resetPagination) {
            bGrid.pageCurrent = 0
        }

        if(bGrid.withPagination) bGrid.allPagesRecords = bGrid.countFromQuery( workDb, qry.countSql, qry.countParameters);
        bGrid.fillFromQuery( workDb, qry.dataSql, qry.dataParameters);

        console.log( new Date().getTime() - startTime + " ms - page " + bGrid.pageCurrent );

        txtInfo.text = 'Loaded: ' + bGrid.rows() + " rows"
    }

    function getGender(display, dataType){
        let icon = "";
        let color = "";

        if(dataType === BTColumn.Str) {
            if(display === "Men") {
                icon = Fa.fa_male;
                color = "blue";
            }
            else {
                icon = Fa.fa_female;
                color = "deeppink";
            }
        }
        return {
            'icon': icon,
            'color': color
        };
    }

    ColumnLayout {
        id: gridLayout
        anchors.fill: parent
        anchors.margins: 10

        RowLayout {
            Button {
                text: "10 Records"
                onPressed: {
                    bGrid.withPagination = true
                    bGrid.pageSize = 10
                    fillTable(true)
                }
            }

            Button {
                text: "5 Records"
                onPressed: {
                    bGrid.withPagination = true
                    bGrid.pageSize = 5
                    fillTable(true)
                }
            }

            Button {
                text: "No pagination"
                onPressed: {
                    bGrid.withPagination = false
                    fillTable(true)
                }
            }

            Text {
                id: txtInfo
                font.pointSize: 11
                text: ""
            }
        }

        RowLayout{
            Layout.fillWidth: true
            ComboBox{
                id: cmbGender
                Layout.minimumWidth: 140
                model: ["<gender>", "Men", "Women"]
                currentIndex: 0
            }
            TextField{
                id: txtSearch
                Layout.fillWidth: true
                placeholderText: qsTr("Enter search query on city/sport column")
                text: ""
            }
            Button{
                text: "Fill table"
                onPressed: {
                    fillTable(true);
                }
            }
        }

        ListModel{
            id: modColumns
            ListElement { width: 40; title: "ID"; dataType: BTColumn.Int; role: "id" }
            ListElement { width: 40; title: ""; sort: 4; view: Enums.CellView.CommandButton; command: Enums.Commands.DoCmd1; dataRef1: "id" }
            ListElement { width: 40; title: ""; sort: 4; view: Enums.CellView.CommandButton; command: Enums.Commands.DoCmd2; dataRef1: "id" }
            ListElement { width: 60; title: "Year"; dataType: BTColumn.Int }
            ListElement { minWidth: 110; title: "City" }
            ListElement { minWidth: 120; title: "Sport" }
            ListElement { width: 40; title: ""; view: Enums.CellView.GenderCell }
            ListElement { width: 70; title: "Golds"; dataType: BTColumn.Int }
            ListElement { width: 70; title: "Silv."; dataType: BTColumn.Int }
            ListElement { width: 70; title: "Bronz."; dataType: BTColumn.Int }
            ListElement { width: 70; title: "% Gold"; dataType: BTColumn.Int; view: Enums.CellView.ProgressView }
            ListElement { width: 50; title: "Tot"; dataType: BTColumn.Int }
        }

        CompGrid {
            id: bGrid
            Layout.fillWidth: true
            Layout.fillHeight: true
            withMultiselection: true

            dataHeight: 40
            dateFormat: "MMM yyyy"
            //withPagination: true
            pageSize: 5

            Component {
                id: cellDelegate

                Rectangle {
                    implicitHeight: bGrid.dataHeight
                    color: bGrid.getCellBk(row, highlight)
                    visible: model.visible
                    readonly property var curValue: display
                    readonly property var curGender: view === Enums.CellView.GenderCell ? getGender(curValue, dataType) : {'icon': '','color': ''}

                    CellText {
                        visible: view === Enums.CellView.SimpleText
                        text: bGrid.formatDisplay(curValue, dataType, 2)
                        horizontalAlignment: bGrid.getAlign(dataType)
                        font.capitalization: Font.Capitalize
                    }

                    CellText {
                        visible: view === Enums.CellView.GenderCell
                        font.family: Fa.solid
                        text: curGender.icon
                        color: curGender.color
                        horizontalAlignment: Text.AlignHCenter;
                        font.pointSize: 14
                    }

                    ButtonAction {
                        visible: view === Enums.CellView.CommandButton
                        commandId: command
                    }

                    ProgressBar {
                        id: control
                        visible: view === Enums.CellView.ProgressView
                        anchors.centerIn: parent
                        width: 60
                        from: 0
                        to: 100
                        value: model.dataType === BTColumn.Int ? curValue : 0

                        background: Rectangle {
                            implicitHeight: 18
                            color: "lavenderblush"
                        }

                        contentItem: Item {
                            Rectangle {
                                id: rectLeft
                                width: control.visualPosition * parent.width
                                height: parent.height
                                color: "gold"
                            }
                        }
                    }

                    CellClicker {
                        grid: bGrid
                        linkEnabled: view === Enums.CellView.CommandButton
                        onDoCommand: {
                            txtInfo.text = 'Clicked: ' + command + ', ID: ' + ref1 + ', Year: ' + bGrid.cellValue(row,3)
                        }
                    }
                }
            }

            cellDelegate: cellDelegate

            fromListModel: modColumns

            onFetchPageRecords: {
                fillTable(false);
            }
        }
    }
}
