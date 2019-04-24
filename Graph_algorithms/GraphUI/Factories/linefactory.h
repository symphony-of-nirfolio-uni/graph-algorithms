#ifndef LINEFACTORY_H
#define LINEFACTORY_H

#include "../QtCustomPlot/QCustomPlot.h"
#include <QPointF>
#include <QColor>


class LineFactory
{
    LineFactory();
    static QCPItemLine* create_line(QCustomPlot* parent, QPointF point_from, QPointF point_to, QColor color);
public:
    static QCPItemLine* get_line(QCustomPlot* parent, QPointF point_from, QPointF point_to, QColor color);
    static QCPItemLine* get_line_between_dots(QCustomPlot* parent, QPointF point_from, QPointF point_to, QColor color, double r1, double r2);
    static void change_dot_radius(QCPItemLine* line, double r1, double r2);
};


#endif // LINEFACTORY_H
