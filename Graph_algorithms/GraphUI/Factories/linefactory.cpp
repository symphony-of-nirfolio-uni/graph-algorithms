#include "linefactory.h"
#include <cmath>

LineFactory::LineFactory()
{

}

QCPItemLine *LineFactory::create_line(QCustomPlot* parent, QPointF point_from, QPointF point_to, QColor color)
{
    QCPItemLine *line = new QCPItemLine(parent);
    line->start->setCoords(point_from);
    line->end->setCoords(point_to);
    line->setPen(QPen(color));
    return line;
}

QCPItemLine *LineFactory::get_line(QCustomPlot *parent, QPointF point_from, QPointF point_to, QColor color)
{
    return create_line(parent, point_from, point_to, color);
}

QCPItemLine *LineFactory::get_line_between_dots(QCustomPlot *parent, QPointF point_from, QPointF point_to, QColor color, double r1, double r2)
{
    double delta_x = point_to.x() - point_from.x();
    double delta_y = point_to.y() - point_from.y();
    double dist = sqrt(delta_x*delta_x + delta_y*delta_y);
    double sin = delta_y / dist;
    double cos = delta_x / dist;
    r1 /= 10;
    r2 /= 10;
    QPointF from = QPointF(point_from.x() + r1*cos, point_from.y() + r1*sin);
    QPointF to = QPointF(point_to.x() - r2*cos, point_to.y() - r2*sin);
    return create_line(parent, from, to, color);
}

void LineFactory::change_dot_radius(QCPItemLine *line, double r1, double r2)
{
    QPointF point_from = line->start->coords();
    QPointF point_to = line->end->coords();
    double delta_x = point_to.x() - point_from.x();
    double delta_y = point_to.y() - point_from.y();
    double dist = sqrt(delta_x*delta_x + delta_y*delta_y);
    double sin = delta_y / dist;
    double cos = delta_x / dist;
    QPointF from = QPointF(point_from.x() + r1*cos, point_from.y() + r1*sin);
    QPointF to = QPointF(point_to.x() - r2*cos, point_to.y() - r2*sin);
    line->start->setCoords(from);
    line->end->setCoords(to);
}
