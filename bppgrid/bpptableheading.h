#ifndef TABLEHEADING_H
#define TABLEHEADING_H

#include <QObject>
#include <QVariantList>
#include <QVariantMap>

namespace bpp {

    class TableHeading : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(QVariantList columns READ getColumns WRITE setColumns NOTIFY columnsChanged)
    public:
        explicit TableHeading(QObject *parent = nullptr);

        Q_INVOKABLE const QVariantList getColumns() const;
        Q_INVOKABLE void setColumns(const QVariantList& newColumns);
        Q_INVOKABLE void clickedOnColumn(int index);

        Q_INVOKABLE const QVector<int> getSortColumns() const;
        Q_INVOKABLE const QVector<int> getRoleColumns(const QString& roleName) const;
        Q_INVOKABLE const QVector<QString> getRoleColumnsStr(const QString& roleName) const;

        static void registerQml();

    signals:
        void columnsChanged();

    public slots:

    private:
        QVariantList theColumns;
    };

}

#endif // TABLEHEADING_H
