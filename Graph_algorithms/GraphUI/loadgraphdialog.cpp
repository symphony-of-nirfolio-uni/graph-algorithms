#include "loadgraphdialog.h"
#include "ui_loadgraphdialog.h"
#include "graphwindow.h"
#include <QDir>

LoadGraphDialog::LoadGraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadGraphDialog)
{
    ui->setupUi(this);
    this->parent = parent;

    load_graphs();

    connect(ui->loadGraphButton, SIGNAL(clicked()), this, SLOT(create_graph_visualisation()));
}

LoadGraphDialog::~LoadGraphDialog()
{
    delete ui;
}

void LoadGraphDialog::load_graphs()
{
    QDir *dir = new QDir("../Graph_algorithms/Graph_data/Data");
    auto list = dir->entryInfoList();
    for(auto file : list)
    {
        if(file.suffix() == "dat")
            ui->graphList->addItem(file.baseName());
    }
    ui->graphList->addItem("test");

    ui->graphList->setCurrentItem((ui->graphList->item(0)));
}

void LoadGraphDialog::create_graph_visualisation()
{

    //GraphWindow* window_1 = new GraphWindow(ui->graphList->currentItem()->text(), parent);
    //window_1->show();

    GraphPlotWindow* window_2 = new GraphPlotWindow(ui->graphList->currentItem()->text(), parent);
    new_window(window_2);
    this->close();
}
