#-------------------------------------------------
#
# Project created by QtCreator 2019-04-23T16:15:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExamenOpdracht
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    ellipseimage.cpp

HEADERS  += mainwindow.h \
    ellipseimage.h

FORMS    += mainwindow.ui


unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
