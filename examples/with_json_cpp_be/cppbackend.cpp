#include "cppbackend.h"
#include <QVariantMap>
#include <QColor>

CppBackend::CppBackend(QObject *parent) : QObject(parent)
{

}

QVariantList CppBackend::getData(int whatTab)
{
    QVariantList records;

    int numRecs(10);

    for(int iRec = 0; iRec<numRecs; iRec++){
        QVariantMap record;

        int r(0), g(0), b(0);
        switch (whatTab) {
            case 0:
            r = 255 * iRec / numRecs;
            break;
            case 1:
            g = 255 * iRec / numRecs;
            break;
            case 2:
            b = 255 * iRec / numRecs;
            break;
        }

        QColor theColor(r,g,b);

        record["pkid"] = iRec;
        record["name"] = QString("Record %1 of tab %2").arg(iRec).arg(whatTab);
        record["color"] = theColor.name();

        records.append(record);
    }

    return records;
}
