/*************************
[29/7/2018 21:54
重載與多態.cpp
*************************/

#include<iostream>
#include<string>

using namespace std;

class Base {
public:
	Base() {}
	~Base(){}
	void fn1() { cout << "1" << endl; };
	void fn2() { cout << "2" << endl; };
};

class Derived :private Base {
public:
	using Base::fn1; //c++ 11 up
	using Base::fn2;
	/*void fn1() { Base::fn1(); }
	void fn2() { Base::fn2(); }*/

	

};
int main私有() {
	Derived a;
	a.fn1();
	a.fn2();

	

	system("pause");
	return  0;
}