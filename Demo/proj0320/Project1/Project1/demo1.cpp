/*
*	DEMO1
*	2021/03/20
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class A {
public:
	explicit A() :num(0) {}
	explicit A(int a) :num(a)
	{
		cout << "ºc³y" << endl;
	}
	void operator =(int a) {
		cout << "½á­Èºc³y" << endl;
		num = a;
	}

	int num;
};
using namespace std;

int mainA() {
	A a;
	a = 3;
	//A a(2);


	system("pause");
	return EXIT_SUCCESS;
}