#include "bpptableheading.h"
#include <QQmlEngine>
#include <QDebug>

namespace bpp {

TableHeading::TableHeading(QObject *parent) : QObject(parent)
{

}

const QVariantList TableHeading::getColumns() const
{
    return theColumns;
}

void TableHeading::setColumns(const QVariantList &newColumns)
{
    theColumns.clear();
    int iCol(0);
    for(auto& newCol: newColumns){
        iCol++;
        QVariantMap aColumn = newCol.toMap();

        QVariantMap toInsertColumn = aColumn;
        if(!toInsertColumn.contains("width"))
            toInsertColumn["width"] = 100;
        if(!toInsertColumn.contains("title"))
            toInsertColumn["title"] = QString("Col %1").arg(iCol);
        if(!toInsertColumn.contains("sort"))
            toInsertColumn["sort"] = 0;
        if(!toInsertColumn.contains("dataType"))
            toInsertColumn["dataType"] = 0;
        if(!toInsertColumn.contains("view"))
            toInsertColumn["view"] = 0;
        if(!toInsertColumn.contains("command"))
            toInsertColumn["command"] = 0;
        if(!toInsertColumn.contains("role"))
            toInsertColumn["role"] = QString("col_%1").arg(iCol);

        theColumns.append(toInsertColumn);
    }

    emit columnsChanged();
}

void TableHeading::clickedOnColumn(int index)
{
    if(index < theColumns.size()){
        QVariantMap aColumn = theColumns[index].toMap();
        int sortVal = aColumn["sort"].toInt();

        sortVal++;
        if(sortVal > 2) sortVal = 0;

        aColumn["sort"] = sortVal;

        theColumns[index].setValue( aColumn );

        emit columnsChanged();
    }
}

const QVector<int> TableHeading::getSortColumns() const
{
    QVector<int> sortColumns;

    int iCol(1);
    for(auto& curColumn: theColumns){
        const QVariantMap& aColumn = curColumn.toMap();
        int sortVal = aColumn["sort"].toInt();
        if(sortVal == 1)
            sortColumns.push_back(iCol);
        if(sortVal == 2)
            sortColumns.push_back(-iCol);
        iCol++;
    }

    return sortColumns;
}

const QVector<int> TableHeading::getRoleColumns(const QString& roleName) const
{
    QVector<int> typeColumns;

    int iCol(0);
    for(auto& curColumn: theColumns){
        iCol++;
        const QVariantMap& aColumn = curColumn.toMap();
        typeColumns.push_back( aColumn[roleName].toInt() );
    }

    return typeColumns;
}

const QVector<QString> TableHeading::getRoleColumnsStr(const QString &roleName) const
{
    QVector<QString> typeColumns;

    int iCol(0);
    for(auto& curColumn: theColumns){
        iCol++;
        const QVariantMap& aColumn = curColumn.toMap();
        typeColumns.push_back( aColumn[roleName].toString() );
    }

    return typeColumns;
}

void TableHeading::registerQml()
{
    qmlRegisterType<bpp::TableHeading>("BppTableModel", 0, 1, "BppTableHeading");
}

}
