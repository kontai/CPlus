#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionmodal,&QAction::triggered,[=](){
        QDialog dlg(this);
        dlg.exec();
        qDebug()<<"hello dialog";
    });
    connect(ui->actionnonmodal,&QAction::triggered,[=](){
        QDialog *dlg=new QDialog(this);
        dlg->show();	//資源分配在heap上
        dlg->setAttribute(Qt::WA_DeleteOnClose);	//視窗關閉時,刪除資源
        qDebug()<<"hello dialog";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
