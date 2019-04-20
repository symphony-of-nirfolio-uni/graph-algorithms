#include "chartview.h"
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>

ChartView::ChartView(QWidget *parent) :
    QChartView(new QChart(), parent)
{
    QScatterSeries* series0 = new QScatterSeries();
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->append(0, 6);
    series0->append(2, 4);
    series0->append(3, 8);
    series0->append(7, 4);
    series0->append(10, 5);

    QLineSeries* series1 = new QLineSeries();
    series1->append(0, 6);
    series1->append(2, 4);

    QLineSeries* series2 = new QLineSeries();
    series2->append(7, 4);
    series2->append(10, 5);

    setRenderHint(QPainter::Antialiasing);
    chart()->addSeries(series1);
    chart()->addSeries(series2);
    chart()->addSeries(series0);

    chart()->setTitle("Graph");
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);
    chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);


    chart()->axisX()->setRange(qreal(-5),qreal(15));
    chart()->axisY()->setRange(qreal(-1),qreal(11));

    chart()->axisX()->hide();
    chart()->axisY()->hide();


    chart()->legend()->hide();
}

ChartView::~ChartView()
{

}
