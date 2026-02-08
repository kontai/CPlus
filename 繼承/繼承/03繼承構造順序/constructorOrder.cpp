#include<iostream>

/*
*2026/02/08
*03繼承構造順序\
*/

using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base Constructor" << endl;
	}
	~Base()
	{
		cout << "Base Destructor" << endl;
	}
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived Constructor" << endl;
	}
	~Derived()
	{
		cout << "Derived Destructor" << endl;
	}

};

class A
{
public:
	A()
	{
		cout << "A Constructor" << endl;
	}
	~A()
	{
		cout << "A Destructor" << endl;
	}
};
class B
{
public:
	B()
	{
		cout << "B Constructor" << endl;
	}
	~B()
	{
		cout << "B Destructor" << endl;
	}
};
class C
{
public:
	C()
	{
		cout << "C Constructor" << endl;
	}
	~C()
	{
		cout << "C Destructor" << endl;
	}
};
class D:public A
{
public:
	D()
	{
		cout << "D Constructor" << endl;
	}
	~D()
	{
		cout << "D Destructor" << endl;
	}

public:
	B b;	//類D中包含類B的物件b，會在構造D物件時先構造b物件
	C c;	//類D中包含類C的物件c，會在構造D物件時先構造c物件
};

void func()
{
	Derived dc;	//創建Derived類的物件dc，會依次調用Base類的構造函數和Derived類的構造函數，輸出構造順序
	cout << "------------------" << endl;
	D d;	//創建D類的物件d，會依次調用A類的構造函數、B類的構造函數、C類的構造函數和D類的構造函數，輸出構造順序
}


int main()
{
	func();
}
