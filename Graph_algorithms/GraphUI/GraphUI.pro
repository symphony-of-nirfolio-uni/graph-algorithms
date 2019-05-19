#-------------------------------------------------
#
# Project created by QtCreator 2019-04-16T17:46:34
#
#-------------------------------------------------

QT += core gui
QT += charts
QT += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = GraphUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += QT_GRAPH_API

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    newgraphdialog.cpp \
    ../Graph_algorithms/GraphAPI/GraphAPI.cpp \
    ../Graph_algorithms/Graph_data/Graph.cpp \
    loadgraphdialog.cpp \
    ../Graph_algorithms/Graph_data/Algorithm.cpp \
    ../Graph_algorithms/Graph_data/Algorithm_factory.cpp \
    ../Graph_algorithms/Graph_data/Graph.cpp \
    ../Graph_algorithms/Graph_data/Graph_algo.cpp \
    ../Graph_algorithms/Graph_data/Graph_is_acyclic.cpp \
    ../Graph_algorithms/Graph_data/Graph_is_connected.cpp \
    ../Graph_algorithms/Graph_data/Read_graph.cpp \
    ../Graph_algorithms/Graph_data/Read_graph_builder.cpp \
    ../Graph_algorithms/Build_dots/Build_dots.cpp \
    QtCustomPlot/qcustomplot.cpp \
    graphplotwindow.cpp \
    Factories/linefactory.cpp \
    ../Graph_algorithms/Graph_data/Algorithm.cpp \
    ../Graph_algorithms/Graph_data/Algorithm_factory.cpp \
    ../Graph_algorithms/Graph_data/Finding_shortest_path.cpp \
    ../Graph_algorithms/Graph_data/Graph.cpp \
    ../Graph_algorithms/Graph_data/Graph_algo.cpp \
    ../Graph_algorithms/Graph_data/Graph_is_acyclic.cpp \
    ../Graph_algorithms/Graph_data/Graph_is_connected.cpp \
    ../Graph_algorithms/Graph_data/Read_graph.cpp \
    ../Graph_algorithms/Graph_data/Read_graph_builder.cpp \
    messagedialog.cpp \
    ../Graph_algorithms/Control_data_time/Control_data_time.cpp \
    ../Graph_algorithms/Control_data_time/Control_data_time.cpp

HEADERS += \
        mainwindow.h \
    ../Graph_algorithms/GraphAPI/GraphAPI.h \
    ../Graph_algorithms/Graph_data/Graph.h \
    newgraphdialog.h \
    loadgraphdialog.h \
    ../Graph_algorithms/Graph_data/Algorithm.h \
    ../Graph_algorithms/Graph_data/Algorithm_factory.h \
    ../Graph_algorithms/Graph_data/Graph.h \
    ../Graph_algorithms/Graph_data/Graph_algo.h \
    ../Graph_algorithms/Graph_data/Graph_is_acyclic.h \
    ../Graph_algorithms/Graph_data/Graph_is_connected.h \
    ../Graph_algorithms/Graph_data/Read_graph.h \
    ../Graph_algorithms/Graph_data/Read_graph_builder.h \
    ../Graph_algorithms/Build_dots/Build_dots.h \
    QtCustomPlot/qcustomplot.h \
    graphplotwindow.h \
    Factories/linefactory.h \
    ../Graph_algorithms/Graph_data/Algorithm.h \
    ../Graph_algorithms/Graph_data/Algorithm_factory.h \
    ../Graph_algorithms/Graph_data/Finding_shortest_path.h \
    ../Graph_algorithms/Graph_data/Graph.h \
    ../Graph_algorithms/Graph_data/Graph_algo.h \
    ../Graph_algorithms/Graph_data/Graph_is_acyclic.h \
    ../Graph_algorithms/Graph_data/Graph_is_connected.h \
    ../Graph_algorithms/Graph_data/Read_graph.h \
    ../Graph_algorithms/Graph_data/Read_graph_builder.h \
    messagedialog.h \
    ../Graph_algorithms/Control_data_time/Control_data_time.h \
    ../Graph_algorithms/Control_data_time/Control_data_time.h

FORMS += \
        mainwindow.ui \
    newgraphdialog.ui \
    loadgraphdialog.ui \
    graphplotwindow.ui \
    messagedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
