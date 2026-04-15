#include "mypushbutton.h"
#include<QDebug>

myPushButton::myPushButton(QWidget *parent)
    : QPushButton{parent}
{}

void myPushButton::paintEvent(QPaintEvent *event)
{
    static int a=0;
    qDebug()<<a++;
    // QPushButton::paintEvent(event);
}
