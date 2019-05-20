#include "graphplotwindow.h"
#include "ui_graphplotwindow.h"
#include "../GraphUI/Factories/linefactory.h"
#include "messagedialog.h"
#include "startenddialog.h"

GraphPlotWindow::GraphPlotWindow(QString graph_file_name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphPlotWindow)
{
    ui->setupUi(this);

    _is_closed = false;
    current_status = preparing;
    graph_name = graph_file_name + ".dat";
    timer = new QTimer();
    time_registrer = new QTime();
    setWindowTitle(graph_file_name);
    scatter_radius = 50;
    //connect(this, SIGNAL(close()), this, SLOT(end_algo()));

    get_graph_from_api();
    add_lines_on_chart();
    add_dots_on_chart();

    axis_and_legend_setup();
    ui->plot->setWidget(plot);
    setup_update_timer();
    setup_buttons();
    setup_algo_list();
    setup_slider();

}

void GraphPlotWindow::get_graph_from_api()
{
    graph = GraphAPI::instance().get_graph(graph_name.toStdString());
    vertices_coordinates = GraphAPI::instance().get_vertices_coordinates(graph_name.toStdString());
    plot = new QCustomPlot(this);

    scatter_radius = graph.size() < 30 ? 50 : 13;
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
    used = plot->graph(plot->graphCount() - 1);
    make_scatter(used, Qt::darkGray, scatter_radius);

    plot->addGraph();
    black = plot->graph(plot->graphCount() - 1);
    make_scatter(black, Qt::black, scatter_radius);

    plot->addGraph();
    highlighted = plot->graph(plot->graphCount() - 1);
    make_scatter(highlighted, Qt::green, scatter_radius);

}

void GraphPlotWindow::add_lines_on_chart()
{

    for(unsigned current_vertex_id = 0; current_vertex_id < graph.size(); ++current_vertex_id)
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
        if(graph.size() < 30)
        {
            textLabel->setFont(QFont(font().family(), 16));
        }
        else
        {
            textLabel->setFont(QFont(font().family(), 10));
        }
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
    timer->setInterval(5000);
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(update_timer(int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(update_graph()));

}
void GraphPlotWindow::update_timer(int slider_progres)
{
    timer->stop();
    if(slider_progres != 0)
    {

        timer->setInterval(5000/slider_progres);
        if(current_status == working)
        {
            timer->start();
        }
    }
}

void GraphPlotWindow::end_timer()
{
    timer->stop();
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

void GraphPlotWindow::setup_buttons()
{
    connect(ui->next_step_button, SIGNAL(clicked()), this, SLOT(update_graph()));
    connect(ui->choose_algo_button, SIGNAL(clicked()), this, SLOT(choose_algo()));
    connect(ui->stop_button, SIGNAL(clicked()), this, SLOT(end_algo()));
    connect(ui->start_algo_button,  SIGNAL(clicked()), this, SLOT(start_algo()));
}

void GraphPlotWindow::setup_algo_list()
{
    ui->algo_list->addItems({"Graph_is_connected", "Graph_is_acyclic", "Finding_shortest_path"});
}

void GraphPlotWindow::setup_slider()
{
    ui->speedSlider->setTickInterval(10);
}

void GraphPlotWindow::update_status()
{
    GraphAPI::instance().continue_algo();
}

void GraphPlotWindow::get_algo_result()
{
    algo_result = QString::fromStdString(GraphAPI::instance().get_result());
}

void GraphPlotWindow::get_algo_stats()
{
    QString algo_name = ui->algo_list->currentText();
    auto algo_enum = get_algo_enum(algo_name);
    algo_stats = "Stats:\n";
    if(algo_enum == GraphAPI::Finding_shortest_path)
    {
        algo_stats += "Time: " + QString::fromStdString(GraphAPI::instance().get_time_of_work(algo_enum, graph, algo_start, algo_end)) + "\n";
        //algo_stats += "RAM: " + QString::fromStdString(GraphAPI::instance().get_RAM_usage(algo_enum, graph, algo_start, algo_end)) + "\n";
    }
    else
    {
        algo_stats += "Time: " + QString::fromStdString(GraphAPI::instance().get_time_of_work(algo_enum, graph)) + "\n";
        //algo_stats += "RAM: " + QString::fromStdString(GraphAPI::instance().get_RAM_usage(algo_enum, graph)) + "\n";
    }

}

GraphAPI::Algorithm GraphPlotWindow::get_algo_enum(QString algo_name)
{
    if(algo_name == "Finding_shortest_path")
    {

        return GraphAPI::Algorithm::Finding_shortest_path;
    }
    else if(algo_name == "Graph_is_acyclic")
    {
        return GraphAPI::Algorithm::Graph_is_acyclic;
    }
    else if(algo_name == "Graph_is_connected")
    {
        return GraphAPI::Algorithm::Graph_is_connected;
    }
}

void GraphPlotWindow::dots_reset()
{
    used->setData({},{});
    black->setData({},{});
    highlighted->setData({},{});
    used_v.clear();
    black_v.clear();
    plot->replot();
}

void GraphPlotWindow::exec_message_dialog(QString message)
{
    MessageDialog *dialog = new MessageDialog(message, this);
    dialog->exec();
}

void GraphPlotWindow::update_graph()
{
    if(current_status == working)
    {
        if(GraphAPI::instance().algorithm_is_ended())
        {

            get_algo_result();
            end_algo();
        }
        else
        {
            update_highlighted();
            update_used();
            update_black();
            plot->replot();
            update_status();
        }
    }
    else
    {
        QString message;
        if(current_status == preparing)
        {
            message = "Choose your algorithm.";
        }
        else
        {
            message = "Algorithm ended with result:\n" + algo_result + "\n" + algo_stats;
        }
        exec_message_dialog(message);
    }


}

void GraphPlotWindow::update_highlighted()
{
    auto h = GraphAPI::instance().get_current_highlighted();
    make_highlighted(h);
}

void GraphPlotWindow::update_used()
{
    auto u = GraphAPI::instance().get_used_marked();
    for(unsigned i = unsigned(used_v.size()); i < u.size(); ++i)
    {
        used_v.push_back(i);
        add_used_vertex(u[i]);
    }
}

void GraphPlotWindow::update_black()
{
    auto b = GraphAPI::instance().get_black_marked();
    for(unsigned i = unsigned(black_v.size()); i < b.size(); ++i)
    {
        black_v.push_back(i);
        add_black_vertex(b[i]);
    }
}

void GraphPlotWindow::choose_algo()
{
    if(current_status != working)
    {
        ui->algo_name_label->setText(ui->algo_list->currentText());
        start_algo();
    }
}

void GraphPlotWindow::start_algo()
{
    QString algo_name = ui->algo_name_label->text();
    if(current_status != working)
    {
        QString algo_name = ui->algo_name_label->text();
        if(algo_name == "None")
        {
            QString message = "Choose your algorithm.";
            exec_message_dialog(message);
            return;
        }
        auto algo_enum = get_algo_enum(algo_name);
        if(algo_name == "Finding_shortest_path")
        {

            auto dialog = new StartEndDialog(this);
            connect(dialog, SIGNAL(got_data(unsigned,unsigned)), this, SLOT(get_start_end(unsigned,unsigned)));
            dialog->exec();
            GraphAPI::instance().start_algorithm(algo_enum, graph, algo_start, algo_end);
        }
        else if(algo_name == "Graph_is_acyclic")
        {
            GraphAPI::instance().start_algorithm(algo_enum, graph);
        }
        else if(algo_name == "Graph_is_connected")
        {
            GraphAPI::instance().start_algorithm(algo_enum, graph);
        }

        ui->algo_name_label->setText(algo_name);
        algo_result = "None";

        if(current_status == ended)
        {
            dots_reset();
        }

        get_algo_stats();
        time_registrer->restart();
        current_status = working;

    }
    else
    {
        QString message = "Algorithm is still working. Stop it before change.";
        exec_message_dialog(message);
    }
}

void GraphPlotWindow::end_algo()
{
    end_timer();
    end_algo_mute();
    time_registrer->elapsed();
    QString ui_status = "Program work time: " + QString::number(double(time_registrer->elapsed())/1000) + " seconds";
    exec_message_dialog("Algorithm ended with result:\n" + algo_result + "\n" + algo_stats + "\n" + ui_status);
}

void GraphPlotWindow::end_algo_mute()
{
    GraphAPI::instance().end_of_the_algorithm();
    current_status = ended;
}

void GraphPlotWindow::get_start_end(unsigned start, unsigned end)
{
    algo_start = start;
    algo_end = end;
}

void GraphPlotWindow::closeEvent(QCloseEvent*)
{
    end_algo_mute();
    delete dots;
    delete used;
    delete black;
    delete highlighted;
    delete timer;
    _is_closed = true;
}

GraphPlotWindow::~GraphPlotWindow()
{
    delete ui;
}

bool GraphPlotWindow::is_closed()
{
    return _is_closed;
}
