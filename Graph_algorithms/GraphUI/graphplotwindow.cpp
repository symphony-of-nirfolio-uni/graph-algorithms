#include "graphplotwindow.h"
#include "ui_graphplotwindow.h"
#include "../GraphUI/Factories/linefactory.h"

GraphPlotWindow::GraphPlotWindow(QString graph_file_name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphPlotWindow)
{
    ui->setupUi(this);

    graph_name = graph_file_name + ".dat";
    setWindowTitle(graph_file_name);
    scatter_radius = 50;

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

    scatter_radius = graph.get_size() < 30 ? 50 : 5;
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
    dots->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, Qt::blue, Qt::blue, scatter_radius));

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

            QPointF from = {vertices_coordinates[current_vertex_id].x, vertices_coordinates[current_vertex_id].y};
            QPointF to = {vertices_coordinates[adjacent_vertex_id].x, vertices_coordinates[adjacent_vertex_id].y};

            if(graph.is_direct())
            {
                QCPItemLine *arrow = LineFactory::get_line_between_dots(plot, from, to, Qt::red, scatter_radius, scatter_radius);
                arrows.push_back(arrow);
                arrow->setHead(QCPLineEnding::esLineArrow);//esSpikeArrow);
                //QCPItemLine *arrow = new QCPItemLine(plot);
                //arrow->start->setParentAnchor(data->at(current_vertex_id));
                //arrow->end->setParentAnchor();
            }
            else
            {
                if(current_vertex_id < adjacent_vertex_id)
                {
                    QCPItemLine *line = LineFactory::get_line_between_dots(plot, from, to, Qt::red, scatter_radius, scatter_radius);
                    lines.push_back(line);
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

    plot->xAxis->setVisible(false);
    plot->yAxis->setVisible(false);
}

GraphPlotWindow::~GraphPlotWindow()
{
    delete ui;
}
