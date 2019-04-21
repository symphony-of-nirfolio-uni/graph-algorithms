#ifndef LOADGRAPHDIALOG_H
#define LOADGRAPHDIALOG_H

#include <QDialog>

namespace Ui {
class LoadGraphDialog;
}

class LoadGraphDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadGraphDialog(QWidget *parent = nullptr);
    ~LoadGraphDialog();

private:
    Ui::LoadGraphDialog *ui;
    QWidget *parent;

    void load_graphs();

private slots:
    void create_graph_visualisation();
};

#endif // LOADGRAPHDIALOG_H
