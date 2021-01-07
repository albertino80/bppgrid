#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>
#include <QQuickStyle>
#include <QFont>
#include "bppfontawesome.h"
#include "bpptablemodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    if( QFontDatabase::addApplicationFont(":/BppFa/fonts/Roboto-Regular.ttf") < 0)
        qWarning() << "Roboto font cannot be loaded !";

    QQuickStyle::setStyle("Material");
    QFont fon("Roboto", 11);
    app.setFont(fon);

    QQmlApplicationEngine engine;
    bpp::FontAwesome::registerQml(engine);
    bpp::TableModel::registerQml();
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
