#include "widget.h"

#include "student.h"
#include "teacher.h"

#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // pTeacher=new Teacher();
    pTeacher=new Teacher(this);	//設定 parent，解構時才會自動釋放
    pStudent=new Student(this);
    //建立連接(無參)
    // connect(pTeacher,&Teacher::hungry,pStudent,&Student::treats);

    //建立函數指針
    void (Teacher::*teacherHungry)(QString)=&Teacher::hungry;
    void (Student::*studentTreats)(QString)=&Student::treats;

    //建立連接(有參)method I
    connect(pTeacher,teacherHungry,pStudent,studentTreats);

    //建立連接(有參)method II
    connect(pTeacher,
            static_cast<void (Teacher::*)(QString)>(&Teacher::hungry),
            pStudent,
            static_cast<void (Student::*)(QString)>(&Student::treats));
    connect(pTeacher,
            static_cast<void (Teacher::*)()>(&Teacher::hungry),
            pStudent,
            static_cast<void (Student::*)()>(&Student::treats));


    QPushButton *btn=new QPushButton("Press Me",this);


    this->classIsOver();

    //信號連接信號
    //無參
    // connect(btn,
    //         &QPushButton::clicked,
    //         pTeacher,
    //         static_cast<void (Teacher::*)()>(&Teacher::hungry));
    //有參
    connect(btn,
            &QPushButton::clicked,
            this,
           &Widget::btnPress );
    //有參 lambda
    /*
    connect(btn,
            &QPushButton::clicked,
            [this](){ emit pTeacher->hungry("黃燜雞"); }); // 用 lambda 橋接
*/

}

void Widget::classIsOver()
{
    //觸發信號
    emit pTeacher->hungry();

    //觸發信號,有型參
    emit pTeacher->hungry("黃燜雞");
}

void Widget::btnPress()
{
emit pTeacher->hungry("黃燜雞");
}

Widget::~Widget() = default;
