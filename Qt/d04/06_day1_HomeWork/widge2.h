#ifndef WIDGE2_H
#define WIDGE2_H

#include <QWidget>

class Widge2 : public QWidget
{
    Q_OBJECT
public:
    explicit Widge2(QWidget *parent = nullptr);

signals:
    void btn2Clicked();
};

#endif // WIDGE2_H
