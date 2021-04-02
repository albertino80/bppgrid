import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import Qt.labs.calendar 1.0

Item {
    id: control

    property date date: new Date()
    property int month
    property int year
    property bool dateSelected: false
    property bool mobileMode: false

    // Own signal emitted to preserve date binding.
    signal dateSelect(date newDate)

    anchors.fill: parent
    //width: gridLayout.width // + 24
    //height: dayBox.height + buttonLayout.height + gridLayout.height + 16

    function resetBindings() {
        month = date.getMonth();
        year = date.getFullYear();
    }

    function sameDates(date1, date2) {
        return (date1.getDate() === date2.getDate())
                && (date1.getMonth() === date2.getMonth())
                && (date1.getFullYear() === date2.getFullYear());
    }

    function goBackward() {
        if (month == 0) {
            month = 11;
            year = year - 1;
        } else {
            month--;
        }
    }

    function goForward() {
        if (month == 11) {
            month = 0;
            year = year + 1;
        } else {
            month++;
        }
    }

    function firstOfMonth(month) {
        var date = new Date(2018, month, 1)
        return date;
    }

    function monthName(month) {
        return firstOfMonth(month).toLocaleString(grid.locale, "MMMM")
    }

    ColumnLayout {
        id: mainColumn
        anchors.fill: parent
        anchors.margins: 2

        Rectangle {
            id: dayBox
            //width: parent.width
            Layout.fillWidth: true
            height: 50
            color: BppMetrics.windowBackgroundAlt

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 0

                Label {
                    text: date.toLocaleString(Qt.locale(), "ddd d MMMM")
                    color: BppMetrics.accentColor
                    font.pixelSize: BppMetrics.fontSizePtBig
                    font.bold: true
                    //font.family: "Roboto Regular"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    Layout.fillWidth: true
                }

                Label {
                    text: date.getFullYear()
                    color: BppMetrics.textColor
                    font.pixelSize: BppMetrics.fontSizePtMedium
                    font.bold: true
                    //font.family: "Roboto Regular"
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

        RowLayout {
            id: buttonLayout
            Layout.fillWidth: true

            BppToolButtonFa {
                text: Fa.fa_chevron_left
                ToolTip.text: qsTr("Indietro")
                onPressed: {
                    goBackward()
                }
            }

            Label {
                text: monthName(month)
                font.bold: true
                font.pointSize: BppMetrics.fontSizePtMedium
                //font.family: "Roboto Condensed"
                Layout.minimumWidth: 100
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            BppToolButtonFa {
                text: Fa.fa_chevron_right
                ToolTip.text: qsTr("Avanti")
                onPressed: {
                    goForward()
                }
            }

            Item{
                Layout.fillWidth: true
            }

            BppToolButtonFa {
                text: Fa.fa_chevron_left
                ToolTip.text: qsTr("Indietro")
                onPressed: {
                    year--
                }
            }

            Label {
                text: year
                font.bold: true
                font.pointSize: BppMetrics.fontSizePtMedium
                Layout.minimumWidth: 70
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            BppToolButtonFa {
                text: Fa.fa_chevron_right
                ToolTip.text: qsTr("Indietro")
                onPressed: {
                    year++
                }
            }
        }

        GridLayout {
            id: gridLayout
            columns: 1//2
            rowSpacing: 0
            columnSpacing: rowSpacing
            Layout.fillWidth: true
            Layout.fillHeight: true

            //Item { width: weekNumberColumn.width; height: width}

            DayOfWeekRow {
                Layout.fillWidth: true
                //height: 30
                //spacing: grid.spacing
                locale: grid.locale
                delegate: Text {
                    //font.family: "Roboto Condensed"
                    text: model.narrowName
                    color: BppMetrics.accentColor
                    font.pointSize: BppMetrics.fontSizePt
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            /*
            WeekNumberColumn {
                id: weekNumberColumn
                month: grid.month
                year: grid.year
                locale: grid.locale
                Layout.fillHeight: true
                spacing: grid.spacing
                delegate: Text {
                    text: model.weekNumber
                    color: Material.accent
                    font.family: "Roboto Condensed"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }
            }
            */

            MonthGrid {
                id: grid
                month: control.month
                year: control.year
                Layout.fillHeight: true
                Layout.fillWidth: true
                spacing: 0
                delegate: Rectangle {
                    property bool checked: sameDates(control.date, model.date)
                    //width: 36
                    //height: width
                    //anchors.margins: 0
                    radius: 30
                    color: {
                        if(checked)
                            return BppMetrics.accentColor
                        else if(model.today)
                            return BppMetrics.listItemSelOdd
                        else
                            return "transparent"
                    }

                    Label {
                        anchors.centerIn: parent
                        text: model.day
                        //font.family: "Roboto Condensed"
                        height: width
                        color: {
//                            if (parent.checked)
//                                return BppMetrics.textColor;
//                            else if (model.today)
//                                return BppMetrics.accentColor
//                            else
                            if (model.date.getMonth() !== control.month)
                                return BppMetrics.textColorDisabled//Material.color(Material.Grey, Material.Shade400)
                            else
                                return BppMetrics.textColor;
                        }
                        font.pointSize: BppMetrics.fontSizePtMedium
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            //if (!checked) {
                                control.dateSelect(model.date)
                                dateSelected = true;
                            //}
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        resetBindings();
    }
}
