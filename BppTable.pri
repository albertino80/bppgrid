QT += quick
QT += quickcontrols2
QT += sql
QT += svg

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QML_IMPORT_PATH += $$PWD
QML_DESIGNER_IMPORT_PATH += $$PWD

SOURCES += \
	$$PWD/BppTable/bpptablecolumn.cpp \
	$$PWD/BppTable/bpptabledatabase.cpp \
	$$PWD/BppTable/bpptablemodel.cpp

HEADERS += \
	$$PWD/BppTable/bpptablecolumn.h \
	$$PWD/BppTable/bpptabledatabase.h \
	$$PWD/BppTable/bpptablemodel.h

INCLUDEPATH += $$PWD/BppTable

RESOURCES += $$PWD/BppTable.qrc
