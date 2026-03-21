#include "hellowidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HelloWidget w;
    w.show();
    return QCoreApplication::exec();
}
