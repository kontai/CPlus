#ifndef MOUSECTRL_H
#define MOUSECTRL_H

#include <QLabel>
#include <QWidget>

class mouseCtrl : public QLabel
{
    Q_OBJECT
public:
    explicit mouseCtrl(QWidget *parent = nullptr);

signals:

    // QWidget interface
protected:
    //重寫事件

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool event(QEvent *event);




    // QObject interface
public:
    //安裝過濾器
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MOUSECTRL_H
