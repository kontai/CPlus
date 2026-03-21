#include "widget.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn=new QPushButton("按鈕",this);
    this->setGeometry(500,500,500,300);
    // btn->setFixedSize(200,200);
    btn->resize(250,150);

    // btn->show();
    connect(btn,&QPushButton::clicked,this,&Widget::close);

}

Widget::~Widget() = default;
