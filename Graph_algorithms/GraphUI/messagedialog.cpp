#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog::MessageDialog(QString message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    ui->message->setText(message);
    connect(ui->ok_button, SIGNAL(clicked()), this, SLOT(close()));
}

MessageDialog::~MessageDialog()
{
    delete ui;
}
