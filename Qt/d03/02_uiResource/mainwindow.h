#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionwarning_triggered();

    void on_actioninfo_triggered();

    void on_actioncritical_triggered();

    void on_actionquestion_triggered();

private:
    Ui::MainWindow *ui;
    void QMessageBox();
};
#endif // MAINWINDOW_H
