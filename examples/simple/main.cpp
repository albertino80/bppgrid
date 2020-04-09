#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <bpptablemodel.h>
#include <QTranslator>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QTranslator appTranslator;
    if(appTranslator.load(QString(":/i18n/simple-qml_%1.qm").arg(QLocale::system().name())))
        app.installTranslator(&appTranslator);

    bpp::TableModel::registerQml();

    QQmlApplicationEngine engine;
	engine.addImportPath("qrc:/");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
