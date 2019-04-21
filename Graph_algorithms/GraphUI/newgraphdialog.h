#ifndef NEWGRAPHDIALOG_H
#define NEWGRAPHDIALOG_H

#include <QDialog>

namespace Ui {
class NewGraphDialog;
}

class NewGraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewGraphDialog(QWidget *parent = nullptr);
    ~NewGraphDialog();

private:
    Ui::NewGraphDialog *ui;
};

#endif // NEWGRAPHDIALOG_H
