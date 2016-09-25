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
    ssocket.cpp \
    yuv2rgb.cpp \
    jdatabuf.cpp \
    video.cpp

HEADERS  += widget.h \
    videothread.h \
    ssocket.h \
    yuv2rgb.h \
    jdatabuf.h \
    video.h

FORMS    += widget.ui

RESOURCES += \
    resource.qrc
LIBS+=-l jpeg
