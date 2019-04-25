#ifndef GRAPHPLOTWINDOW_H
#define GRAPHPLOTWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTimer>
#include <QCloseEvent>
#include "../GraphUI/QtCustomPlot/qcustomplot.h"

#include <vector>
#include "../Graph_algorithms/GraphAPI/GraphAPI.h"
#include "../Graph_algorithms/Graph_data/Graph.h"

namespace Ui {
class GraphPlotWindow;
}

class GraphPlotWindow : public QMainWindow, public QCloseEvent
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
    QCPGraph *used;
    QCPGraph *black;
    QCPGraph *highlighted;
    vector<QCPItemLine*> lines;
    vector<QCPItemLine*> arrows;
    QTimer *timer;
    vector<unsigned> black_v;
    vector<unsigned> used_v;



    QString graph_name;
    double scatter_radius;
    int plot_min;
    int plot_max;

    void get_graph_from_api();
    void add_dots_on_chart();
    void add_lines_on_chart();
    void axis_and_legend_setup();
    void make_scatter(QCPGraph* graph, QColor color, double radius);
    void setup_update_timer();
    void add_used_vertex(unsigned vertex);
    void add_black_vertex(unsigned vertex);
    void make_highlighted(unsigned vertex);


private slots:
    void update_graph();
    void closeEvent(QCloseEvent *event);
};

#endif // GRAPHPLOTWINDOW_H
