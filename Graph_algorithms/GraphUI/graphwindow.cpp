#include "graphwindow.h"
#include "ui_graphwindow.h"

GraphWindow::GraphWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphWindow)
{
    ui->setupUi(this);

    chart = new QChartView(this);

}

GraphWindow::~GraphWindow()
{
    delete ui;
}
