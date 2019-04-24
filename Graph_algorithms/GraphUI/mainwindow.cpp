#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../Graph_algorithms/GraphAPI/GraphAPI.h"
#include "graphwindow.h"
#include "loadgraphdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    connect(ui->loadGraphButton, SIGNAL(clicked()), this, SLOT(load_graph_dialog()));
    connect(ui->newGraphButton, SIGNAL(clicked()), this, SLOT(show_graph_window()));
    }

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::show_graph_window()
{
    windows.back()->resize(400, 300);
    windows.back()->show();
}

void MainWindow::load_graph_dialog()
{
    LoadGraphDialog* dialog = new LoadGraphDialog();
    connect(dialog,SIGNAL(new_window(GraphPlotWindow*)), this, SLOT(get_new_window(GraphPlotWindow*)));
    dialog->exec();
}

void MainWindow::get_new_window(GraphPlotWindow* window)
{
    windows.push_back(window);
    window->show();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    for(unsigned i = 0; i < windows.size(); ++i)
    {
        windows[i]->close();
    }
}
