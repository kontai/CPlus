#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //單項加入
    QListWidgetItem *item=new QListWidgetItem("床前明月光");
    // item->setTextAlignment(Qt::AlignCenter);	//文字居中
    ui->listWidget->addItem(item);

    QStringList list;
    list.append("疑是地上霜");
    list<<"舉頭望明月"<<"低頭思故鄉";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
