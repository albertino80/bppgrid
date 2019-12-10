#ifndef TABLECOLUMN_H
#define TABLECOLUMN_H

#include <QObject>

namespace bpp {

    class TableColumn : public QObject
    {
        Q_OBJECT
    public:
        explicit TableColumn(QObject *parent = nullptr);
        static void registerQml();
        void modify(const QVariantMap& colDef, bool withDefaults);

        enum ColumnType{
            Str = 0,
            Dbl,
            Int,
            Date,
            DateTime
        };

        Q_ENUM(ColumnType)

        QString title;
        ColumnType type;
        int view;
        int sortFlag;
        int action;
        int command;
        int width;
        int minWidth;
        bool visible;
        QString role;
        QString dataRef1;

        int reference1;

    signals:

    public slots:
    };

}
#endif // TABLECOLUMN_H
