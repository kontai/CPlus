#include<iostream>

using	namespace std;


//多重繼承：一個類同時繼承多個基類
 class A {
public:
	 	int a = 20;
};

class B {
public:
	int a = 10;
};

class C :public A,public B{
public:
	//int a = 5;
};

void func() {
	C c;
	//cout << "c.a=" << c.a << endl;		// 編譯錯誤：c.a是二義性的，因為A和B都有a成員變數
}
int main() {



	return 0;
}