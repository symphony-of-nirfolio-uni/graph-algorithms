#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QtQml>
#include <QtCharts>
#include <vector>
#include "../Graph_algorithms/GraphAPI.h"
#include "../Graph_algorithms/Graph.h"

using std::vector;
using algorithms_on_graphs::Graph;
using namespace QtCharts;

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private:
    Ui::GraphWindow *ui;
    QChartView* chart;
    Graph graph;
    vector<pair<double, double> > vertices_coordinates;
    vector<QLineSeries*> connection_series;
    QString graph_name;


    void get_graph_from_api();
    void add_dots_on_chart();
    void add_lines_on_chart();
    void axis_and_legend_setup();

};

#endif // GRAPHWINDOW_H
