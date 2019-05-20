#ifndef LOADGRAPHDIALOG_H
#define LOADGRAPHDIALOG_H

#include <QDialog>
#include "graphplotwindow.h"

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

signals:
    void new_window(GraphPlotWindow*);
};

#endif // LOADGRAPHDIALOG_H
