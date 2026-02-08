#include<iostream>

/*
*2026/02/08
*01繼承概念\
*/

using namespace std;

class BaseClass
{
public:
	void func1() {}

	void func2() {}
};

class DerivedClass :public BaseClass
{
public: void func3() {}	//func3()是DerivedClass的成員函式，BaseClass沒有func3()，所以BaseClass的物件無法呼叫func3()
};

int main() {
	BaseClass bc;
	DerivedClass dc;
	//bc.func3();	//error: ‘class BaseClass’ has no member named ‘func3’
}