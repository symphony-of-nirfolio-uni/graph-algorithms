#include "graphwindow.h"
#include "ui_graphwindow.h"

#include <iostream>

GraphWindow::GraphWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);
    graph = GraphAPI::instance.get_graph("test.dat");
    vertices_coordinates = GraphAPI::instance.get_vertices_coodrdinates("test.dat");
    chart = new QChartView(this);

    QScatterSeries* vertices_series = new QScatterSeries;
    //vertices_series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    for(auto vertex_coordinate : vertices_coordinates)
    {
        *vertices_series << QPointF(vertex_coordinate.first, vertex_coordinate.second);
    }

    vertices_series->setColor(QColor(0,0,255));
    for(unsigned current_vertex_id = 0; current_vertex_id < graph.graph.size(); ++current_vertex_id)
    {
        auto adjacent_vertices_list = graph.graph[current_vertex_id];
        for(auto adjacent_vertex : adjacent_vertices_list)
        {
            unsigned adjacent_vertex_id = unsigned(adjacent_vertex.first);
            connection_series.push_back(new QLineSeries());
            std::cout << current_vertex_id << ' ' << adjacent_vertex_id << '\n';
            if(vertices_coordinates[current_vertex_id].first <  vertices_coordinates[adjacent_vertex_id].first)
            {
                std::cout << vertices_coordinates[current_vertex_id].first << ' ' << vertices_coordinates[current_vertex_id].second << ' ' << vertices_coordinates[adjacent_vertex_id].first << ' ' << vertices_coordinates[adjacent_vertex_id].second << '\n';

                *(connection_series.back()) << QPointF(vertices_coordinates[current_vertex_id].first, vertices_coordinates[current_vertex_id].second) << QPointF(vertices_coordinates[adjacent_vertex_id].first, vertices_coordinates[adjacent_vertex_id].second);
                connection_series.back()->setColor(QColor(255,0,0));
                chart->chart()->addSeries(connection_series.back());
            }

        }
    }
    chart->chart()->addSeries(vertices_series);


    chart->chart()->createDefaultAxes();
    chart->chart()->setDropShadowEnabled(false);
    chart->chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);


    chart->chart()->axisX()->setRange(-5,15);
    chart->chart()->axisY()->setRange(-5,20);
    chart->chart()->axisX()->hide();
    chart->chart()->axisY()->hide();
    chart->chart()->legend()->hide();

    this->setCentralWidget(chart);



}

GraphWindow::~GraphWindow()
{
    delete ui;
}
