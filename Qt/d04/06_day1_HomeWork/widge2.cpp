#include "widge2.h"
#include<QPushButton>

Widge2::Widge2(QWidget *parent)
    : QWidget{parent}
{

    this->resize(500,400);
    this->setWindowTitle("視窗二");
    QPushButton *btn2=new  QPushButton("視窗一",this);
    connect(btn2,&QPushButton::clicked,[=](){
        emit btn2Clicked();
    });
}
