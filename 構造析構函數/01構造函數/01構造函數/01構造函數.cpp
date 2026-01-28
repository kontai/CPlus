#include<iostream>

using namespace std;

class Maker {
	//無參數建構子
public:
	Maker() {
		this->a = 0;
		cout << "Maker() called" << endl;
	}

	//有參數建構子
	Maker(int a) {
		this->a = a;
		cout << "Maker(int a) called, a = " << a << endl;
	}

	~Maker() {
		cout <<this->a<< "~Maker() called" << endl;
	}

private:
	int a;
};

class Maker2 {

};

void fun() {
	Maker m1;
	Maker m2(20);
}

void fun2() {
	Maker2 m1;	//if no constructor defined, default constructor is provided
	//Maker2 m2(20);
}


int main() {
	fun();

	return 0;
}