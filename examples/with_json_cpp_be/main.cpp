#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>

#include <bpptablemodel.h>
#include <bppfontawesome.h>
#include "cppbackend.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");

    bpp::TableModel::registerQml();
    bpp::FontAwesome::registerQml(engine);

    CppBackend cpp_be;
    engine.rootContext()->setContextProperty("cpp_be", &cpp_be);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
