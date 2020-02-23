#-------------------------------------------------
#
# Project created by QtCreator 2020-02-21T16:45:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp

HEADERS  += widget.h \
    mylabel.h

FORMS    += widget.ui

RESOURCES += \
    img.qrc
