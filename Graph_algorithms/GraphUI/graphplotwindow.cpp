#include "graphplotwindow.h"
#include "ui_graphplotwindow.h"
#include "../GraphUI/Factories/linefactory.h"

GraphPlotWindow::GraphPlotWindow(QString graph_file_name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphPlotWindow)
{
    ui->setupUi(this);

    graph_name = graph_file_name + ".dat";
    timer = new QTimer();
    setWindowTitle(graph_file_name);
    scatter_radius = 50;

    get_graph_from_api();
    add_lines_on_chart();
    add_dots_on_chart();

    axis_and_legend_setup();
    this->setCentralWidget(plot);
    setup_update_timer();

}

void GraphPlotWindow::get_graph_from_api()
{
    graph = GraphAPI::instance().get_graph(graph_name.toStdString());
    vertices_coordinates = GraphAPI::instance().get_vertices_coordinates(graph_name.toStdString());
    plot = new QCustomPlot(this);

    scatter_radius = graph.get_size() < 30 ? 50 : 13;
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
    make_scatter(dots, Qt::blue, scatter_radius);
    dots->setData(x, y);

    plot->addGraph();
    highlighted = plot->graph(plot->graphCount() - 1);
    make_scatter(highlighted, Qt::green, scatter_radius);

    plot->addGraph();
    used = plot->graph(plot->graphCount() - 1);
    make_scatter(used, Qt::darkGray, scatter_radius);

    plot->addGraph();
    black = plot->graph(plot->graphCount() - 1);
    make_scatter(black, Qt::black, scatter_radius);

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
    int i = 0;
    for(auto vertex_coordinate : vertices_coordinates)
    {
        QCPItemText *textLabel = new QCPItemText(plot);
        textLabel->position->setCoords(vertex_coordinate.x, vertex_coordinate.y);
        textLabel->setText(QString::number(i++));
        if(graph.get_size() < 30)
        {
            textLabel->setFont(QFont(font().family(), 16));
        }
        else
        {
            textLabel->setFont(QFont(font().family(), 10));
        }
        //textLabel->setSelectedPen(QPen(Qt::white));
        textLabel->setColor(Qt::white);
    }
}

void GraphPlotWindow::make_scatter(QCPGraph* graph, QColor color, double radius)
{
    graph->setLineStyle(QCPGraph::lsNone);
    graph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, color, color, radius));

}

void GraphPlotWindow::setup_update_timer()
{
    timer->setInterval(200);
    timer->start();

    connect(timer,SIGNAL(timeout()), this, SLOT(update_graph()));
}

void GraphPlotWindow::add_used_vertex(unsigned vertex)
{
    used->addData(vertices_coordinates[vertex].x, vertices_coordinates[vertex].y);
}

void GraphPlotWindow::add_black_vertex(unsigned vertex)
{
    black->addData(vertices_coordinates[vertex].x, vertices_coordinates[vertex].y);
}

void GraphPlotWindow::make_highlighted(unsigned vertex)
{
    highlighted->setData({vertices_coordinates[vertex].x}, {vertices_coordinates[vertex].y});
}

void GraphPlotWindow::update_graph()
{
    auto h = GraphAPI::instance().get_current_highlighted();
    make_highlighted(h);

    auto u = GraphAPI::instance().get_used_marked();
    for(unsigned i = unsigned(used_v.size()); i < u.size(); ++i)
    {
        add_used_vertex(u[i]);
    }
    auto b = GraphAPI::instance().get_black_marked();
    for(unsigned i = unsigned(black_v.size()); i < b.size(); ++i)
    {
        add_black_vertex(b[i]);
    }
    plot->replot();

}

GraphPlotWindow::~GraphPlotWindow()
{
    delete ui;
}
