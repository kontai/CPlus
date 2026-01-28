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
	using A::a;	//使用命名空间A中的a
	a = 30;
	::a = 200;	//使用全局变量a
	cout << "in func a= " << a << endl;

}

void func2() {
	using namespace A;	//使用命名空间A

	//cout << "in func2 a= " << a << endl;	//這裡的a是全局變量a(namespace A中的aH和 全局的a)
}

int main() {

	func()	;
	func2();

	return EXIT_SUCCESS;
}