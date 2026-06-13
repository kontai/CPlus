#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/

const int var = 100;

void test1() {

	cout << "var= " << var << endl;

	const int b = 20;
	int* p = (int*)&b;
	*p = 30;
	cout << "b= " << b << endl;
	cout << "*p= " << *p << endl;
}

void test2() {
	volatile const int b = 20;

	int* p = (int*)&b;
	*p = 30;
	cout << "b= " << b << endl;
	cout << "&var= " << &var << endl;
	cout << "*p= " << *p << endl;


	cout << "&b= " << &b << endl;

	cout << "&var= " << &var << endl;
	cout << "p= " << p << endl;
}

void test3() {
	int a = 10;
	const int b = a;
	int* p = (int*)&b;
	*p = 20;
	cout << "b= " << b << endl;
	cout << "*p= " << *p << endl;

	struct Mask {
		int a = 10;
	};

	const	Mask m;
	Mask* n = (Mask*)&m;
	n->a = 99;
	cout << "m.a= " << m.a << endl;

}

int main() {
	////test1();
	////test2();
	////test3();

	return EXIT_SUCCESS;
}