#include "widget.h"


   Widget:: Widget(const QString &windowTitle,const QString &btnTitle ,QWidget *parent){

        //設置屬性
        this->setWindowTitle(windowTitle);
        this->resize(500,300);

        //創建按鈕
        QPushButton *btn=new QPushButton(btnTitle,this);
        connect(btn,&QPushButton::clicked,this,&Widget::switchWindow);
   }


Widget::~Widget() = default;
