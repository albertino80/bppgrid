#ifndef TABLEHEADING_H
#define TABLEHEADING_H

#include <QObject>
#include <QVariantList>
#include <QVariantMap>
#include "bpptablecolumn.h"

namespace bpp {

    class TableHeading : public QObject
    {
        Q_OBJECT
    public:
        explicit TableHeading(QObject *parent = nullptr);
        virtual ~TableHeading();

        Q_INVOKABLE int getColWidth(int columnId) const;
        Q_INVOKABLE void clearColumnsDef();
        Q_INVOKABLE int addColumnDef();
        Q_INVOKABLE void setColumnDef(int columnId, bool withDefaults, const QVariantMap& colDef);
        Q_INVOKABLE int sizeColumnsDef() const;
        const TableColumn& getColumnDef(int columnId) const;

        static void registerQml();

    signals:

    public slots:

    private:
        QVector<TableColumn*> columnsDef;
    };

}

#endif // TABLEHEADING_H
