#include "mousectrl.h"
#include<QMouseEvent>


mouseCtrl::mouseCtrl(QWidget *parent)
    : QLabel{parent}
{
    //默認情況下，窗口不會主動跟蹤鼠標
    //只有當某個鼠標按下的情況下才開始跟踨
    //如果想一開始跟踨，就要使用以下函數
    setMouseTracking(true);


    //事件過濾器的使用
    //1.窗口調用installEventFilter來安裝一個事件過濾器
    //2.參數是一個事件過濾器對象QObject,該對象的類要重寫eventFilter的函數
    //事件過濾的時候，事件會先到達事件過濾器的eventFilter函數
    //返回值:true表示攔截，false表示不攔截，不攔截情況下，事件會繼續到達窗口
    this->installEventFilter(this);
}

void mouseCtrl::mousePressEvent(QMouseEvent *event)
{
    //獲取座標
    int x=event->x();
    int y=event->y();
    Qt::MouseButton btn=   event->button();
    QString qbtn="";
    if(btn == Qt::LeftButton){
        qbtn="leftButton";
    }else if(btn==Qt::RightButton){
        qbtn="rightButton";
    }


    //Label可以是html
    QString str=QString("<h1><center>[%1 %2][%3]</center></h1>").arg(x).arg(y).arg(qbtn);
    this->setText(str);

}

void mouseCtrl::mouseMoveEvent(QMouseEvent *event)
{    //獲取座標
    int x=event->x();
    int y=event->y();


    Qt::MouseButtons btns=   event->buttons();
    QString qbtns="";
    if(btns & Qt::LeftButton){
        qbtns+="leftButton";
    }
    if(btns&Qt::RightButton){
        qbtns+="rightButton";
    }
    if(btns&Qt::MiddleButton){
        qbtns+="midButton";
    }

    //Label可以是html
    QString str=QString("<h1><center>[%1 %2][%3]</center></h1>").arg(x).arg(y).arg(qbtns);
    this->setText(str);

}

//事件先會到達窗口的event函數
bool mouseCtrl::event(QEvent *e)
{
    // if(e->type()==QEvent::MouseMove){
    //     //攔截事件
    //     // this->mouseMoveEvent(static_cast<QMouseEvent*>(e));
    //     return true;

    // }

    return QLabel::event(e);	//其它事件交給父類處理
    //return true;	//攔截所有事件
}

bool mouseCtrl::eventFilter(QObject *watched, QEvent *event)
{
    //過濾鼠標姼動事件
    if(event->type()==QEvent::MouseMove){
        return true;	//return true 表示攔截事件
    }

    return false;
}
