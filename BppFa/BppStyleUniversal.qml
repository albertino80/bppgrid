pragma Singleton

import QtQuick 2.12
import QtQuick.Controls.Universal 2.12

Item {
    id: thisStyle
    property int lightTheme: Universal.Light
    property int darkTheme: Universal.Dark
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
        if(thisStyle.whatTheme === thisStyle.lightTheme) {
            BppMetrics.windowBackground = "#E6E6E6"
            BppMetrics.windowBackgroundAlt = "#FFFFFF"
            BppMetrics.panelBackground = "#FAFAFA"
            BppMetrics.buttonBackground = "#33000000";
            BppMetrics.headingTextColor = "#15325C"
            BppMetrics.accentColor = Universal.color(Universal.Cobalt);
            BppMetrics.textColor = "#242424"
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
            BppMetrics.buttonBackground = "#33FFFFFF"
            BppMetrics.headingTextColor = "#FEFEFE"
            BppMetrics.accentColor = Universal.color(Universal.Cyan);
            BppMetrics.textColor = "#FCFCFC"
            BppMetrics.textColorDisabled = "#999999"

            BppMetrics.listItemOdd = BppMetrics.panelBackground
            BppMetrics.listItemEven = BppMetrics.windowBackgroundAlt
            BppMetrics.listItemSelOdd = "#0f1b6b"
            BppMetrics.listItemSelEven = "#101F70"
        }
    }
}
