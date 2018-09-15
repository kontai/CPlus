/*************************
[21/7/2018 9:44
class_der.cpp
*************************/

#include<iostream>

using namespace std;

class Base1 {
public:
	void dis() {
		cout << "Base1 display" << endl;
}
};

class Base2 :public Base1 {
public:
	void dis() {
		cout << "Base2 display" << endl;
	}
};

class Derived :public Base2 {
public:
	void dis() {
		cout << "Derives display" << endl;
	}
};

void inf(Base1* pt) {
	pt->dis();
}

int main(){
	Base1 base1;
	Base2 base2;
	Derived derived;

	inf(&base1);
	inf(&base2);
	inf(&derived);

	system("pause");
	return 0;
}