#-------------------------------------------------
#
<<<<<<< HEAD
# Project created by QtCreator 2019-04-23T15:25:27
=======
# Project created by QtCreator 2019-04-23T16:15:27
>>>>>>> 3bbcb8d83e6ff5aa365923f4d9141b287e7df908
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExamenOpdracht
TEMPLATE = app

<<<<<<< HEAD

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
=======
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    ellipseimage.cpp \
    ellipsfinder.cpp

HEADERS  += mainwindow.h \
    ellipseimage.h \
    ellipsfinder.h

FORMS    += mainwindow.ui


unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += opencv
}
>>>>>>> 3bbcb8d83e6ff5aa365923f4d9141b287e7df908
