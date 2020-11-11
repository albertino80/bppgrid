# Changelog

## Version 1.2.0 (11 November 2020)
### Changed row selection indicator
Now, all selected row have a background color controlled by properties:
* `property color dataBkSelOdd`
* `property color dataBkSelEven`

### Add multiselection
[Example!](https://dev.bigno.it/bppgrid/multiselection.gif)

Multiselection can be enabled with
* `property bool withMultiselection`
  * false: multiselection not allowed
  * true: multiselection enabled
* `property bool withMultiselectionMobileMode`
  * false: use CTRL ans SHIFT keyboard modifiers for multiselect
  * true: act as CTRL is always pressed

If multiselection is enabled `withMultiselection=true` then a new bar under columns is visible, `select all none`

*WARNING* Deprecated function `getCellBackground(row)` now use: `getCellBk(row, highlight)`

## Version 1.1.0 (9 April 2020)
### Add option button on grid
This button can be disabled see `showOptionsButton`

### Add resize on columns with mobile friendly UI
Resize can be activated from:
* option button, choose *tap on column* behaviour then tap on column header
* right click on column header (used in desktop)
* press and hold on column header (used on mobile)

### Add copy row option
Select a table row, then press option button

## Verision 1.0.0
First version