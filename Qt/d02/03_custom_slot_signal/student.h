#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
public slots:
    void treats();
    //重載函數
    void treats(QString);
signals:
};

#endif // STUDENT_H
