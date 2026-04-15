#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QWidget>

class myPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit myPushButton(QWidget *parent = nullptr);

signals:

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MYPUSHBUTTON_H
