pragma Singleton

import QtQuick 2.0
import QtQuick.Controls.Material 2.12

Item {
    id: thisStyle
    property int lightTheme: Material.Light
    property int darkTheme: Material.Dark
    property int whatTheme: lightTheme
    property var prepareColorsCallback: prepareColors

    onWhatThemeChanged: {
        prepareColorsCallback();
    }

    Component.onCompleted: {
        prepareColorsCallback();
    }

    function setInitFunction(cbackFunz) {
        prepareColorsCallback = cbackFunz;
        prepareColorsCallback();
    }

    function setMode(goLight){
        if(goLight)
            thisStyle.whatTheme = thisStyle.lightTheme;
        else
            thisStyle.whatTheme = thisStyle.darkTheme;
    }

    function prepareColors() {
        BppMetrics.elevation = 2
        if(thisStyle.whatTheme === thisStyle.lightTheme) {
            BppMetrics.windowBackground = "#E6E6E6"
            BppMetrics.windowBackgroundAlt = "#FFFFFF"
            BppMetrics.panelBackground = "#FAFAFA"
            BppMetrics.buttonBackground = "#D6D7D7"
            BppMetrics.headingTextColor = "#15325C"
            BppMetrics.accentColor = Material.color(Material.Blue); //"#2196F3" //Material.Indigo
            BppMetrics.textColor = "#000000"
            BppMetrics.textColorDisabled = "#666666"

            BppMetrics.listItemOdd = BppMetrics.panelBackground
            BppMetrics.listItemEven = BppMetrics.windowBackgroundAlt
            BppMetrics.listItemSelOdd = "#40ffa8"
            BppMetrics.listItemSelEven = "#3df5a1"
        }
        else {
            BppMetrics.windowBackground = "#303030"
            BppMetrics.windowBackgroundAlt = "#151515"
            BppMetrics.panelBackground = "#1E1E1E"
            BppMetrics.buttonBackground = "#404040";
            BppMetrics.headingTextColor = "#FEFEFE"
            BppMetrics.accentColor = Material.color(Material.Cyan); //"#80DEEA" //Material.Cyan
            BppMetrics.textColor = "#FFFFFF"
            BppMetrics.textColorDisabled = "#999999"

            BppMetrics.listItemOdd = BppMetrics.panelBackground
            BppMetrics.listItemEven = BppMetrics.windowBackgroundAlt
            BppMetrics.listItemSelOdd = "#0f1b6b"
            BppMetrics.listItemSelEven = "#101F70"
        }
    }
}
