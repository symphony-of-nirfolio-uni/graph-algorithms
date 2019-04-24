#ifndef GRAPHPLOTWINDOW_H
#define GRAPHPLOTWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "../GraphUI/QtCustomPlot/qcustomplot.h"

#include <vector>
#include "../Graph_algorithms/GraphAPI/GraphAPI.h"
#include "../Graph_algorithms/Graph_data/Graph.h"

namespace Ui {
class GraphPlotWindow;
}

class GraphPlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphPlotWindow(QString graph_file_name, QWidget *parent = nullptr);
    ~GraphPlotWindow();

private:
    Ui::GraphPlotWindow *ui;

    QCustomPlot* plot;
    Graph graph;
    vector<Point> vertices_coordinates;

    QCPGraph *dots;
    vector<QCPItemLine*> lines;
    vector<QCPItemLine*> arrows;


    QString graph_name;
    double scatter_radius;
    int plot_min;
    int plot_max;

    void get_graph_from_api();
    void add_dots_on_chart();
    void add_lines_on_chart();
    void axis_and_legend_setup();
};

#endif // GRAPHPLOTWINDOW_H
