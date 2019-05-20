#ifndef GRAPHPLOTWINDOW_H
#define GRAPHPLOTWINDOW_H

#include <QMainWindow>
#include <QDialog>
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

class GraphPlotWindow : public QDialog, public QCloseEvent
{
    Q_OBJECT

public:
    explicit GraphPlotWindow(QString graph_file_name, QWidget *parent = nullptr);
    ~GraphPlotWindow();

    bool is_closed();

private:
    enum status {preparing, working, ended};
    Ui::GraphPlotWindow *ui;

    QCustomPlot* plot;
    Graph graph;
    vector<Point> vertices_coordinates;

    bool _is_closed;

    QCPGraph *dots;
    QCPGraph *used;
    QCPGraph *black;
    QCPGraph *highlighted;
    vector<QCPItemLine*> lines;
    vector<QCPItemLine*> arrows;
    QTimer *timer;
    QTime *time_registrer;
    vector<unsigned> black_v;
    vector<unsigned> used_v;
    status current_status;

    unsigned algo_start;
    unsigned algo_end;




    QString graph_name;
    QString algo_result;
    QString algo_stats;
    double scatter_radius;
    int plot_min;
    int plot_max;

    void get_graph_from_api();
    void add_dots_on_chart();
    void add_lines_on_chart();
    void axis_and_legend_setup();
    void make_scatter(QCPGraph* graph, QColor color, double radius);
    void setup_update_timer();
    void setup_buttons();
    void setup_algo_list();
    void setup_slider();
    void add_used_vertex(unsigned vertex);
    void add_black_vertex(unsigned vertex);
    void make_highlighted(unsigned vertex);
    void update_status();
    void get_algo_result();
    void get_algo_stats();
    GraphAPI::Algorithm get_algo_enum(QString algo_name);

    void dots_reset();

    void exec_message_dialog(QString message);


private slots:
    void update_graph();
    void update_timer(int);
    void end_timer();

    void update_highlighted();
    void update_used();
    void update_black();

    void choose_algo();
    void start_algo();
    void end_algo();
    void end_algo_mute();

    void get_start_end(unsigned, unsigned);

    void closeEvent(QCloseEvent*);
};

#endif // GRAPHPLOTWINDOW_H
