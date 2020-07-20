/****************************************
[4/26/2017  21:47]
Exam12.23.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;


class NoDefault
{
public:
	NoDefault(int a){ }
};

class C
{
public:
	string st;
	C():NoDeobj(10){ }
	C(int iv):NoDeobj(iv){ }
private:
	NoDefault NoDeobj;
};




int mainExam12_23(){
	C cc ;
	C dd(12);
	int *is = new (int ) ;


system("pause");
return 0;
}