#ifndef TABLECOLUMNLIST_H
#define TABLECOLUMNLIST_H

#include <QObject>
#include <QVector>
#include <QVariantMap>
#include "bpptablecolumn.h"

namespace bpp {

    class TableColumnList : public QObject
    {
        Q_OBJECT
    public:
        explicit TableColumnList(QObject *parent = nullptr);
        virtual ~TableColumnList();
        static void registerQml();

        const QVector<int> getSortColumns() const;

        Q_INVOKABLE void clear();
        Q_INVOKABLE int add();
        Q_INVOKABLE void modifyColumn(int columnId, bool withDefaults, const QVariantMap& colDef);
        Q_INVOKABLE int size() const;
        void swapSort(int columnId);
        const TableColumn& operator[] (int columnId) const;
        const TableColumn& at(int columnId) const;

        Q_INVOKABLE QVariantList getColumnMap();
        Q_INVOKABLE bool resizeColumns(int theWidth);

    signals:

    public slots:

    protected:
        QVector<TableColumn*> def;
    };

}
#endif // TABLECOLUMNLIST_H
