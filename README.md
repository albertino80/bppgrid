
# bppgrid
QtQuick 2 Table component, modeled on TableView QML Type

Tested on Windows, Android 6+, may work on other plaftorms

Developed with Qt 5.12.3

![Image of bppgrid](examples/bppgrid.png)

### How to start a new project

* in your project **.pro** add :
```
include($$PWD/bppgrid/BppTable.pri)
include($$PWD/bppgrid/BppFa.pri) #only if you plan to use FontAwesome 5 Icons
```
* in **main.cpp** call
```
bpp::TableModel::registerQml()
bpp::FontAwesome::registerQml(engine); //Optional
engine.addImportPath("qrc:/")
```
Example:
```
#include <bpptablemodel.h>
#include <bppfontawesome.h> //Optional

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
...
    bpp::TableModel::registerQml();
    bpp::FontAwesome::registerQml(engine); //Optional
    engine.addImportPath("qrc:/");
...
}
```

* in qml file add imports
```
import BppTableModel 0.1
import BppTable 0.1
```

* Use it!

### Example QML
```
import QtQuick 2.13
import QtQuick.Window 2.13
import BppTableModel 0.1
import BppTable 0.1

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var fruitList: [
        {pkid: 1, name: "Apple", cost: 2.45},
        {pkid: 2, name: "Orange", cost: 3.45},
        {pkid: 3, name: "Banana", cost: 1.459},
        {pkid: 4, name: "Strawberry", cost: 1.1467}
    ];

    CompGrid {
        id: bGrid
        anchors.fill: parent
        anchors.margins: 10

        dataHeight: 30

        Component {
            id: cellItem

            Rectangle {
                implicitHeight: bGrid.dataHeight
                color: bGrid.getCellBackground(row)

                CellText {
                    text: bGrid.formatDisplay(display, dataType, 2)
                    horizontalAlignment: bGrid.getAlign(dataType)
                }

                CellSeparator{
                    color: bGrid.dataLines
                }

                CellClicker {
                    grid: bGrid
                }
            }
        }

        cellDelegate: cellItem

        fromArray: [
            { role: "pkid", title: "ID", dataType: BTColumn.Int },
            { role: "name", title: "Name", minWidth: 100 },
            { role: "cost", title: "Cost", dataType: BTColumn.Dbl }
         ]
    }

    Component.onCompleted: {
        bGrid.fillFromJson(fruitList);
    }
}
```

### Examples folder content

* Component preview: [bppgrid_preview.gif](examples/bppgrid_preview.gif)
* **simple**: very simple table, data loaded from Json
* **simple_array**: very simple table, data loaded from Js Array of records
* **simple_buttons**: 
  * auto size column
  * clickable cell
  * custom cell content (a ProgressBar)
* **fromDb**:
  * ```MyDatabase``` is a SQLite example backend
    * is a simple Class derived from ```bpp::TableDatabase```
    * override ```bpp::TableDatabase::getDb()```: returns a QSqlDatabase used internally to fetch SQL data
  * in this example SQLite Db is created in ```QStandardPaths::AppLocalDataLocation```
  * fill table from a Db with SQL
  * example Date/DateTime column
  * example of column edit (change column text and visibility)

### Features
TODO: write list

### Todo
- [ ] Parametrize project for avoid ```QT += sql``` if not needed
- [ ] Test other database drivers
- [ ] Column reordering (Study a mobile friendly interface)
- [ ] Documentation, developer guide
