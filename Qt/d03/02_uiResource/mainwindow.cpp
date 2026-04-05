#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QLabel>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addWidget(new QLabel("左側訊息",this));
    ui->actionnew->setIcon(QIcon(":/image/icons8-add-94.png"));
    ui->actiondelete->setIcon(QIcon(":/image/icons8-remove-94.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionwarning_triggered()
{
}


void MainWindow::on_actioninfo_triggered()
{

}


void MainWindow::on_actioncritical_triggered()
{

}


void MainWindow::on_actionquestion_triggered()
{

}

