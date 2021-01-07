pragma Singleton

import QtQuick 2.12

//All BppFa components depends on this metrics

Item {
    property int fontSizePt: Qt.application.font.pointSize;
    property int fontSizePtMedium: Qt.application.font.pointSize * 1.2
    property int fontSizePtBig: Qt.application.font.pointSize * 1.7
    property int fontSizeCommandIcons: Qt.application.font.pointSize * 1.3

    property int toolbarHeight: 48
    property int cellDataHeight: 30
    property int cellDataFontSizePt: Qt.application.font.pointSize;
    property int cellHeadingsHeight: 30
    property int cellHeadingsFontSizePt: Qt.application.font.pointSize

    property int elevation: 0

    property color panelBackground: "#FAFAFA"
    property color windowBackground: "#E6E6E6"
    property color windowBackgroundAlt: "#FFFFFF"
    property color buttonBackground: "#D6D7D7"
    property color accentColor: "#2196F3"
    property color textColor: "#000000"
    property color textColorDisabled: "#666666"
    property color headingTextColor: "#15325C"

    property color listItemOdd: "#FAFAFA"
    property color listItemEven: "#FFFFFF"
    property color listItemSelOdd: "#40ffa8"
    property color listItemSelEven: "#3df5a1"

    property font appFont: Qt.application.font
}
