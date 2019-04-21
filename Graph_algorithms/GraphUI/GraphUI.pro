#-------------------------------------------------
#
# Project created by QtCreator 2019-04-16T17:46:34
#
#-------------------------------------------------

QT += core gui
QT += charts
QT += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        ../Graph_algorithms/GraphAPI.cpp \
    graphwindow.cpp \
    ../Graph_algorithms/GraphAPI.cpp \
    ../Graph_algorithms/Graph.cpp \
    newgraphdialog.cpp \
    loadgraphdialog.cpp

HEADERS += \
        mainwindow.h \
        ../Graph_algorithms/GraphAPI.h \
    graphwindow.h \
    ../Graph_algorithms/GraphAPI.h \
    ../Graph_algorithms/Graph.h \
    ../Graph_algorithms/api_creation.h \
    newgraphdialog.h \
    loadgraphdialog.h

FORMS += \
        mainwindow.ui \
    graphwindow.ui \
    newgraphdialog.ui \
    loadgraphdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    additions.qml
