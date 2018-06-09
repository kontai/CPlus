/****************************************
[4/2/2017  18:04]
Exam12.1.cpp
****************************************/

#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

class Person
{
public:
	string getA()const, getN()const;
	Person(const string &cn,const string &ca) :name(cn), address(ca){ }
	

private:
	string name,address;

};

string Person::getA()const
{
	return name;
}

string Person::getN()const
{
	return address;
}

int mainExam12_1(){

system("pause");
return 0;
}