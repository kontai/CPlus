#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyClass
{
public:
	//MyClass()
	//{
	//	cout << "默認構造函數" << endl;
	//}

	MyClass(int a)
	{
		cout << "有參構造函數" << endl;
	}

	//MyClass(const MyClass& m)
	//{
	//}
	int m_A;
	
	
};

//系統默認給一個類提供 3個函數  默認構造 、 拷貝構造 、 析構函數

//1 當我們提供了有參構造函數，那麼系統就不會在給我們提供默認構造函數了
//但是 系統還會提供默認拷貝構造函數 , 進行簡單的值拷貝

void test01()
{
	MyClass c1(1);
	c1.m_A = 10;
	MyClass c2(c1);
	cout << c2.m_A << endl;
}

//2 當我們提供了 拷貝構造，那麼系統就不會提供其他構造了

class MyClass2
{
public:
	MyClass2()
	{
		cout << "默認構造函數" << endl;
	}

	//MyClass2(int a)
	//{
	//	cout << "有參構造函數" << endl;
	//}

	MyClass2(const MyClass& m)
	{
	}
	int m_A;

};

void test02()
{
	MyClass2 c1;
}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}