#include "bpptablemodel.h"
#include <cfloat>
#include <QDebug>
#include <QQmlEngine>
#include <QSqlQuery>
#include <QSqlError>
#include <cmath>
#include <QDate>
#include <QDateTime>

namespace bpp {

    TableModel::TableModel():
        dbRef(&emptyDbRef),
        dataSorted(false),
        highlightRow(-1)
    {
    }

    TableModel::~TableModel()
    {
        clearColumnsDef();
    }

    int TableModel::rowCount(const QModelIndex &) const
    {
        return dataVal.size();
    }

    int TableModel::columnCount(const QModelIndex &) const
    {
        return columnsDef.size();
    }

    QVariant TableModel::data(const QModelIndex &cellIndex, int role) const
    {
        const TableColumn &cdef = getColumnDef( cellIndex.column() );

        switch (role) {
        case Qt::DisplayRole:
            return getDataDisplayRole(cellIndex);
        case roleDataType:
            return cdef.type;
        case roleView:
            return cdef.view;
        case roleCommand:
            return cdef.command;
        case roleHighlight:
            if(cellIndex.row() == highlightRow)
                return true;
            return false;
        case roleVisible:
            return cdef.visible;
        case roleRef1:
            {
                int reference = cdef.reference1;
                if(reference >= 0)
                    return getDataDisplayRole( QModelIndex( index(cellIndex.row(), reference) ) );
                else
                    return QString("");
            }
        default:
            break;
        }

        return QVariant();
    }

    //https://doc.qt.io/qt-5/qt.html#ItemDataRole-enum
    QHash<int, QByteArray> TableModel::roleNames() const
    {
        return {
            {Qt::DisplayRole, "display"},
            {roleDataType, "dataType"},
            {roleView, "view"},
            {roleCommand, "command"},
            {roleHighlight, "highlight"},
            {roleVisible, "visible"},
            {roleRef1, "ref1"}
        };
    }

    void TableModel::sortData()
    {
        if(!dataSorted) {
            if(sortColumns.isEmpty()) {
                if(dataIndex.isEmpty()) {
                    //nothing to do
                    dataSorted = true;
                }
                else {
                    emit beginResetModel();
                    dataIndex.clear();
                    dataSorted = true;
                    emit endResetModel();
                }
                return;
            }

            if(dataVal.isEmpty()) {
                //nothing to do
                dataSorted = true;
                return;
            }

            dataIndex.fill(0, dataVal.size());
            std::iota(dataIndex.begin(), dataIndex.end(), 0);

            QVector< QPair<int,bool> > sortIndexes;
            for(auto sortCol: sortColumns) {
                bool orderAsc(true);
                int iCol = sortCol;
                if(iCol < 0) {
                    orderAsc = false;
                    iCol = -iCol;
                }

                //-1 because sortColumns value starts from 1 for the first column
                sortIndexes.push_back( QPair<int,bool>(iCol - 1, orderAsc) );
            }

            emit beginResetModel();
            std::sort(dataIndex.begin(), dataIndex.end(), [&](int indexA, int indexB) {

                const QVector<QVariant>& recordA = dataVal[indexA];
                const QVector<QVariant>& recordB = dataVal[indexB];
                for(auto sortCol: sortIndexes) {
                    bool orderAsc(sortCol.second);
                    int iCol(sortCol.first);

                    const QVariant& valA = recordA[iCol];
                    const QVariant& valB = recordB[iCol];

                    if(valA.isNull() && !valB.isNull())
                        return orderAsc;
                    if(valB.isNull() && !valA.isNull())
                        return !orderAsc;

                    switch (getColumnDef( iCol ).type) {
                    case TableColumn::Str:
                        if(valA.toString().compare(valB.toString(), Qt::CaseInsensitive) == 0)
                            continue;
                        break;
                    case TableColumn::Dbl:
                        if( fabs(valA.toDouble() - valB.toDouble()) < double(FLT_EPSILON) )
                            continue;
                        break;
                    case TableColumn::Int:
                        if( valA.toInt() == valB.toInt() )
                            continue;
                        break;
                    case TableColumn::Date:
                        if( valA.toDate() == valB.toDate() )
                            continue;
                        break;
                    case TableColumn::DateTime:
                        if( valA.toDateTime() == valB.toDateTime() )
                            continue;
                        break;
                    }

                    if(orderAsc){
                        switch (getColumnDef( iCol ).type) {
                        case TableColumn::Str:
                            return valA.toString().compare(valB.toString(), Qt::CaseInsensitive) < 0;
                        case TableColumn::Dbl:
                            return valA.toDouble() < valB.toDouble();
                        case TableColumn::Int:
                            return valA.toInt() < valB.toInt();
                        case TableColumn::Date:
                            return valA.toDate() < valB.toDate();
                        case TableColumn::DateTime:
                            return valA.toDateTime() < valB.toDateTime();
                        }
                    }
                    else {
                        switch (getColumnDef( iCol ).type) {
                        case TableColumn::Str:
                            return valA.toString().compare(valB.toString(), Qt::CaseInsensitive) > 0;
                        case TableColumn::Dbl:
                            return valA.toDouble() > valB.toDouble();
                        case TableColumn::Int:
                            return valA.toInt() > valB.toInt();
                        case TableColumn::Date:
                            return valA.toDate() > valB.toDate();
                        case TableColumn::DateTime:
                            return valA.toDateTime() > valB.toDateTime();
                        }
                    }
                }
                return false;
            });
            dataSorted = true;

            emit endResetModel();
        }
    }

    void TableModel::beginReset()
    {
        emit beginResetModel();
        setHighlightRow(-1);
        dataVal.clear();
        dataIndex.clear();
    }

    void TableModel::endReset()
    {
        emit endResetModel();
        sortData();
    }

    bool TableModel::addFromQuery(const QString &theSqlQuery, const QList<QVariant>& parameters)
    {
        if(!dbRef->getDb()) {
            qDebug() << "No database";
            return false;
        }

        QSqlQuery query(*dbRef->getDb());
        query.setForwardOnly(true);

        if(!query.prepare(theSqlQuery)){
            qDebug() << "Error querying the db" << query.lastError().text();
            return false;
        }

        if(!parameters.isEmpty()) {
            for(auto& curParam: parameters) {
                query.addBindValue(curParam);
            }
        }

        bool allOk(true);
        if(query.exec()) {

            beginReset();

            dataVal.reserve(100);
            int nCols = columnsDef.size();
            while(query.next() && allOk) {
                dataVal.push_back(QVector<QVariant>());
                QVector<QVariant>& curRow = dataVal.last();
                curRow.reserve( nCols );

                for(int iCol = 0; iCol < nCols; iCol++) {
                    if(getColumnDef( iCol ).reference1 < 0)
                        appendDataVariant(curRow, query.value(iCol), getColumnDef( iCol ).type, DataDialect::Sqlite);
                    else
                        appendDataVariant(curRow, emptyVInt, getColumnDef( iCol ).type, DataDialect::JsonISO);
                }
            }
            dataVal.shrink_to_fit();

            if(query.lastError().isValid())
            {
                allOk = false;
                qDebug() << "Error querying the db" << query.lastError().text();
            }
            query.finish();

            endReset();
        }

        return allOk;
    }

    bool TableModel::addFromList(const QVariantList &values)
    {
        bool allOk(true);
        beginReset();

        for(auto& curRecord: values){
            const QVariantMap& curValues = curRecord.toMap();

            dataVal.push_back(QVector<QVariant>());
            QVector<QVariant>& curRow = dataVal.last();

            for(int iCol = 0; iCol < columnsDef.size(); iCol++) {
                if(!curValues.contains(getColumnDef( iCol ).role))
                    appendDataVariant(curRow, emptyVInt, getColumnDef( iCol ).type, DataDialect::JsonISO);
                else
                    appendDataVariant(curRow, curValues[getColumnDef( iCol ).role], getColumnDef( iCol ).type, DataDialect::JsonISO);
            }
        }

        endReset();
        return allOk;
    }

    void TableModel::addRecord(const QList<QVariant>& theData)
    {
        int iCol;
        int numColumns( columnsDef.size() );

        dataVal.push_back(QVector<QVariant>());
        QVector<QVariant>& curRow = dataVal.last();
        iCol=0;
        for(auto& theValue: theData){
            if(getColumnDef( iCol ).reference1 < 0)
                appendDataVariant(curRow, theValue, getColumnDef( iCol ).type, DataDialect::JsonISO);
            else
                appendDataVariant(curRow, emptyVInt, getColumnDef( iCol ).type, DataDialect::JsonISO);
            iCol++;
        }

        while(iCol < numColumns) {
            appendDataVariant(curRow, QVariant(QVariant::Int), getColumnDef( iCol ).type, DataDialect::JsonISO);
            iCol++;
        }
    }

    void TableModel::updateLayout()
    {
        emit layoutChanged();
        sortData();
    }

    void TableModel::registerQml()
    {
        qmlRegisterType<bpp::TableModel>("BppTableModel", 0, 1, "BTModel");
        bpp::TableDatabase::registerQml();
        bpp::TableColumn::registerQml();
    }

    void TableModel::setDbRef(TableDatabase *value)
    {
        dbRef = value;
    }

    void TableModel::endUpdateColumns()
    {
        calcReferenceColumns();
        calcSortColumns();
        updateLayout();
    }

    bool TableModel::canHideColumns()
    {
        #if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
            return true;
        #else
            return false;
        #endif
    }

    int TableModel::getColWidth(int columnId) const
    {
        int theW(0);
        if(columnId<0)
            theW = 100;
        else if(columnsDef[columnId]->visible)
            theW = columnsDef[columnId]->width;

        return theW;
    }

    void TableModel::clearColumnsDef()
    {
        for(auto col: columnsDef){
            delete col;
        }
        columnsDef.clear();
    }

    int TableModel::addColumnDef()
    {
        int newCol(columnsDef.size());
        columnsDef.push_back( new TableColumn() );
        return newCol;
    }

    void TableModel::setColumnDef(int columnId, bool withDefaults, const QVariantMap &colDef)
    {
        columnsDef[columnId]->modify(colDef, withDefaults);
    }

    const TableColumn &TableModel::getColumnDef(int columnId) const
    {
        return *columnsDef[columnId];
    }

    void TableModel::appendDataVariant(QVector<QVariant> &record, const QVariant &theValue, TableColumn::ColumnType columnType, DataDialect dia)
    {
        if(theValue.isNull())
            switch(columnType){
            case TableColumn::Str:
                record.push_back( emptyVString );
                break;
            case TableColumn::Dbl:
                record.push_back( emptyVDouble );
                break;
            case TableColumn::Int:
                record.push_back( emptyVInt );
                break;
            case TableColumn::Date:
                record.push_back( emptyVDate );
                break;
            case TableColumn::DateTime:
                record.push_back( emptyVDateTime );
                break;
            }
        else {
            switch(columnType){
            case TableColumn::Str:
                record.push_back( theValue.toString() );
                break;
            case TableColumn::Dbl:
                record.push_back( theValue.toDouble() );
                break;
            case TableColumn::Int:
                record.push_back( theValue.toInt() );
                break;
            case TableColumn::Date:
                if(dia == DataDialect::Sqlite)
                    record.push_back( QDate::fromString(theValue.toString(),"yyyy-MM-dd") );
                else if(dia == DataDialect::JsonISO)
                    record.push_back( QDate::fromString(theValue.toString(), Qt::ISODate) );
                else
                    record.push_back( theValue.toDate() );
                break;
            case TableColumn::DateTime:
                if(dia == DataDialect::Sqlite)
                    record.push_back( QDateTime::fromString(theValue.toString(),"yyyy-MM-dd HH:mm:ss") );
                else if(dia == DataDialect::JsonISO)
                    record.push_back( QDateTime::fromString(theValue.toString(), Qt::ISODate) );
                else
                    record.push_back( theValue.toDateTime() );
                break;
            }
        }
    }

    void TableModel::calcSortColumns()
    {
        sortColumns.clear();
        dataSorted = false;

        for(int i = 0; i < columnsDef.size(); i++){
            int sortVal = getColumnDef(i).sortFlag;
            if(sortVal == 1)
                sortColumns.push_back(i+1);
            if(sortVal == 2)
                sortColumns.push_back(-(i+1));
        }
    }

    void TableModel::calcReferenceColumns()
    {
        for(int iColumn = 0; iColumn < columnsDef.size(); iColumn++){
            TableColumn* currentColumn = columnsDef[iColumn];
            if(currentColumn->dataRef1.isEmpty())
                currentColumn->reference1 = -1;
            else {
                currentColumn->reference1 = -1;
                for(int iSeek = 0; iSeek < columnsDef.size() && currentColumn->reference1 == -1; iSeek++){
                    TableColumn* seekColumn = columnsDef[iSeek];
                    if(!seekColumn->role.isEmpty() && currentColumn->dataRef1.compare(seekColumn->role) == 0){
                        currentColumn->reference1 = iSeek;
                    }
                }
            }
        }
    }

    QVariant TableModel::getDataDisplayRole(const QModelIndex &index) const
    {
        int whatRow = index.row();
        if(!dataIndex.isEmpty())
            whatRow = dataIndex[whatRow];

        const QVariant& colVal = dataVal[whatRow][index.column()];
        switch ( getColumnDef( index.column() ).type) {
        case TableColumn::Str:
            if(colVal.isNull()) return QVariant(QVariant::String);
            else                return colVal.toString();
        case TableColumn::Dbl:
            if(colVal.isNull()) return QVariant(QVariant::Double);
            else                return colVal.toDouble();
        case TableColumn::Int:
            if(colVal.isNull()) return QVariant(QVariant::Int);
            else                return colVal.toInt();
        case TableColumn::Date:
            if(colVal.isNull()) return QVariant(QVariant::Date);
            else                return colVal.toDate();
        case TableColumn::DateTime:
            if(colVal.isNull()) return QVariant(QVariant::DateTime);
            else                return colVal.toDateTime();
        }
        return colVal.toString();
    }

    int TableModel::getHighlightRow() const
    {
        return highlightRow;
    }

    void TableModel::dataNeedSort()
    {
        dataSorted = false;
    }

    void TableModel::setHighlightRow(int rowNum)
    {
        if(highlightRow != rowNum) {
            highlightRow = rowNum;
            emit highlightRowChanged();
        }

        /*
        QList<QPersistentModelIndex> cells;
        for(int i = 0; i < columnCount(QModelIndex()); i++){
            cells.append( QModelIndex(index(rowNum, i)) );
        }

        emit layoutChanged(cells);
        */
    }

}
