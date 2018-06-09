/*************************
[3/6/2018 18:59
exam1240.cpp
*************************/

#include<iostream>

using namespace std;
class Foo {
public:
	Foo(int a = 0) :f1(a) {}
	int ret() { return f1; }
	friend class Bar;
private:
	int f1;
};

class Bar :public Foo {
public:
	Bar(int aaa):Foo(aaa){ callsFooVal(); }
	static Foo Fooval();
	static void callsFooVal();

private:
	static int si;
	static Foo scf;
};

int Bar::si = 20;
Foo Bar::scf(0);

Foo Bar::Fooval() {

	return scf;
}

void Bar::callsFooVal() {
	Bar::si += 1;
	cout << "now si=" << Bar::si << endl;
}

int mainE1240() {
	Foo pp(20);
	Bar pp2(30);
	cout << pp2.ret() << endl;
	Bar pp3(70);
	cout << pp3.ret() << endl;

	system("pause");
	return 0;
}