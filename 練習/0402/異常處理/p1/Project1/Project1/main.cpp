/*
*	MAIN
*	2021/04/02
*
*/
#if 0

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class myExceptClass {
public:
	myExceptClass() {
		cout << "�c�y��ƽե�" << endl;
	}
	myExceptClass(const myExceptClass &e) {
		cout << "�����c�y�ե�" << endl;
	}
	void func(){}
	~myExceptClass() { cout << "�R�c��ƽե�" << endl; }

};

int myDivision(int a, int b=3)throw(int) {

	throw 1.2;
}

void demo() {
	throw new myExceptClass();
}
int main() {
	int a = 10;
	int b = -10;
	try {

		//myDivision(a, b);
		demo();
	}
	catch (myExceptClass *e) {
		e->func();
		cout << "�u�ƹL��myExceptClass Called....II" << endl;
		delete e;
	}

	/*
	catch (myExceptClass &e) {
		cout << "�u�ƹL��myExceptClass Called....I" << endl;
	}
	*/

	/*
	catch (myExceptClass e) {
		cout << "myExceptClass Called" << endl;
	}
	*/
	catch (...) {
		cout << "���򲧱`" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
#endif