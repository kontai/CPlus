#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "widge2.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
private:
    Widge2 *widge2;
};
#endif // WIDGET_H
