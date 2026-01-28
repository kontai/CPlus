#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/
namespace A {
	int a = 10;
	int b = 20;
	int c = 30;
}
int a = 100;

void func() {
	using A::a;
	a = 30;
	::a = 200;
	cout << "in func a= " << a << endl;

}

void func2() {
	using  A::a;
	cout << "in func2 a= " << a << endl;
}

int main() {

	func()	;
	func2();

	return EXIT_SUCCESS;
}