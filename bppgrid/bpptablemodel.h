#ifndef TABLEMODEL1_H
#define TABLEMODEL1_H

#include <QObject>
#include <QAbstractTableModel>
#include "bpptabledatabase.h"

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
            roleHighlight
        };

        enum ColumnType{
            Str = 0,
            Dbl,
            Int,
            Date,
            DateTime
        };

        enum DataDialect{
            Sqlite = 0,
            JsonISO
        };

        Q_ENUMS(ColumnType)

        TableModel();

        int rowCount(const QModelIndex & = QModelIndex()) const override;
        int columnCount(const QModelIndex & = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role) const override;

        //https://doc.qt.io/qt-5/qt.html#ItemDataRole-enum
        QHash<int, QByteArray> roleNames() const override;

        Q_INVOKABLE void sortData();

        Q_INVOKABLE void beginReset();
        Q_INVOKABLE void endReset();

        Q_INVOKABLE void addRecord(const QList<QVariant>& theData);
        Q_INVOKABLE bool addFromQuery(const QString& theSqlQuery, const QList<QVariant>& parameters);
        Q_INVOKABLE bool addFromList(const QVariantList& values);

        Q_INVOKABLE void setSortColumns(const QVector<int> &value);
        Q_INVOKABLE void setTypeColumns(const QVector<int> &value);
        Q_INVOKABLE void setActionColumns(const QVector<int> &value);
        Q_INVOKABLE void setCommandColumns(const QVector<int> &value);
        Q_INVOKABLE void setRoleColumns(const QVector<QString> &value);
        Q_INVOKABLE void setHighlightRow(int rowNum);
        Q_INVOKABLE int getHighlightRow() const;

        Q_INVOKABLE void updateLayout();

        static void registerQml();
        Q_INVOKABLE void setDbRef(TableDatabase *value);

    signals:
        void highlightRowChanged();

    protected:
        void appendDataVariant(QVector<QVariant>& record, const QVariant& theValue, ColumnType columnType, DataDialect dia);

        TableDatabase emptyDbRef;
        TableDatabase* dbRef;

        bool dataSorted;

        QVector<int> sortColumns; //first column is 1 if asc; -1 if desc - second is 2 and -2 ...
        QVector<ColumnType> typeColumns;
        QVector<int> actionColumns;
        QVector<int> commandColumns;
        QVector<QString> roleColumns;

        int highlightRow;
        QVector< QVector<QVariant> > dataVal;
        QVector<int> dataIndex;
    };

}

#endif // TABLEMODEL1_H
