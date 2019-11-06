#include "bpptableheading.h"
#include <QQmlEngine>
#include <QDebug>

namespace bpp {

TableHeading::TableHeading(QObject *parent) :
    QObject(parent)
{

}

TableHeading::~TableHeading()
{
    clearColumnsDef();
}

int TableHeading::getColWidth(int columnId) const
{
    if(columnId<0)
        return 100;

    if(!columnsDef[columnId]->visible)
        return 0;

    return columnsDef[columnId]->width;
}

void TableHeading::clearColumnsDef()
{
    for(auto col: columnsDef){
        delete col;
    }
    columnsDef.clear();
}

int TableHeading::addColumnDef()
{
    int newCol(columnsDef.size());
    columnsDef.push_back( new TableColumn() );
    return newCol;
}

void TableHeading::setColumnDef(int columnId, bool withDefaults, const QVariantMap &colDef)
{
    columnsDef[columnId]->modify(colDef, withDefaults);
}

const TableColumn &TableHeading::getColumnDef(int columnId) const
{
    return *columnsDef[columnId];
}

int TableHeading::sizeColumnsDef() const
{
    return columnsDef.size();
}

void TableHeading::registerQml()
{
    qmlRegisterType<bpp::TableHeading>("BppTableModel", 0, 1, "BTHeading");
}

}
