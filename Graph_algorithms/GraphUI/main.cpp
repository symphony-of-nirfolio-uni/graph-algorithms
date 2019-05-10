#include "mainwindow.h"
#include "messagedialog.h"
#include <QApplication>
#include <exception>


int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        a.exec();
        std::terminate();
    } catch (std::exception e) {
        MessageDialog *win = new MessageDialog(QString::fromStdString(e.what()));
        win->exec();
    }{}
    return 0;
}
