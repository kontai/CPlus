#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actioninfo_triggered()
{
    QMessageBox::information(this,"信息","information");
}


void MainWindow::on_actionwarning_triggered()
{
    QMessageBox::warning(this,"警告","warning");

}

void MainWindow::on_actioncritical_triggered()
{
    QMessageBox::critical(this,"譪誤","critical");
}


void MainWindow::on_actionquestion_triggered()
{
    if(QMessageBox::Yes==
    QMessageBox::question(this,"hello","最近好嗎?",QMessageBox::Yes|QMessageBox::No))
    {
        qDebug()<<"還OK!";
    }else{
        qDebug().noquote()<<"不OK";
    }

}


