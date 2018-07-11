/*************************
[17/6/2018 16:42
uniExp.cpp
*************************/

#include<iostream>
#include<string>

using namespace std;

class UniExp {
	enum  { GRADE,PASS, PERCENT} mode;
	string name;
	union {
		char grade;
		bool pass;
		int percent;
	};

public:
	UniExp(string name,char grade):
		name(name),grade(grade),mode(GRADE){}
	UniExp(string name,bool pass):
		name(name),pass(pass),mode(PASS){}
	UniExp(string name,int  percent):
		name(name),percent(percent),mode(PERCENT){}

	void show();
};

void UniExp::show() {
	cout << name << ":";
	switch (mode) {
	case GRADE:
		cout << grade;
		break;
	case PASS:
		cout << pass ? "Pass" : "False";
		break;
	case PERCENT:
		cout << percent;
		break;
	}
	cout << endl;
}

int main(){
	UniExp student1("nick", 'A');
	UniExp student2("jack", 0);
	UniExp student3("Bill", 30);

	student1.show();
	student2.show();
	student3.show();
	

	system("pause");
	return 0;
}