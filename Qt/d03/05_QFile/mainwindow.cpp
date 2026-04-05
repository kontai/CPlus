#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qDebug>

#include <QFileDialog>

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

void MainWindow::on_actionopen_file_triggered()
{
    // 过滤格式: 檔案格式 (檔案後綴) ;; 檔案格式 (檔案後綴) ;; ...
    //例如 "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)"

    QString filename=QFileDialog::getOpenFileName(this,"打開一個文件",
                                                    "D:/win10Folder",	//預設目
                                                    "JpG (*.jpg *.jpeg);;pNG (*.png);;GIF (*.gif);;all (*.*");	//過濾
    qDebug().noquote()<<filename;

}

