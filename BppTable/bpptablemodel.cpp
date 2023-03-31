#include "bpptablemodel.h"
#include <cfloat>
#include <QDebug>
#include <QQmlEngine>
#include <QSqlQuery>
#include <QSqlError>
#include <cmath>
#include <QDate>
#include <QDateTime>

#include <QClipboard>
#include <QGuiApplication>

namespace bpp {

    TableModel::TableModel():
        dbRef(&emptyDbRef),
        dataChangedALS(false),
        columnsChangedALS(false),
        sortedChangedALS(false),
        highlightRow(-1),
        lastHighlightRow(-1),
        hasMultiselection(false),
        onlyHighlightRole{CustomRoles::roleHighlight}
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
            if( highlightRows.count( cellIndex.row() ) )
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
        if(dataChangedALS || columnsChangedALS || sortedChangedALS) {
            setHighlightRow(-1, 0);

            bool doSort(true);
            if(dataVal.isEmpty()) doSort = false;

            if(doSort) {
                if(sortColumns.isEmpty()){ //no sort
                    doSort = false;
                    if(!dataIndex.isEmpty()) {
                        beginResetModel();
                        dataIndex.clear();
                        endResetModel();
                    }
                }
            }

            if(doSort) {
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

                beginResetModel();
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

                endResetModel();
            }
            dataChangedALS = false;
            columnsChangedALS = false;
            sortedChangedALS = false;
        }
    }

    void TableModel::beginReset(bool appendMode)
    {
        beginResetModel();
        if(!appendMode) {
            dataVal.clear();
            //dataIndex.clear();
        }
        dataChangedALS = true;
    }

    void TableModel::endReset()
    {
        endResetModel();
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

            beginReset(false);

            if(!addFrontRecords.isEmpty())
                allOk = addFromList(addFrontRecords, false);

            dataVal.reserve(100);
            int nCols = columnsDef.size();
            while(query.next() && allOk) {
                dataVal.push_back(QVector<QVariant>());
                QVector<QVariant>& curRow = dataVal.last();
                curRow.reserve( nCols );

                for(int iCol = 0; iCol < nCols; iCol++) {
                    //if(getColumnDef( iCol ).reference1 < 0)
                        appendDataVariant(curRow, query.value(iCol), getColumnDef( iCol ).type, DataDialect::Sqlite);
                    //else
                    //    appendDataVariant(curRow, emptyVInt, getColumnDef( iCol ).type, DataDialect::JsonISO);
                }
            }
            dataVal.shrink_to_fit();

            endReset();
        }

        if(query.lastError().isValid())
        {
            allOk = false;
            qDebug() << "Error querying the db" << query.lastError().text();
        }
        query.finish();

        return allOk;
    }

    bool TableModel::addFromList(const QVariantList &values, bool resetList)
    {
        bool allOk(true);
        //if(resetList)
            beginReset(!resetList);

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

        //if(resetList)
            endReset();
        return allOk;
    }

    void TableModel::setFrontRecords(const QVariantList &values)
    {
        addFrontRecords = values;
    }

    int TableModel::countFromQuery(const QString &theSqlQuery, const QList<QVariant> &parameters)
    {
        if(!dbRef->getDb()) {
            qDebug() << "No database";
            return false;
        }

        QSqlQuery query(*dbRef->getDb());
        query.setForwardOnly(true);

        if(!query.prepare(theSqlQuery)){
            qDebug() << "Error querying the db" << query.lastError().text();
            return 0;
        }

        if(!parameters.isEmpty()) {
            for(auto& curParam: parameters) {
                query.addBindValue(curParam);
            }
        }

        int numRecords(0);

        bool allOk(true);
        if(query.exec()) {
            if(query.next()) {
                numRecords = query.value(0).toInt();
            }
        }
        if(query.lastError().isValid())
        {
            allOk = false;
            qDebug() << "Error querying the db" << query.lastError().text();
        }
        query.finish();

        if(allOk)
            return numRecords;

        return 0;
    }

    void TableModel::addRecord(const QList<QVariant>& theData)
    {
        int numColumns( columnsDef.size() );

        dataChangedALS = true;
        dataVal.push_back(QVector<QVariant>());
        QVector<QVariant>& curRow = dataVal.last();
        int iCol=0;
        for(auto& theValue: theData){
            //if(getColumnDef( iCol ).reference1 < 0)
                appendDataVariant(curRow, theValue, getColumnDef( iCol ).type, DataDialect::JsonISO);
//            else
//                appendDataVariant(curRow, emptyVInt, getColumnDef( iCol ).type, DataDialect::JsonISO);
            iCol++;
        }

        while(iCol < numColumns) {
            appendDataVariant(curRow, emptyVInt, getColumnDef( iCol ).type, DataDialect::JsonISO);
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
        //qmlRegisterType<bpp::TableModel>("BppTableModel", 0, 1, "BTModel");
        qmlRegisterType<bpp::TableModel>("BppTable", 0, 1, "BTModel");
        bpp::TableDatabase::registerQml();
        bpp::TableColumn::registerQml();
    }

    void TableModel::setDbRef(bpp::TableDatabase *value)
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

    bool TableModel::copyRowToClipboard(int row) const
    {
        QString text = getRowString(row);
        QClipboard* clipboard = QGuiApplication::clipboard();

        clipboard->setText(text, QClipboard::Clipboard);
        if (clipboard->supportsSelection()) {
            clipboard->setText(text, QClipboard::Selection);
        }

        return true;
    }

    QString TableModel::getRowString(int row) const
    {
        QString toRet;

        toRet.append("{");

        int iCol(0);
        int appended(0);
        for(auto col: columnsDef){
            if(col->command == 0) {
                if(appended)
                    toRet.append( ", " );
                if(col->title.isEmpty())
                    toRet.append( QString("\"column_%1\": ").arg(iCol + 1) );
                else
                    toRet.append( QString("\"%1\": ").arg(col->title) );
                if(col->type == TableColumn::Str || col->type == TableColumn::Date || col->type == TableColumn::DateTime)
                {
                    toRet.append( "\"" );
                    toRet.append( data( QModelIndex( index(row, iCol) ), Qt::DisplayRole).toString() );
                    toRet.append( "\"" );
                }
                else
                    toRet.append( data( QModelIndex( index(row, iCol) ), Qt::DisplayRole).toString() );
                appended++;
            }
            iCol++;
        }
        toRet.append("}");

        return toRet;
    }

    QVariantMap TableModel::getRowObject(int row) const
    {
        QVariantMap toRet;
        int iCol = 0;
        for(auto col: columnsDef){
            toRet[col->role] = getDataDisplayRole( QModelIndex( index(row, iCol) ) );
            iCol++;
        }
        return toRet;
    }

    bool TableModel::setCellValue(int rowNum, int columnNum, const QVariant &data)
    {
        if(rowNum < 0 || rowNum >= dataVal.size())
            return false;
        if(columnNum < 0 || columnNum >= columnsDef.size())
            return false;

        int whatRow = rowNum;
        if(!dataIndex.isEmpty())
            whatRow = dataIndex[whatRow];

        if(sortColumns.contains(columnNum + 1) || sortColumns.contains(-(columnNum + 1))){
            //data need to be resorted
            beginReset(true);
            dataVal[whatRow][columnNum] = data;
            endReset();
        }
        else {
            dataVal[whatRow][columnNum] = data;
            emit dataChanged( QModelIndex( index(rowNum, columnNum) ),  QModelIndex( index(rowNum, columnNum) ), {Qt::DisplayRole});
        }
        return true;
    }

    int TableModel::getColWidth(int columnId) const
    {
        int theW(0);
        if(columnId<0)
            theW = 100;
        else if(columnsDef[columnId]->visible)
            theW = columnsDef[columnId]->width;

        //qDebug() << columnId << theW;
        return theW;
    }

    void TableModel::clearColumnsDef()
    {
        for(auto col: qAsConst(columnsDef)){
            delete col;
        }
        columnsDef.clear();
        columnsChangedALS = true;
    }

    int TableModel::addColumnDef()
    {
        int newCol(columnsDef.size());
        columnsDef.push_back( new TableColumn() );
        columnsChangedALS = true;
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

    int TableModel::getColumnId(const QString &columnRole)
    {
        int columnNum = -1;
        for(int iCol = 0; iCol < columnsDef.size(); iCol++) {
            if (columnRole == columnsDef[iCol]->role) {
                columnNum = iCol;
                break;
            }
        }
        return columnNum;
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
        QVector<int> newSortColumns;
        for(int i = 0; i < columnsDef.size(); i++){
            int sortVal = getColumnDef(i).sortFlag;
            if(sortVal == 1)
                newSortColumns.push_back(i+1);
            if(sortVal == 2)
                newSortColumns.push_back(-(i+1));
        }
        if(newSortColumns != sortColumns) {
            sortColumns = newSortColumns;
            sortedChangedALS = true;
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
    
    bool TableModel::getMultiselectionMobileMode() const
    {
        return multiselectionMobileMode;
    }

    void TableModel::setMultiselectionMobileMode(bool value)
    {
        if(multiselectionMobileMode != value) {
            multiselectionMobileMode = value;
            emit multiselectionMobileModeChanged();
        }
    }

    bool TableModel::getHasMultiselection() const
    {
        return hasMultiselection;
    }

    void TableModel::setHasMultiselection(bool value)
    {
        if(value != hasMultiselection) {
            hasMultiselection = value;
            if(!hasMultiselection && highlightRows.size()>1){
                setHighlightRow(-1, 0);
            }
            emit hasMultiselectionChanged();
        }
    }

    int TableModel::getHighlightRow() const
    {
        return highlightRow;
    }

    bool TableModel::isHighlightRow(int rowNum) const
    {
        return highlightRows.count(rowNum)>0;
    }

    int TableModel::countHighlightRows() const
    {
        return int(highlightRows.size());
    }

    QVector<int> TableModel::getHighlightRows() const
    {
        QVector<int> toRet;
        for(auto curRow: highlightRows) toRet.push_back(curRow);
        return toRet;
    }

    void TableModel::dataNeedSort()
    {
        columnsChangedALS = true;
    }

    void TableModel::setHighlightRow(int rowNum, int modifiers)
    {
        bool pressedCtrl = modifiers & Qt::ControlModifier;
        bool pressedShift = modifiers & Qt::ShiftModifier;

        bool fireRowChanged(false);
        int minRow(-1), maxRow(-1);

        if(multiselectionMobileMode) pressedCtrl = true;

        if(highlightRows.count(rowNum)) {
            if(!hasMultiselection || pressedCtrl || highlightRows.size() == 1) {
                //deselect it
                highlightRows.erase(rowNum);
                if(highlightRows.empty())
                    highlightRow = -1;
                else
                    highlightRow = *highlightRows.begin();
                fireRowChanged = true;
                minRow = rowNum; maxRow = rowNum;
                lastHighlightRow = -1;
            }
            else {
                if(hasMultiselection) {
                    minRow = *highlightRows.begin();
                    maxRow = *highlightRows.rbegin();
                    highlightRows.clear();
                    highlightRows.insert(rowNum);
                    highlightRow = rowNum;
                    lastHighlightRow = rowNum;
                    fireRowChanged = true;
                }
            }
        }
        else {
            if(rowNum == -1) {
                //select none
                if(!highlightRows.empty()) {
                    //clear selection
                    minRow = *highlightRows.begin();
                    maxRow = *highlightRows.rbegin();
                    highlightRows.clear();
                    highlightRow = -1;
                    lastHighlightRow = -1;
                    fireRowChanged = true;
                }
            }
            else if(rowNum == -2) {
                //select all
                for(int irow=0; irow<dataVal.size(); irow++){
                    highlightRows.insert(irow);
                }
                fireRowChanged = true;
                highlightRow = dataVal.size()-1;
                lastHighlightRow = dataVal.size()-1;
                if(!highlightRows.empty()) {
                    minRow = *highlightRows.begin();
                    maxRow = *highlightRows.rbegin();
                }
            }
            else {
                if(!hasMultiselection || (!pressedCtrl && !pressedShift)) {
                    if(!highlightRows.empty()) {
                        minRow = *highlightRows.begin();
                        maxRow = *highlightRows.rbegin();
                        highlightRows.clear();
                    }
                }
                if(!hasMultiselection || !pressedShift || lastHighlightRow == -1)
                    highlightRows.insert(rowNum);
                else {
                    int fromRow = lastHighlightRow;
                    int toRow = rowNum;
                    if(fromRow > toRow) std::swap(fromRow, toRow);
                    minRow = fromRow;
                    maxRow = toRow;
                    while(fromRow <= toRow) {
                        highlightRows.insert(fromRow);
                        fromRow++;
                    }
                }

                highlightRow = rowNum;
                lastHighlightRow = rowNum;
                fireRowChanged = true;
                if(minRow < 0 || rowNum < minRow) minRow = rowNum;
                if(maxRow < 0 || rowNum > maxRow) maxRow = rowNum;
            }
        }

        if(fireRowChanged) {
            emit highlightRowChanged();
            if(minRow != -1) {
                //qDebug() << rowNum << minRow << maxRow;
                emit dataChanged(QModelIndex(index(minRow, 0)), QModelIndex(index(maxRow, columnsDef.size() - 1)), onlyHighlightRole);
            }
        }
    }

    void TableModel::setHighlightRows(bool emptySel, const QVector<int> &rowsIdx)
    {
        bool fireRowChanged(false);
        int minRow(-1), maxRow(-1);

        if(emptySel){
            if(!highlightRows.empty()) {
                //clear selection
                minRow = *highlightRows.begin();
                maxRow = *highlightRows.rbegin();
                highlightRows.clear();
                highlightRow = -1;
                lastHighlightRow = -1;
                fireRowChanged = true;
            }
        }
        if(!rowsIdx.isEmpty()) {
            for(int irow=0; irow<rowsIdx.size(); irow++){
                highlightRows.insert(rowsIdx[irow]);
            }
            fireRowChanged = true;
            highlightRow = rowsIdx[rowsIdx.size()-1];
            lastHighlightRow = highlightRow;
            if(!highlightRows.empty()) {
                if(minRow < 0 || *highlightRows.begin() < minRow)
                    minRow = *highlightRows.begin();
                if(maxRow < 0 || *highlightRows.rbegin() > maxRow)
                    maxRow = *highlightRows.rbegin();
            }
        }

        if(fireRowChanged) {
            emit highlightRowChanged();
            if(minRow != -1) {
                //qDebug() << rowNum << minRow << maxRow;
                emit dataChanged(QModelIndex(index(minRow, 0)), QModelIndex(index(maxRow, columnsDef.size() - 1)), onlyHighlightRole);
            }
        }
    }
}
