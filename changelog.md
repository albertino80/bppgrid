# Changelog

## Version 1.4.0 (8 May 2021)

### Added New TreeView Control 
TODO: Write documentation and an example

### Added New example with_json_cpp_be
* Use multiple grids on tabbed window
* GetData from cpp backend class

## Version 1.3.0 (7 January 2021)

### Changed column resize and ordering, more mobile friendly
Now clicking on a column title, an indicator will appear to resize and reorder the column. By clicking again, the indicator will disappear

### Removed qml namespace BppTableModel
No more `import BppTableModel 0.1` needed

### Extended BppFa project with some related controls 
[Example](https://dev.bigno.it/bppgrid/color_grid.gif)

## Version 1.2.0 (11 November 2020)

### Changed row selection indicator
Now, all selected row have a background color controlled by properties:
* `property color dataBkSelOdd`
* `property color dataBkSelEven`

### Add multiselection
[Example](https://dev.bigno.it/bppgrid/multiselection.gif)

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
