#ifndef MYDATABASE_H
#define MYDATABASE_H

#include "bpptabledatabase.h"

class MyDatabase: public bpp::TableDatabase
{
public:
    MyDatabase();
    virtual ~MyDatabase() override;

    bool openDb();
    bool createTable();

    virtual QSqlDatabase* getDb() override;

protected:
    QSqlDatabase db;
};

#endif // MYDATABASE_H
