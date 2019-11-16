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

    if ( !db.tables().contains( "olimpic_ita_medals" ) ) {
        db.transaction();

        QFile inputFile(":/assets/create_db.sql");
        if (inputFile.open(QIODevice::ReadOnly))
        {
            QTextStream in(&inputFile);
            while (!in.atEnd() && allOk)
            {
                QString line = in.readLine();
                if(line.endsWith(";"))
                    db.exec( line.left(line.length() - 1) );
                else
                    db.exec( line );
            }
            inputFile.close();
        }

        if(allOk)
            db.commit();
        else
            db.rollback();
    }

    return allOk;
}

QSqlDatabase *MyDatabase::getDb()
{
    return &db;
}
