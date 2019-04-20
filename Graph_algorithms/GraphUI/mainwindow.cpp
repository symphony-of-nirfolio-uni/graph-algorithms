#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Graph_algorithms/GraphAPI.h"
#include "graphwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    //GraphAPI::instance;

    connect(ui->newGraphButton,SIGNAL(clicked()), this, SLOT(show_graph_window()));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::show_graph_window()
{
    chartView = new ChartView();
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
}
