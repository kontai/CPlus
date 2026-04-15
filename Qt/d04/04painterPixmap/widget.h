#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    int imgPos;


    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();
};
#endif // WIDGET_H
