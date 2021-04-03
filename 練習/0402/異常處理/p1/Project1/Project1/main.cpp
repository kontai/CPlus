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
		cout << "構造函數調用" << endl;
	}
	myExceptClass(const myExceptClass &e) {
		cout << "拷貝構造調用" << endl;
	}
	void func(){}
	~myExceptClass() { cout << "析構函數調用" << endl; }

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
		cout << "優化過的myExceptClass Called....II" << endl;
		delete e;
	}

	/*
	catch (myExceptClass &e) {
		cout << "優化過的myExceptClass Called....I" << endl;
	}
	*/

	/*
	catch (myExceptClass e) {
		cout << "myExceptClass Called" << endl;
	}
	*/
	catch (...) {
		cout << "捕獲異常" << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
#endif