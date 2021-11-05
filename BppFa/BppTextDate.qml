import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item {
    id: container
    implicitWidth: txtDate.implicitWidth + mouseSetDate.implicitWidth + 5
    implicitHeight: Math.max(txtDate.implicitHeight, mouseSetDate.implicitHeight)

    //property date dateSel: new Date()
    property var dateSel: null
    property string dateFormat: "dd/MM/yyyy"
    property string placeholderText: "Sel. data"
    property alias fontSize: txtDate.font.pointSize
    //property alias enabled: mouseSetDate.enabled

    signal dateChanged();

    function toText(){
        if(dateSel === null)
            return ""
        else
            return Qt.formatDate(dateSel, "yyyyMMdd")
    }

    function toTextFmt(aFormat){
        if(dateSel === null)
            return ""
        else
            return Qt.formatDate(dateSel, aFormat)
    }

    function fromText(aText){
        if(aText.length > 0)
            dateSel = Date.fromLocaleDateString(Qt.locale(), aText, "yyyyMMdd");
        else
            dateSel = null;

    }

    function fromTextFmt(aText, aFormat){
        if(aText && aText.length > 0)
            dateSel = Date.fromLocaleDateString(Qt.locale(), aText, aFormat);
        else
            dateSel = null;
    }

    RowLayout{
        anchors.fill: parent
        spacing: 0

        Text {
            id: txtDate
            text: dateSel === null ? container.placeholderText : Qt.formatDate(dateSel, dateFormat)
            color: enabled
                   ? (dateSel === null ? BppMetrics.textColorDisabled : BppMetrics.textColor)
                   : BppMetrics.textColorDisabled
            font.pointSize: BppMetrics.fontSizePt
            //Layout.fillWidth: true
        }

        BppToolButtonFa {
            id: mouseSetDate
            text: Fa.fa_calendar
            ToolTip.text: qsTr("Set Date")
            onPressed: {
                calendarPopup.askDate(dateSel)
            }
        }

        BppToolButtonFa {
            text: Fa.fa_times
            ToolTip.text: qsTr("Cancel Date")
            //enabled: mouseSetDate.enabled
            onPressed: {
                dateSel = null;
                container.dateChanged();
            }
        }

        Item {
            Layout.fillWidth: true
        }
    }

    Popup {
        id: calendarPopup
        property int taskId: -1

        anchors.centerIn: parent
        width: 400
        height: 400
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        padding: 0
        margins: 0

//        contentItem: BppCalendar {
//            id: calendarView

//            clip: true
//            //year: 2019
//            //month: (new Date()).getMonth()
//            //date: dateSel

//            onDateSelect: {
//                dateSel = newDate;
//                //txt.text = dateSel;
//                calendarPopup.close();
//                container.dateChanged();
//            }
//        }

//        function askDate(theStartDate){
//            if(theStartDate === null)
//                calendarView.date = new Date()
//            else
//                calendarView.date = theStartDate
//            calendarView.resetBindings();
//            calendarPopup.open();
//        }

        function askDate(theStartDate){
            loaderCalendar.sourceComponent = calendarComp
            if(theStartDate === null)
                loaderCalendar.item.date = new Date()
            else
                loaderCalendar.item.date = theStartDate
            loaderCalendar.item.resetBindings();
            calendarPopup.open();
        }

        Component {
            id: calendarComp
            BppCalendar {
                clip: true
            }
        }

        Loader {
            id: loaderCalendar
            anchors.fill: parent
        }

        Connections {
            target: loaderCalendar.item
            onDateSelect: {
                dateSel = newDate;
                //txt.text = dateSel;
                calendarPopup.close();
                container.dateChanged();
            }
        }
    }
}
