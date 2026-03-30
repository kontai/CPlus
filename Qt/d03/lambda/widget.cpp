#include "widget.h"
#include<QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    int a=10;
    int b=20;



    [=](){
        //lmabda直傳遞預設是const
        // a=5;
        // b=10;
        qDebug()<<a<<b;
    }();
    [&](){
        qDebug()<<a<<b;
    }();

    QPushButton *btn=new QPushButton("按鈕1",this);
    connect(btn,&QPushButton::clicked,
            [=](){
                qDebug()<<a<<b;
    });

    connect(btn,&QPushButton::clicked,
            [&](){
                qDebug()<<a<<b;
    });

}

Widget::~Widget() = default;
