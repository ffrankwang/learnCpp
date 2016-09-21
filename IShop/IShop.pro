#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T17:08:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IShop
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    videothread.cpp \
    ssocket.cpp

HEADERS  += widget.h \
    videothread.h \
    ssocket.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
