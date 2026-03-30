#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w("win1","btn1");
    Widget w2("視窗二","按下顯示另一個視窗");
    //連接信號
    QObject::connect(&w,&Widget::switchWindow,&w,&QWidget::hide);
    QObject::connect(&w,&Widget::switchWindow,&w2,&QWidget::show);

    QObject::connect(&w2,&Widget::switchWindow,&w2,&QWidget::hide);
    QObject::connect(&w2,&Widget::switchWindow,&w,&QWidget::show);
    w.show();
    return QCoreApplication::exec();
}
