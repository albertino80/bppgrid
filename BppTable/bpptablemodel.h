#ifndef TABLEMODEL1_H
#define TABLEMODEL1_H

#include <QObject>
#include <set>
#include <QAbstractTableModel>
#include "bpptabledatabase.h"
#include "bpptablecolumn.h"

namespace bpp {

    class TableModel : public QAbstractTableModel
    {
        Q_OBJECT
        Q_PROPERTY(int highlightRow READ getHighlightRow NOTIFY highlightRowChanged)
        Q_PROPERTY(bool hasMultiselection READ getHasMultiselection WRITE setHasMultiselection NOTIFY hasMultiselectionChanged)
        Q_PROPERTY(bool multiselectionMobileMode READ getMultiselectionMobileMode WRITE setMultiselectionMobileMode NOTIFY multiselectionMobileModeChanged)
    public:

        enum CustomRoles{
            roleDataType = Qt::UserRole,
            roleView,
            roleCommand,
            roleHighlight,
            roleVisible,
            roleRef1
        };

        enum DataDialect{
            Sqlite = 0,
            JsonISO
        };

        TableModel();
        virtual ~TableModel() override;

        int rowCount(const QModelIndex & = QModelIndex()) const override;
        int columnCount(const QModelIndex & = QModelIndex()) const override;
        QVariant data(const QModelIndex &cellIndex, int role) const override;

        //https://doc.qt.io/qt-5/qt.html#ItemDataRole-enum
        QHash<int, QByteArray> roleNames() const override;

        Q_INVOKABLE void sortData();

        Q_INVOKABLE void beginReset(bool appendMode);
        Q_INVOKABLE void endReset();

        Q_INVOKABLE void addRecord(const QList<QVariant>& theData);
        Q_INVOKABLE bool addFromQuery(const QString& theSqlQuery, const QList<QVariant>& parameters);
        Q_INVOKABLE bool addFromList(const QVariantList& values, bool resetList = true);
        Q_INVOKABLE void setFrontRecords(const QVariantList& values);

        Q_INVOKABLE int countFromQuery(const QString& theSqlQuery, const QList<QVariant>& parameters);

        Q_INVOKABLE void setHighlightRow(int rowNum, int modifiers);
        Q_INVOKABLE void setHighlightRows(bool emptySel, const QVector<int>& rowsIdx);
        Q_INVOKABLE int getHighlightRow() const;
        Q_INVOKABLE bool isHighlightRow(int rowNum) const;
        Q_INVOKABLE int countHighlightRows() const;
        Q_INVOKABLE QVector<int> getHighlightRows() const;

        Q_INVOKABLE void dataNeedSort();
        Q_INVOKABLE void updateLayout();

        static void registerQml();
        Q_INVOKABLE void setDbRef(bpp::TableDatabase *value);

        Q_INVOKABLE int getColWidth(int columnId) const;
        Q_INVOKABLE void clearColumnsDef();
        const TableColumn& getColumnDef(int columnId) const;
        Q_INVOKABLE int getColumnId(const QString& columnRole);

        Q_INVOKABLE int addColumnDef();
        Q_INVOKABLE void setColumnDef(int columnId, bool withDefaults, const QVariantMap& colDef);
        Q_INVOKABLE void endUpdateColumns();

        Q_INVOKABLE bool canHideColumns();

        Q_INVOKABLE bool copyRowToClipboard(int row) const;
        Q_INVOKABLE QString getRowString(int row) const;
        Q_INVOKABLE QVariantMap getRowObject(int row) const;

        Q_INVOKABLE bool setCellValue(int rowNum, int columnNum, const QVariant& data);

        bool getHasMultiselection() const;
        void setHasMultiselection(bool value);

        bool getMultiselectionMobileMode() const;
        void setMultiselectionMobileMode(bool value);

    signals:
        void highlightRowChanged();
        void hasMultiselectionChanged();
        void multiselectionMobileModeChanged();

    protected:
        void appendDataVariant(QVector<QVariant>& record, const QVariant& theValue, TableColumn::ColumnType columnType, DataDialect dia);
        void calcSortColumns();
        void calcReferenceColumns();

        QVariant getDataDisplayRole(const QModelIndex &index) const;

        TableDatabase emptyDbRef;
        TableDatabase* dbRef;

        bool dataChangedALS;    //new rows added or removed, After Last Sort
        bool columnsChangedALS; //new columns added or removed, After Last Sort
        bool sortedChangedALS;  //to sort colmumn list changed, After Last Sort

        QVector<int> sortColumns;   //column ordinal, starting from 1 (not 0!)
        QVector<TableColumn*> columnsDef;

        int highlightRow;
        int lastHighlightRow;
        std::set<int> highlightRows;
        bool hasMultiselection;
        bool multiselectionMobileMode;
        QVector< QVector<QVariant> > dataVal;
        QVector<int> dataIndex;

        QVariantList addFrontRecords;

        QVariant emptyVString = QVariant(QVariant::String);
        QVariant emptyVDouble = QVariant(QVariant::Double);
        QVariant emptyVInt = QVariant(QVariant::Int);
        QVariant emptyVDate = QVariant(QVariant::Date);
        QVariant emptyVDateTime = QVariant(QVariant::DateTime);

        QVector<int> onlyHighlightRole;
    };

}

#endif // TABLEMODEL1_H
