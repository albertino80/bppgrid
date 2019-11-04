#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include <bpptablemodel.h>
#include "mydatabase.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("bppGrid");
    QCoreApplication::setOrganizationDomain("bigno.it");
    QCoreApplication::setOrganizationName("bpp");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    bpp::TableModel::registerQml();

    MyDatabase theDb;
    if(!theDb.openDb())
        return 1;

    if(!theDb.createTable())
        return 1;

    QQmlApplicationEngine engine;

	engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("workDb", &theDb);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
