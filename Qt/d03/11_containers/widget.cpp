#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_pushButton_13_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}

