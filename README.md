# bppgrid
QtQuick 2 Table component, modeled on TableView QML Type

Tested on Windows, Android 6+, may work on other plaftorms

### How to start a new project

* in (your) **project.pro** include pri:
```include($$PWD/../../bppgrid/bppgrid.pri)```
* in **main.cpp** register qml types:
```
#include <bpptablemodel.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

...

    bpp::TableModel::registerQml();

...
}
```
* Use it!

### Examples folder content

* Component preview: [bppgrid_preview.gif](examples/bppgrid_preview.gif)
* **simple**: very simple table
