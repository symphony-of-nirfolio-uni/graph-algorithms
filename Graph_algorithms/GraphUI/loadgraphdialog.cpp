#include "loadgraphdialog.h"
#include "ui_loadgraphdialog.h"
#include "graphwindow.h"

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
    ui->graphList->addItem("test");

    ui->graphList->setCurrentItem((ui->graphList->item(0)));
}

void LoadGraphDialog::create_graph_visualisation()
{

    GraphWindow* window = new GraphWindow(ui->graphList->currentItem()->text(), parent);
    window->show();
    this->close();
}
