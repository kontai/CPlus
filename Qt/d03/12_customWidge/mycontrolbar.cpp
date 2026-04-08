#include "mycontrolbar.h"
#include "ui_mycontrolbar.h"
#include<qDebug>

MyControlBar::MyControlBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyControlBar)
{
    ui->setupUi(this);
    //設置最大/最小值
    ui->horizontalSlider->setRange(0,100);
    ui->spinBox->setRange(0,100);
    //利用水平條調整數值
    connect(ui->horizontalSlider,&QSlider::sliderMoved,[=](int a){
        ui->spinBox->setValue(a);
    });
    //更改數值，水平條同步調整
    connect(ui->spinBox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->horizontalSlider,&QSlider::setValue);
}

MyControlBar::~MyControlBar()
{
    delete ui;
}

void MyControlBar::on_pushButton_clicked()
{
    qDebug()<< ui->spinBox->value();
}


void MyControlBar::on_pushButton_2_clicked()
{
    ui->spinBox->setValue(50);
}

