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

private slots:
    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_startButton_2_clicked();

    void on_stopButton_2_clicked();



    void on_startButton_3_clicked();

    void on_stopButton_3_clicked();

private:
    Ui::Widget *ui;
    short tId;
    short tId2;

    QTimer *qtimer;

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};
#endif // WIDGET_H
