/*************************
[29/7/2018 22:46
fn.cpp
*************************/

#include<iostream>

using namespace std;

class A {
public:
	A() {};
	void fn1() { cout << "�ե�A fn1()" << endl; }
	void fn2() { cout << "�ե�A fn2()" << endl; }
};

class B :virtual public A {
public:
	B():A(){}
	void fn1() { cout << "�ե�B fn1()" << endl; }
	void fn2() { cout << "�ե�B fn2()" << endl; }
};

class C :virtual public A {
public:
	C():A(){}
	void fn1() { cout << "�ե�C fn1()" << endl; }
	void fn2() { cout << "�ե�C fn2()" << endl; }
};

class D :public B, public C{
public:
	D():A(){}
	void fn1() { cout << "�ե�D fn1()" << endl; }
	void fn2() { cout << "�ե�D fn2()" << endl; }
	};

int mainUN() {
	B b;
	B *pb = &b;
	A *pa = &b;

	b.fn1();
	b.fn2();
	pa->fn1();
	pa->fn2();
	pb->fn1();
	pb->fn2();

	A *pp = new D();
	pp->fn1();


	system("pause");
	return 0;
}