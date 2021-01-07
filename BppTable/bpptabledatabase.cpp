#include "bpptabledatabase.h"
#include <QQmlEngine>

namespace bpp {

    TableDatabase::TableDatabase(QObject *parent) : QObject(parent)
    {

    }

    QSqlDatabase *TableDatabase::getDb()
    {
        return nullptr;
    }

    void TableDatabase::registerQml()
    {
        //qmlRegisterType<bpp::TableDatabase>("BppTableModel", 0, 1, "BTDb");
        qmlRegisterType<bpp::TableDatabase>("BppTable", 0, 1, "BTDb");
    }
}
