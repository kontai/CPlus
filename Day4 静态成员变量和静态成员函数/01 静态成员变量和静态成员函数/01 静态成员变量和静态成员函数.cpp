#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		//m_Age = 10;
	}

	static int m_Age; //加入static就是 靜態成員變量 ，會共享數據
	//靜態成員變量，在類內聲明，類外進行初始化

	//靜態成員變量 也是有權限的
	int m_A;

	//靜態成員函數
	//不可以訪問  普通成員變量
	//可以訪問 靜態成員變量
	static void func()
	{
		//m_A = 10;
		m_Age = 100;
		cout << "func調用" << endl;
	};
	//普通成員函數 可以訪問普通成員變量，也可以訪問靜態成員變量
	void myFunc()
	{
		m_A = 100;
		m_Age = 100;
	}
private:
	static int m_other; //私有權限 在類外不能訪問

	static void func2()
	{
		cout << "func2調用" << endl;
	}
};
int  Person::m_Age = 0; //類外初始化實現
int  Person::m_other = 10;


void test01()
{
	//1 通過對像訪問屬性
	Person p1;
	p1.m_Age = 10;

	Person p2;
	p2.m_Age = 20;

	cout << "p1 = " << p1.m_Age << endl; //10 或者 20？ 20
	cout << "p2 = " << p2.m_Age << endl; //20
	//共享數據

	//2 通過類名訪問屬性
	cout << "通過類名訪問Age" << Person::m_Age << endl;
	//cout << "other = " << Person::m_other << endl; //私有權限在類外無法訪問

	//靜態成員函數調用
	p1.func();
	p2.func();
	Person::func();

	//靜態成員函數 也是有權限的
	//Person::func2();

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}