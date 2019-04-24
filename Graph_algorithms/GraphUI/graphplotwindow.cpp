#include "graphplotwindow.h"
#include "ui_graphplotwindow.h"

GraphPlotWindow::GraphPlotWindow(QString graph_file_name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphPlotWindow)
{
    ui->setupUi(this);

    graph_name = graph_file_name + ".dat";
    setWindowTitle(graph_file_name);

    get_graph_from_api();
    add_lines_on_chart();
    add_dots_on_chart();
    axis_and_legend_setup();
    this->setCentralWidget(plot);
}

void GraphPlotWindow::get_graph_from_api()
{
    graph = GraphAPI::instance().get_graph(graph_name.toStdString());
    vertices_coordinates = GraphAPI::instance().get_vertices_coordinates(graph_name.toStdString());
    plot = new QCustomPlot(this);
}

void GraphPlotWindow::add_dots_on_chart()
{
    plot->addGraph();

    dots = plot->graph(plot->graphCount() - 1);
    QVector<double> x, y;
    for(auto vertex_coordinate : vertices_coordinates)
    {
        x.push_back(vertex_coordinate.x);
        y.push_back(vertex_coordinate.y);
    }

    dots->setLineStyle(QCPGraph::lsNone);
    dots->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::blue, 10));

    dots->setData(x, y);

}

void GraphPlotWindow::add_lines_on_chart()
{
    for(unsigned current_vertex_id = 0; current_vertex_id < graph.get_size(); ++current_vertex_id)
    {
        auto adjacent_vertices_list = graph.at(current_vertex_id);
        for(auto adjacent_vertex : adjacent_vertices_list.adjacent())
        {
            unsigned adjacent_vertex_id = unsigned(adjacent_vertex);

            if(graph.is_direct())
            {
                QCPItemLine *arrow = new QCPItemLine(plot);
                arrows.push_back(arrow);
                arrow->start->setCoords(vertices_coordinates[current_vertex_id].x, vertices_coordinates[current_vertex_id].y);
                arrow->end->setCoords(vertices_coordinates[adjacent_vertex_id].x, vertices_coordinates[adjacent_vertex_id].y);
                arrow->setHead(QCPLineEnding::esSpikeArrow);
            }
            else
            {
                if(current_vertex_id < adjacent_vertex_id)
                {
                    plot->addGraph();
                    lines.push_back(plot->graph(plot->graphCount() - 1));
                    auto current_line = lines.back();
                    current_line->addData({vertices_coordinates[current_vertex_id].x, vertices_coordinates[adjacent_vertex_id].x},
                    {vertices_coordinates[current_vertex_id].y, vertices_coordinates[adjacent_vertex_id].y});
                }
            }

        }
    }
}

void GraphPlotWindow::axis_and_legend_setup()
{
    plot_min = -5; // hardcoded, maybe need to change
    plot_max = 105;

    plot->xAxis->setRange(plot_min, plot_max);
    plot->yAxis->setRange(plot_min, plot_max);
}

GraphPlotWindow::~GraphPlotWindow()
{
    delete ui;
}
