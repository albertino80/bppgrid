#ifndef TABLEMODEL1_H
#define TABLEMODEL1_H

#include <QObject>
#include <QAbstractTableModel>
#include "bpptabledatabase.h"
#include "bpptablecolumn.h"

namespace bpp {

    class TableModel : public QAbstractTableModel
    {
        Q_OBJECT
        Q_PROPERTY(int highlightRow READ getHighlightRow WRITE setHighlightRow NOTIFY highlightRowChanged)
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

        Q_INVOKABLE void beginReset();
        Q_INVOKABLE void endReset();

        Q_INVOKABLE void addRecord(const QList<QVariant>& theData);
        Q_INVOKABLE bool addFromQuery(const QString& theSqlQuery, const QList<QVariant>& parameters);
        Q_INVOKABLE bool addFromList(const QVariantList& values);

        Q_INVOKABLE void setHighlightRow(int rowNum);
        Q_INVOKABLE int getHighlightRow() const;

        Q_INVOKABLE void dataNeedSort();
        Q_INVOKABLE void updateLayout();

        static void registerQml();
        Q_INVOKABLE void setDbRef(TableDatabase *value);

        Q_INVOKABLE int getColWidth(int columnId) const;
        Q_INVOKABLE void clearColumnsDef();
        const TableColumn& getColumnDef(int columnId) const;

        Q_INVOKABLE int addColumnDef();
        Q_INVOKABLE void setColumnDef(int columnId, bool withDefaults, const QVariantMap& colDef);
        Q_INVOKABLE void endUpdateColumns();

        Q_INVOKABLE bool canHideColumns();

        Q_INVOKABLE bool copyRowToClipboard(int row) const;
        Q_INVOKABLE QString getRowString(int row) const;

    signals:
        void highlightRowChanged();

    protected:
        void appendDataVariant(QVector<QVariant>& record, const QVariant& theValue, TableColumn::ColumnType columnType, DataDialect dia);
        void calcSortColumns();
        void calcReferenceColumns();

        QVariant getDataDisplayRole(const QModelIndex &index) const;

        TableDatabase emptyDbRef;
        TableDatabase* dbRef;

        bool dataSorted;

        QVector<int> sortColumns;
        QVector<TableColumn*> columnsDef;

        int highlightRow;
        QVector< QVector<QVariant> > dataVal;
        QVector<int> dataIndex;

        QVariant emptyVString = QVariant(QVariant::String);
        QVariant emptyVDouble = QVariant(QVariant::Double);
        QVariant emptyVInt = QVariant(QVariant::Int);
        QVariant emptyVDate = QVariant(QVariant::Date);
        QVariant emptyVDateTime = QVariant(QVariant::DateTime);
    };

}

#endif // TABLEMODEL1_H
