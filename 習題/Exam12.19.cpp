/****************************************
[4/20/2017  21:46]
Exam12.19.cpp
****************************************/

#include<iostream>
#include <string>

using namespace std;

class NoName
{

public:
	NoName(){ }
	NoName(int inv,double db,string *str):pstring(str),ival(inv),dval(db){ }

private:
	string *pstring;
	int ival;
	double dval;
};


int mainExam12_19(){
	NoName ss;
	



system("pause");
return 0;
}