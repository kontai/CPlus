#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_checkBox_clicked()
{
    // qDebug()<<ui->checkBox->checkState();
}


void Widget::on_checkBox_stateChanged(int arg1)
{
    qDebug()<<arg1;
}

