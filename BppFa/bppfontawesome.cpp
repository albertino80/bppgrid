#include "bppfontawesome.h"
#include <QDebug>
#include <QQmlContext>

namespace bpp {

    FontAwesome::FontAwesome(QObject *parent) : QObject(parent)
    {

    }

    bool FontAwesome::registerFont(const QString& fontFile) {
        QFontDatabase fontDatabase;
        int idSolid = fontDatabase.addApplicationFont(fontFile);
        if (idSolid >= 0){
            QStringList ll = fontDatabase.applicationFontFamilies(idSolid);
            for(auto& item: ll){
                qDebug() << item << "Registered";
                if(item.contains("brands", Qt::CaseInsensitive))
                    brands = item;
                else if(item.contains("regular", Qt::CaseInsensitive))
                    regular = item;
                else if(item.contains("solid", Qt::CaseInsensitive))
                    solid = item;
            }
            return true;
        }
        qDebug() << "Error on " << __FUNCTION__;

        return false;
    }

    void FontAwesome::registerQml(QQmlApplicationEngine& engine)
    {
        static FontAwesome icons;
        icons.registerFont(":/BppFa/fonts/fa-solid-900.ttf");
        icons.registerFont(":/BppFa/fonts/fa-regular-400.ttf");
        icons.registerFont(":/BppFa/fonts/fa-brands-400.ttf");

        engine.rootContext()->setContextProperty("Fa", &icons);
    }

}
