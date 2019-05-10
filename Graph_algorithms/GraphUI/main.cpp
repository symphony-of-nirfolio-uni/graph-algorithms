#include "mainwindow.h"
#include "messagedialog.h"
#include <QApplication>
#include <exception>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
