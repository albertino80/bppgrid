import QtQuick 2.12
import BppTable 0.1


CompGrid {
    dataHeight: BppMetrics.cellDataHeight
    headingsHeight: BppMetrics.cellHeadingsHeight
    headingsFontSizePt: BppMetrics.cellHeadingsFontSizePt

    dataHighlight: BppMetrics.accentColor

    dataBkOdd: BppMetrics.listItemOdd
    dataBkEven: BppMetrics.listItemEven
    dataBkSelOdd: BppMetrics.listItemSelOdd
    dataBkSelEven: BppMetrics.listItemSelEven

    headingsBk: BppMetrics.windowBackground
    headingsBkAlt: BppMetrics.windowBackgroundAlt
    headingsLines: BppMetrics.buttonBackground

    headingsTextColor: BppMetrics.headingTextColor
    headingsSortColor: BppMetrics.headingTextColor
    disabledTextColor: BppMetrics.textColorDisabled

    fontButtonsPage: Fa.solid
    txtPageNext: Fa.fa_arrow_right
    txtPagePrev: Fa.fa_arrow_left
    txtPageLast: Fa.fa_step_forward
    txtPageFirst: Fa.fa_step_backward
}
