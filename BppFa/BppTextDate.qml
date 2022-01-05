import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Item{
    id: container
//    implicitWidth: txtDate.implicitWidth + mouseSetDate.implicitWidth + 5
//    implicitHeight: Math.max(txtDate.implicitHeight, mouseSetDate.implicitHeight)
    width: 170
    height: BppMetrics.toolbarHeight

    property var dateSel: null
    property string dateFormat: "dd/MM/yyyy"
    property string placeholderText: qsTr("Sel. date")
    property alias fontSize: txtDate.font.pointSize

    signal dateChanged();

    function isNull(){
        return (dateSel === null);
    }

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
        container.dateChanged();

    }

    function fromTextFmt(aText, aFormat){
        if(aText && aText.length > 0)
            dateSel = Date.fromLocaleDateString(Qt.locale(), aText, aFormat);
        else
            dateSel = null;
        container.dateChanged();
    }

    Text {
        id: txtDate
        text: dateSel === null ? container.placeholderText : Qt.formatDate(dateSel, dateFormat)
        color: enabled
               ? (dateSel === null ? BppMetrics.textColorDisabled : BppMetrics.textColor)
               : BppMetrics.textColorDisabled
        font.pointSize: BppMetrics.fontSizePt
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: mouseSetDate.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        verticalAlignment: Text.AlignVCenter
    }

    BppToolButtonFa {
        id: mouseSetDate
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: mouseCancelDate.left
        width: 40
        text: Fa.fa_calendar
        ToolTip.text: qsTr("Set Date")
        onPressed: {
            calendarPopup.askDate(dateSel)
        }
    }

    BppToolButtonFa {
        id: mouseCancelDate
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 40
        text: Fa.fa_times
        ToolTip.text: qsTr("Cancel Date")
        onPressed: {
            dateSel = null;
            container.dateChanged();
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
                calendarPopup.close();
                container.dateChanged();
            }
        }
    }
}
