#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qtimer=new QTimer(this);
    connect(qtimer,&QTimer::timeout,[=](){
        static int t=0;
        this->ui->lcdNumber_3->display(t++);
    });

  }

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    this->tId=startTimer(1000);
    qDebug()<<"tId= "<<this->tId;

}


void Widget::on_stopButton_clicked()
{
    this->killTimer(this->tId);
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int t=1;
    static int t2=1;
    // qDebug()<<event->timerId();
    if(event->timerId()==this->tId){
        ui->lcdNumber->display(t++);
    }else if(event->timerId()==tId2){
        ui->lcdNumber_2->display(t2++);
    }
}


void Widget::on_startButton_2_clicked()
{
    this->tId2=       startTimer(100);
    qDebug()<<"tId2= "<<this->tId2;

}


void Widget::on_stopButton_2_clicked()
{
    this->killTimer(this->tId2);

}


void Widget::on_startButton_3_clicked()
{

    qtimer->start();
}


void Widget::on_stopButton_3_clicked()
{
    qtimer->stop();

}

