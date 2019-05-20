#include "startenddialog.h"
#include "ui_startenddialog.h"

StartEndDialog::StartEndDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartEndDialog)
{
    ui->setupUi(this);
    connect(ui->confirmButton, SIGNAL(clicked()), this, SLOT(confirm()));
}

StartEndDialog::~StartEndDialog()
{
    delete ui;
}

void StartEndDialog::confirm()
{
    got_data(ui->start_edit->text().toUInt(), ui->end_edit->text().toUInt());
    this->close();
}
