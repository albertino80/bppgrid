#include "mydatabase.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QDateTime>

MyDatabase::MyDatabase():
    db(QSqlDatabase::addDatabase("QSQLITE", "TEST_BPPGRID"))
{

}

MyDatabase::~MyDatabase()
{
    db.close();
}

bool MyDatabase::openDb()
{
    QString dbPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    if (dbPath.isEmpty())
    {
        qDebug() << "Could not obtain writable location.";
        return false;
    }
    else
    {
        QDir load_folder(dbPath);
        if(!load_folder.exists())
            load_folder.mkpath(load_folder.absolutePath());
    }

    dbPath.append("/main.db");
    db.setDatabaseName(dbPath);
    if (!db.open())
    {
        qDebug() << "Error: db connection failed";
        return false;
    }

    return true;
}

bool MyDatabase::createTable()
{
    bool allOk(true);

    if ( !db.tables().contains( "table1" ) ) {
        QSqlQuery create(db);

        allOk = false;
        if(create.prepare(R"(create table table1(
                          col1 INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
                          col2 INTEGER,
                          col3 TEXT,
                          col4 TEXT,
                          col5 TEXT,
                          col6 REAL,
                          col7 REAL,
                          col8 TEXT,
                          col9 TEXT,
                          col10 TEXT
                          )
        )")){
            db.transaction();
            if(create.exec()){
                if( create.prepare("insert into table1(col2,col3,col4,col5,col6,col7,col8,col9,col10) values(?,?,?,?,?,?,?,?,?)") ) {
                    allOk = true;
                    for(int i=0; i < 200 && allOk; i++) {

                        double cost = floor(double(i) / 10.0);
                        if(i % 2 == 0)
                            cost += 0.33;
                        else
                            cost += 0.66;

                        create.addBindValue( 200 - i );
                        create.addBindValue( QString("%1-1").arg(i) );
                        create.addBindValue( QString("Cell (%1-4) content").arg(i) );
                        create.addBindValue( QString("%1-3").arg(i) );
                        create.addBindValue( cost );
                        create.addBindValue( double(200) - double(i) / 1.1 );
                        create.addBindValue( QDate::currentDate().toString("yyyy-MM-dd") );
                        create.addBindValue( QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") );
                        create.addBindValue( QString("%1-6").arg(i) );
                        allOk = create.exec();
                    }

                }
            }
            if(allOk)
                db.commit();
            else
                db.rollback();
        }
    }

    return allOk;
}

QSqlDatabase *MyDatabase::getDb()
{
    return &db;
}
