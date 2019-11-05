#include "bpptablemodel.h"
#include <cfloat>
#include <QDebug>
#include <QQmlEngine>
#include <QSqlQuery>
#include <QSqlError>
#include <cmath>
#include <QDate>
#include <QDateTime>

#include "bpptableheading.h"

namespace bpp {

    TableModel::TableModel():
        dbRef(&emptyDbRef),
        dataSorted(false),
        highlightRow(-1)
    {
    }

    int TableModel::rowCount(const QModelIndex &) const
    {
        return dataVal.size();
    }

    int TableModel::columnCount(const QModelIndex &) const
    {
        return typeColumns.size();
    }

    QVariant TableModel::data(const QModelIndex &index, int role) const
    {
        switch (role) {
        case Qt::DisplayRole:
            //return QString("%1,%2,%3").arg(aPrefix).arg(index.column()).arg(index.row());
            {
                int whatRow = index.row();
                if(!dataIndex.isEmpty())
                    whatRow = dataIndex[whatRow];

                const QVariant& colVal = dataVal[whatRow][index.column()];
                switch (typeColumns[ index.column() ]) {
                case ColumnType::Str:
                    if(colVal.isNull()) return QVariant(QVariant::String);
                    else                return colVal.toString();
                case ColumnType::Dbl:
                    if(colVal.isNull()) return QVariant(QVariant::Double);
                    else                return colVal.toDouble();
                case ColumnType::Int:
                    if(colVal.isNull()) return QVariant(QVariant::Int);
                    else                return colVal.toInt();
                case ColumnType::Date:
                    if(colVal.isNull()) return QVariant(QVariant::Date);
                    else                return colVal.toDate();
                case ColumnType::DateTime:
                    if(colVal.isNull()) return QVariant(QVariant::DateTime);
                    else                return colVal.toDateTime();
                }
                return colVal.toString();
            }
        case roleDataType:
            return typeColumns[ index.column() ];
        case roleView:
            return actionColumns[ index.column() ];
        case roleCommand:
            return commandColumns[ index.column() ];
        case roleHighlight:
            if(index.row() == highlightRow)
                return true;
            return false;
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

                    switch (typeColumns[ iCol ]) {
                    case ColumnType::Str:
                        if(valA.toString().compare(valB.toString(), Qt::CaseInsensitive) == 0)
                            continue;
                        break;
                    case ColumnType::Dbl:
                        if( fabs(valA.toDouble() - valB.toDouble()) < double(FLT_EPSILON) )
                            continue;
                        break;
                    case ColumnType::Int:
                        if( valA.toInt() == valB.toInt() )
                            continue;
                        break;
                    case ColumnType::Date:
                        if( valA.toDate() == valB.toDate() )
                            continue;
                        break;
                    case ColumnType::DateTime:
                        if( valA.toDateTime() == valB.toDateTime() )
                            continue;
                        break;
                    }

                    if(orderAsc){
                        switch (typeColumns[ iCol ]) {
                        case ColumnType::Str:
                            return valA.toString().compare(valB.toString(), Qt::CaseInsensitive) < 0;
                        case ColumnType::Dbl:
                            return valA.toDouble() < valB.toDouble();
                        case ColumnType::Int:
                            return valA.toInt() < valB.toInt();
                        case ColumnType::Date:
                            return valA.toDate() < valB.toDate();
                        case ColumnType::DateTime:
                            return valA.toDateTime() < valB.toDateTime();
                        }
                    }
                    else {
                        switch (typeColumns[ iCol ]) {
                        case ColumnType::Str:
                            return valA.toString().compare(valB.toString(), Qt::CaseInsensitive) > 0;
                        case ColumnType::Dbl:
                            return valA.toDouble() > valB.toDouble();
                        case ColumnType::Int:
                            return valA.toInt() > valB.toInt();
                        case ColumnType::Date:
                            return valA.toDate() > valB.toDate();
                        case ColumnType::DateTime:
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

            while(query.next() && allOk) {

                dataVal.push_back(QVector<QVariant>());
                QVector<QVariant>& curRow = dataVal.last();

                for(int iCol = 0; iCol < typeColumns.size(); iCol++) {
                    appendDataVariant(curRow, query.value(iCol), typeColumns[iCol], DataDialect::Sqlite);
                }
            }

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

            for(int iCol = 0; iCol < typeColumns.size(); iCol++) {
                if(!curValues.contains(roleColumns[iCol]))
                    appendDataVariant(curRow, QVariant(QVariant::Int), typeColumns[iCol], DataDialect::JsonISO);
                else
                    appendDataVariant(curRow, curValues[roleColumns[iCol]], typeColumns[iCol], DataDialect::JsonISO);
            }
        }

        endReset();
        return allOk;
    }

    void TableModel::addRecord(const QList<QVariant>& theData)
    {
        int iCol;
        int numColumns( typeColumns.size() );

        dataVal.push_back(QVector<QVariant>());
        QVector<QVariant>& curRow = dataVal.last();
        iCol=0;
        for(auto& theValue: theData){
            appendDataVariant(curRow, theValue, typeColumns[iCol], DataDialect::JsonISO);
            iCol++;
        }

        while(iCol < numColumns) {
            appendDataVariant(curRow, QVariant(QVariant::Int), typeColumns[iCol], DataDialect::JsonISO);
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
        qmlRegisterType<bpp::TableModel>("BppTableModel", 0, 1, "BppTableModel");
        bpp::TableHeading::registerQml();
        bpp::TableDatabase::registerQml();
    }

    void TableModel::setDbRef(TableDatabase *value)
    {
        dbRef = value;
    }

    void TableModel::appendDataVariant(QVector<QVariant> &record, const QVariant &theValue, ColumnType columnType, DataDialect dia)
    {
        if(theValue.isNull())
            switch(columnType){
            case ColumnType::Str:
                record.push_back( QVariant(QVariant::String) );
                break;
            case ColumnType::Dbl:
                record.push_back( QVariant(QVariant::Double) );
                break;
            case ColumnType::Int:
                record.push_back( QVariant(QVariant::Int) );
                break;
            case ColumnType::Date:
                record.push_back( QVariant(QVariant::Date) );
                break;
            case ColumnType::DateTime:
                record.push_back( QVariant(QVariant::DateTime) );
                break;
            }
        else {
            switch(columnType){
            case ColumnType::Str:
                record.push_back( theValue.toString() );
                break;
            case ColumnType::Dbl:
                record.push_back( theValue.toDouble() );
                break;
            case ColumnType::Int:
                record.push_back( theValue.toInt() );
                break;
            case ColumnType::Date:
                if(dia == DataDialect::Sqlite)
                    record.push_back( QDate::fromString(theValue.toString(),"yyyy-MM-dd") );
                else if(dia == DataDialect::JsonISO)
                    record.push_back( QDate::fromString(theValue.toString(), Qt::ISODate) );
                else
                    record.push_back( theValue.toDate() );
                break;
            case ColumnType::DateTime:
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

    int TableModel::getHighlightRow() const
    {
        return highlightRow;
    }

    void TableModel::setSortColumns(const QVector<int> &value)
    {
        if(sortColumns != value) {
            sortColumns = value;
            dataSorted = false;
        }
    }

    void TableModel::setTypeColumns(const QVector<int> &value)
    {
        typeColumns.clear();
        for(auto iType: value){
            typeColumns.push_back( ColumnType(iType) );
        }
    }

    void TableModel::setActionColumns(const QVector<int> &value)
    {
        actionColumns = value;
    }

    void TableModel::setCommandColumns(const QVector<int> &value)
    {
        commandColumns = value;
    }

    void TableModel::setRoleColumns(const QVector<QString> &value)
    {
        roleColumns = value;
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
