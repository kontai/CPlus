#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/02/12
*AuTHOR:kontai
*
*/

class Base {
	public:
	Base() {
		cout << "Base constructor" << endl;
	}
	void display() {
		cout << "Base display" << endl;
	}
	virtual ~Base() {
		cout << "Base destructor" << endl;
	}
};

class Derived : public Base {
	public:
	Derived() {
		cout << "Derived constructor" << endl;
	}

	void display() {
		cout << "Derived display" << endl;
	}

	void show() {
		cout << "Derived show" << endl;
	}
	~Derived() {
		cout << "Derived destructor" << endl;
	}
};

int main() {

	Base* basePtr = new Derived();
	basePtr->display(); // Calls Base's display due to static binding
	//basePtr->show();	// Error: 'class Base' has no member named 'show'

	//Derived* derivedPtr = new Base();	// Error: cannot convert 'Base*' to 'Derived*' in initialization

	return EXIT_SUCCESS;
}