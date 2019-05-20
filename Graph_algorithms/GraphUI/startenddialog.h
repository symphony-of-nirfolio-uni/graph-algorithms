#ifndef STARTENDDIALOG_H
#define STARTENDDIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class StartEndDialog;
}

class StartEndDialog : public QDialog, public QCloseEvent
{
    Q_OBJECT

public:
    explicit StartEndDialog(QWidget *parent = nullptr);
    ~StartEndDialog();

private:
    Ui::StartEndDialog *ui;

private slots:
    void confirm();

signals:
    void got_data(unsigned, unsigned);
};

#endif // STARTENDDIALOG_H
