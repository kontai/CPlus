#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/02/12
*AuTHOR:kontai
*
*/
//多態:同一個操作對不同的物件有不同的行為
class Base {
	public:
	Base() {
		cout << "Base constructor" << endl;
	}
	void display() {
		cout << "Base display" << endl;
	}

	virtual void show() {
		cout << "Base show" << endl;
	}

	//如果要實現多態，必須將函式宣告為虛擬函式,並且在派生類別中覆寫該函式(因為多態是透過虛擬函式實現的)
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
	basePtr->show();    // Calls Derived's show due to dynamic binding (polymorphism)
	//basePtr->show();	// Error: 'class Base' has no member named 'show'

	//Derived* derivedPtr = new Base();	// Error: cannot convert 'Base*' to 'Derived*' in initialization

	return EXIT_SUCCESS;
}