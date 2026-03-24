#include "student.h"
#include<QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{}

void Student::treats()
{
    qDebug()<<"Student treats Teacher\n";
}

void Student::treats(QString food)
{
    qDebug()<<"Student treats Teacher"<<food;
}
