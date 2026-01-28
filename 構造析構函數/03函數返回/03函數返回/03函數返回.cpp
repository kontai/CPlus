#include<iostream>

using namespace std;
class Maker {
public:
	Maker() :a(0) {
		cout << "Maker() called" << endl;
	}
	Maker(int a) :a(a) {
		cout << "Maker(int a) called with a = " << a << endl;
	}
	Maker(const Maker& m) {
		a = m.a;
		cout << "copy Maker(const Maker&) called" << endl;
	}
	~Maker() {
		cout << "~Maker is called" << endl;
	}

private:
	int a;
};

void fun() {
	Maker m1;
	Maker m2(10);
}

 Maker fun2() {
	Maker m1(20);
	cout << "address of m1 in fun2: " << &m1 << endl;
	return m1;
}
int main() {
	//fun();
	Maker m1 = fun2();
	cout << "address of m1 in main: " << &m1 << endl;
}
