QT       += core gui widgets sql
CONFIG += c++11

DESTDIR = ../bin

SOURCES += \
    ../common/constant.cpp \
    dbconnector.cpp \
    lotterypage.cpp \
    main.cpp \
    mgmtpage.cpp \
    resultpage.cpp

HEADERS += \
    ../common/constant.h \
    ../common/model.h \
    dbconnector.h \
    lotterypage.h \
    mgmtpage.h \
    resultpage.h

FORMS += \
    lotterypage.ui \
    mgmtpage.ui \
    resultpage.ui

RESOURCES += \
    ../common/style/style.qrc

INCLUDEPATH += ../common/

QXLSX_PARENTPATH = ../common/QXlsx
QXLSX_HEADERPATH = ../common/QXlsx/header/
QXLSX_SOURCEPATH = ../common/QXlsx/source/
include(../common/QXlsx/QXlsx.pri)
