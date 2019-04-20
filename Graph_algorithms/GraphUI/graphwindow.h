#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QDialog>
#include <QtQml>
#include <QtCharts>
#include <vector>

using std::vector;
using namespace QtCharts;

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr);
    ~GraphWindow();

private:
    Ui::GraphWindow *ui;
    QChartView* chart;
    vector<QPointF> vertices;
};

#endif // GRAPHWINDOW_H
