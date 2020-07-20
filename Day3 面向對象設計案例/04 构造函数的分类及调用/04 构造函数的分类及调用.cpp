#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//分類
//按照參數進行分類  無參構造函數（默認構造函數）   有參構造函數
//按照類型進行分類  普通構造函數  拷貝構造函數
class Person
{
public: //構造和析構必須寫在public下才可以調用到

	Person() //默認 、 無參構造函數
	{
		cout << "默認構造函數調用" << endl;
	}

	Person(int a)
	{
		cout << "有參構造函數調用" << endl;
	}

	//拷貝構造函數
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		cout << "拷貝構造函數調用" << endl;
	}

	~Person()
	{
		cout << "析構函數調用" << endl;
	}

	int m_Age;
};


void test01()
{
	//構造函數調用方式
	//括號法調用
	//Person p1(1); //有參
	//p1.m_Age = 10;
	//Person p2(p1); //拷貝
	//cout << "p2的年齡" << p2.m_Age << endl;

	//Person p3; //默認構造函數 不要加()   Person p3(); //編譯器認為這行是函數的聲明


	//顯示法調用
	//Person p4 = Person(100);
	//Person p5 = Person(p4);

	//Person(100); //叫匿名對像 ,匿名對像特點，如果編譯器發現了對象是匿名的，那麼在這行代碼結束後就釋放這個對象

	//不能用拷貝構造函數 初始化匿名對像
	//Person p6 = Person(p5); //如果寫成左值，編譯器認為你寫成 Person p5; 對象的聲明，如果寫成右值，那麼可以

	
	Person p7 = 100; //相當於調用了 Person p7 = Person(100) ，隱式類型轉換
	Person p8 = p7; // 相當於  Person p8 = Person(p7);
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}