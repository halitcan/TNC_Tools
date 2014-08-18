#-------------------------------------------------
#
# Project created by QtCreator 2014-08-13T23:33:50
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QHeidenhersh
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    heidenhersh.cpp \
    fonttablemodel.cpp \
    heidenhershsimulatedialog.cpp \
    simulateheidenhershgraphicsview.cpp

HEADERS  += mainwindow.h \
    heidenhersh.h \
    fonttablemodel.h \
    heidenhershsimulatedialog.h \
    simulateheidenhershgraphicsview.h

FORMS    += mainwindow.ui \
    heidenhersh.ui \
    heidenhershsimulatedialog.ui

unix:!macx: LIBS += -L$$PWD/../lib/ -lHersh

INCLUDEPATH += $$PWD/../include/Hersh
DEPENDPATH += $$PWD/../include/Hersh
