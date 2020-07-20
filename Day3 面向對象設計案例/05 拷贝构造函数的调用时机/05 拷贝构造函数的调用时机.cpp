#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默認構造函數調用" << endl;
	}

	Person(int a)
	{
		cout << "有參構造函數調用" << endl;
	}

	Person(const Person& p )
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
// 拷貝構造調用的時機
//1、用已經創建好的對象來初始化新的對象
void test01()
{
	Person p1;
	p1.m_Age = 10;

	Person p2(p1);
}


//2、以值傳遞的方式給函數參數傳值
void doWork(Person p1) // Person p1 = Person(p)
{

}

void test02()
{
	Person p;
	p.m_Age = 10;

	doWork(p);
}


//3、以值方式返回局部對像
Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p = doWork2();
}
//Release下優化成什麼樣？
/* Person p; 不調用默認構造
	doWork2(p);

	void doWork2(Person & p)
	{
		Person p1 //調用默認構造
	}

*/


int main(){

	//test01();
	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}