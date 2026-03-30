#include <iostream>
using namespace std;
void test1() {
	//lambda型式:[捕获列表](参数列表)函數額外屬性設置->返回类型{函数体}

	//使用函數指針
	void (*p)() = []() {
		cout << "Hello,Lambda" << endl;
		};
	p();

	//直接調用
	[]() {
		cout << "Hello,Lambda" << endl;
		}();
}

void test2() {
	//局部變量引入方式
	int a = 10;
	int b = 20;

	//值傳遞
	[a, b]() {
		cout << a << "," << b << endl;
		//lambda函數內部不能修改外部變數
		//a = 5;
		//b = 6;
		}();

	/*
	[a, b]()mutable {
		cout << a << "," << b << endl;
		//使用mutable可以修改外部變數
		a = 5;
		b = 6;
		}();
	*/

	//引用傳遞
	[&a, &b]() {
		a = 5, b = 6;
		}();
	cout << a << "," << b << endl;
}

void test3() {
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	// "=" 表示值傳遞所有局部變量(包括this)，"&" 表示引用傳遞所有局部變量，"[]" 表示不傳遞任何變量
	[=]() {
		cout << a << "," << b << endl;
		}();

	[&]() {
		a = 5, b = 6;
		}();
	cout << a << "," << b << endl;

	//b吏用值用傳遞，其它使用a引用傳遞
	[=, &b]() {
		}();

	//b吏用引用傳遞，其它使用a值傳遞
	[&, b]() {
		}();

}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}