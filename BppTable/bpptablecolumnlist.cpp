#include "bpptablecolumnlist.h"
#include <QQmlEngine>
#include <QSet>

namespace bpp {

    TableColumnList::TableColumnList(QObject *parent) : QObject(parent)
    {

    }

    TableColumnList::~TableColumnList()
    {
        clear();
    }

    void TableColumnList::registerQml()
    {
        qmlRegisterType<bpp::TableColumnList>("BppTableModel", 0, 1, "BTColList");
    }

    const QVector<int> TableColumnList::getSortColumns() const
    {
        QVector<int> sortColumns;

        int iCol(1);
        for(auto curColumn: def){
            int sortVal = curColumn->sortFlag;
            if(sortVal == 1)
                sortColumns.push_back(iCol);
            if(sortVal == 2)
                sortColumns.push_back(-iCol);
            iCol++;
        }

        return sortColumns;
    }

    void TableColumnList::clear()
    {
        for(auto col: def){
            delete col;
        }
        def.clear();
    }

    int TableColumnList::add()
    {
        int newCol(def.size());
        def.push_back( new TableColumn() );
        return newCol;
    }

    void TableColumnList::modifyColumn(int columnId, bool withDefaults, const QVariantMap &colDef)
    {
        def[columnId]->modify(colDef, withDefaults);
    }

    const TableColumn &TableColumnList::operator[](int columnId) const
    {
        return *def[columnId];
    }

    const TableColumn &TableColumnList::at(int columnId) const
    {
        return *def[columnId];
    }

    QVariantList TableColumnList::getColumnMap()
    {
        QVariantList records;
        QVariantMap currentRecord;

        for(auto col: def){
            currentRecord.clear();
            currentRecord.insert("title", col->title);
            currentRecord.insert("dataType", col->type);
            currentRecord.insert("sort", col->sortFlag);
            currentRecord.insert("action", col->action);
            currentRecord.insert("command", col->command);
            currentRecord.insert("width", col->width);
            currentRecord.insert("minWidth", col->minWidth);
            currentRecord.insert("role", col->role);
            records.append(currentRecord);
        }

        return records;
    }

    bool TableColumnList::resizeColumns(int theWidth)
    {
        if(def.size() == 0) return false;
        if(theWidth <= 0) return false;

        int minWidth = 0;
        QSet<int> toResize;

        for(int i=0; i < def.size(); i++){
            if(def[i]->minWidth) {
                toResize.insert(i);
                minWidth += def[i]->minWidth;
            }
        }

        if(toResize.isEmpty()) return false;

        int usedWidth = 0;
        for(int i=0; i < def.size(); i++){
            if(!toResize.contains(i)) {
                if(def[i]->width)
                    usedWidth += def[i]->width;
                else
                    usedWidth += 100;
            }
        }

        int newWidth = theWidth - usedWidth;
        if( newWidth < minWidth ) {
            //mantain min
            for(auto iCol: toResize)
                def[iCol]->width = def[iCol]->minWidth ;
        }
        else {
            double factor = double(newWidth) / double(minWidth);
            for(auto iCol: toResize)
                def[iCol]->width = int(floor(double(def[iCol]->minWidth) * factor)) ;
        }

        return true;
    }

    int TableColumnList::size() const
    {
        return def.size();
    }

    void TableColumnList::swapSort(int columnId)
    {
        int sortVal = def[columnId]->sortFlag;

        sortVal++;
        if(sortVal > 2) sortVal = 0;

        def[columnId]->sortFlag = sortVal;
    }

}
