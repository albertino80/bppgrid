#ifndef TABLEDATABASE_H
#define TABLEDATABASE_H

#include <QObject>
#include <QSqlDatabase>

namespace bpp {

    class TableDatabase : public QObject
    {
        Q_OBJECT
    public:
        explicit TableDatabase(QObject *parent = nullptr);
        virtual ~TableDatabase() {}

        virtual QSqlDatabase* getDb();

        static void registerQml();
    signals:

    public slots:
    };

}
#endif // TABLEDATABASE_H
