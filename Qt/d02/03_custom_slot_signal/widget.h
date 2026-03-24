#ifndef WIDGET_H
#define WIDGET_H

#include "student.h"
#include "teacher.h"
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void classIsOver();
    ~Widget() override;
public slots:
    void btnPress();

private:
    Teacher* pTeacher;
    Student* pStudent;
};
#endif // WIDGET_H
