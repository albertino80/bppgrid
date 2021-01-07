#include "bpptablecolumn.h"
#include <QQmlEngine>

namespace bpp {

    TableColumn::TableColumn(QObject *parent) :
        QObject(parent),
        type(Str),
        view(0),
        sortFlag(0),
        action(0),
        command(0),
        width(0),
        minWidth(0),
        visible(true),
        reference1(-1)
    {

    }

    void TableColumn::registerQml()
    {
        //qmlRegisterType<bpp::TableColumn>("BppTableModel", 0, 1, "BTColumn");
        qmlRegisterType<bpp::TableColumn>("BppTable", 0, 1, "BTColumn");
    }

    void TableColumn::modify(const QVariantMap &colDef, bool withDefaults)
    {
        if(!colDef.contains("width")){
            if(withDefaults) width = 100;
        }
        else
        {
            width = colDef["width"].toInt();
        }
        if(width == 0) width = 100;

        if(!colDef.contains("minWidth")){
            if(withDefaults) minWidth = 0;
        }
        else
            minWidth = colDef["minWidth"].toInt();

        if(!colDef.contains("title")){
            if(withDefaults) title = "";
        }
        else
            title = colDef["title"].toString();

        if(!colDef.contains("sort")){
            if(withDefaults) sortFlag = 0;
        }
        else
            sortFlag = colDef["sort"].toInt();

        if(!colDef.contains("dataType")){
            if(withDefaults) type = Str;
        }
        else
            type = ColumnType( colDef["dataType"].toInt() );

        if(!colDef.contains("view")){
            if(withDefaults) view = 0;
        }
        else
            view = colDef["view"].toInt();

        if(!colDef.contains("command")){
            if(withDefaults) command = 0;
        }
        else
            command = colDef["command"].toInt();

        if(!colDef.contains("role")){
            if(withDefaults) role = "";
        }
        else
            role = colDef["role"].toString();

        if(!colDef.contains("visible")){
            if(withDefaults) visible = true;
        }
        else
            visible = colDef["visible"].toBool();

        if(!colDef.contains("dataRef1")){
            if(withDefaults) dataRef1.clear();
        }
        else
            dataRef1 = colDef["dataRef1"].toString();
    }

}
