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

        Q_ENUMS(ColumnType)

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

    signals:

    public slots:
    };

}
#endif // TABLECOLUMN_H
