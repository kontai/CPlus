/****************************************
[5/16/2017  20:59]
Exam13.14.cpp
****************************************/

#include<iostream>
#include<vector>

using namespace std;

struct Exampl {
	Exampl() {
		cout << "Exampl()" << endl;
	}

	Exampl(const Exampl&)
	{
		cout << "Exampl(const Exampl&)" << endl;
	}

	Exampl operator=(const Exampl&){
		cout << "Exampl operator=(const Exampl&)" << endl;
		return *this;
	}

	~Exampl()
	{
		cout << "~Exampl()" << endl;
	}
};

void fun1(Exampl obj)
{
}

void fun2(Exampl &obj)
{
}

Exampl fun3()
{
	Exampl obj;
	return obj;
}

int mainExam13_14(){
	Exampl obj;
	fun1(obj);
	fun2(obj);
	obj=fun3();
	Exampl *epo = new Exampl;
	vector<Exampl>evec(3);
	delete epo;

system("pause");
return 0;
}