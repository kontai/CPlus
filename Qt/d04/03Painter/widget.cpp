#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

#include <QPainter>

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

void Widget::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);

    //移動畫筆
    painter.translate(100,0);

    //創建筆刷
    QPen pen;

    //設置線條寬度
    pen.setWidth(3);

    //設置線條顏色
    pen.setColor(QColor(255,0,0));

    //設置線型
    pen.setStyle(Qt::DashLine);

    //需要填充，使用筆刷
    QBrush brush;

    //填充顏色
    brush.setColor(Qt::yellow);

    //設置風格(預設NoBrush)
    brush.setStyle(Qt::CrossPattern);

    //使用筆刷
    painter.setPen(pen);

    //使用填充
    // painter.setBrush(Qt::yellow);
    painter.setBrush(brush);

    //劃線
    painter.drawLine(0,0,100,100);

    //劃方型
    painter.drawRect(20,20,50,50);

    //劃圓
    painter.drawEllipse(QPoint(100,100),50,50);

    //劃文字
    painter.drawText(200,100,"這是一排文字");

}

