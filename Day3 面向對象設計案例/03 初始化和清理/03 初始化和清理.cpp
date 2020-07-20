#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	//構造函數寫法
	//與類名相同，沒有返回值 ，不寫void，可以發生重載 （可以有參數）
	//構造函數由編譯器自動調用，而不是手動，而且只會調用一次
	Person()
	{
		cout << "構造函數調用" << endl;
	}

	Person(int a)
	{
		cout << "構造函數調用(int a)" << endl;
	}


	//析構函數寫法
	// 與類名相同 類名前面加一個符號 「~」 ,也沒有返回值 ，不寫void， 不可以有參數（不能發生重載）
	//自動調用，只會調用一次
	~Person()
	{
		cout << "析構函數調用" << endl;
	}


};


void test01()
{
	Person p1(1); //默認調用了構造和析構，是系統提供的兩個空實現的函數
}

int main(){

	test01();
	
	
	system("pause");
	return EXIT_SUCCESS;
}