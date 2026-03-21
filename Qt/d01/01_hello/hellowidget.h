#ifndef HELLOWIDGET_H
#define HELLOWIDGET_H

#include <QWidget>

class HelloWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HelloWidget(QWidget *parent = nullptr);
    ~HelloWidget() override;
};
#endif // HELLOWIDGET_H
