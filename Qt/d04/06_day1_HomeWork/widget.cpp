#include "widget.h"
#include<QPushButton>
#include<QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(500,400);
    this->setWindowTitle("視窗一");
    widge2=new Widge2;
    QPushButton *btn1=new  QPushButton("視窗二",this);
    QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(btn1);
    this->setLayout(layout);
    connect(btn1,&QPushButton::clicked,this,[=](){
        //顯示視窗二
        widge2->show();
       //隱藏視窗一
        this->hide();
    });
    connect(widge2,&Widge2::btn2Clicked,this,[=](){
        //收到第二个按钮点击的信号就将第二个窗口隐藏并且将自己显示出来
        this->show();
        widge2->hide();
    });


}

Widget::~Widget(){
    delete widge2;
}
