#ifndef MYCONTROLBAR_H
#define MYCONTROLBAR_H

#include <QWidget>

namespace Ui {
class MyControlBar;
}

class MyControlBar : public QWidget
{
    Q_OBJECT

public:
    explicit MyControlBar(QWidget *parent = nullptr);
    ~MyControlBar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MyControlBar *ui;
};

#endif // MYCONTROLBAR_H
