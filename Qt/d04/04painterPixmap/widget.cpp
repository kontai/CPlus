#include "widget.h"
#include "ui_widget.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->imgPos=0;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event)
{
    //劃製現有圖片
    QPainter painter(this);
    QPixmap pixmap(":/image/Visual_Studio_Icon_2026.svg.png");
    painter.drawPixmap(this->imgPos,0,pixmap);

}


void Widget::on_pushButton_clicked()
{
    this->imgPos+=10;
    this->repaint();
    this->update();
}

