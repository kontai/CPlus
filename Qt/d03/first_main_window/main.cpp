#include "mainwindow.h"

#include <QApplication>
#include <QMenuBar>
#include<QToolBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return QCoreApplication::exec();
}
