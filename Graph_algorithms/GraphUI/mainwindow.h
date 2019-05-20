#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

#include "graphplotwindow.h"
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLegendMarker>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public QCloseEvent
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    vector<GraphPlotWindow*> windows;

public slots:
    void show_graph_window();
    void load_graph_dialog();
    void get_new_window(GraphPlotWindow*);
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
