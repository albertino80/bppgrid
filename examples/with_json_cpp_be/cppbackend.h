#ifndef CPPBACKEND_H
#define CPPBACKEND_H

#include <QObject>
#include <QVariantList>

class CppBackend : public QObject
{
    Q_OBJECT
public:
    explicit CppBackend(QObject *parent = nullptr);

    Q_INVOKABLE QVariantList getData(int whatTab);
signals:

};

#endif // CPPBACKEND_H
