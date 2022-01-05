# Table of Contents

* [simple](#simple)
* [simple_array](#simple_array)
* [simple_buttons](#simple_buttons)
* [fromDb](#fromDb)
* [multi_selection](#multi_selection)
* [color_grid](#color_grid)
* [with_json_cpp_be](#with_json_cpp_be)
* [pickdate](#pickdate)

# simple

very simple table, data loaded from Json

```
property var fruitList: [
        {pkid: 1, name: "Apple", cost: 2.45},
        {pkid: 2, name: "Orange", cost: 3.45},
        {pkid: 3, name: "Banana", cost: 1.459},
        {pkid: 4, name: "Strawberry", cost: 1.1467}
    ];
```

# simple_array

very simple table, data loaded from Js Array of records

```
[
	[1, "Apple", 2.45],
	[2, "Orange", 3.45],
	[3, "Banana", 1.459],
	[4, "Strawberry", 1.1467]
]
```

# simple_buttons

A  table with
* auto size column
* clickable cell
* custom cell content (a ProgressBar)

# fromDb

* ```MyDatabase``` is a SQLite example backend
  * is a simple Class derived from ```bpp::TableDatabase```
  * override ```bpp::TableDatabase::getDb()```: returns a QSqlDatabase used internally to fetch SQL data
* in this example SQLite Db is created in ```QStandardPaths::AppLocalDataLocation```
* fill table from a Db with SQL
* example of column header edit (change column text and visibility)

# multi_selection

* [Example](https://dev.bigno.it/bppgrid/multiselection.gif)
* work with multiselection
* multiselection mobile mode
* update cell content

# color_grid

* [Example](https://dev.bigno.it/bppgrid/color_grid.gif)
* Use some BppFa controls (BppPane, BppMsgBox, BppGrid, BppColorPickerDialog)
* Material theme, customizable

# with_json_cpp_be

* Use multiple grids on tabbed window
* GetData from cpp backend class

# pickdate

* Use of BppTextDate for date picking