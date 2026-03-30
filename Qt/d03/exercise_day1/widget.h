#ifndef WIDGET_H
#define WIDGET_H

#include <QPushButton>
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(const QString &windowTitle,const QString &btnTitle ,QWidget *parent = nullptr);
    ~Widget();
signals:
        void switchWindow();
};
#endif // WIDGET_H
