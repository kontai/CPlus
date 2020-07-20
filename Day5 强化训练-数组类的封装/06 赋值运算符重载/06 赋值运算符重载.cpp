#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//一個類默認創建 默認構造、析構、拷貝構造 operator=賦值運算符 進行簡單的值傳遞
class Person
{
public:

	Person(int a)
	{
		this->m_A = a;
	}


	int m_A;
};

void test01()
{
	Person p1(10);

	Person p2(0);

	p2 = p1; //賦值

	cout << "p2 的m_A" << p2.m_A <<endl;
}


class Person2
{
public:
	Person2(char * name)
	{
		this->pName = new char[strlen(name) + 1];
		strcpy(this->pName, name);
	}

	//重載 = 賦值運算符
	Person2& operator= ( const Person2 & p)
	{
		//判斷如果原來已經堆區有內容，先釋放
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}

		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);

		return *this;
	}

	~Person2()
	{
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}
	}

	char * pName; 
};

void test02()
{
	Person2 p1("狗蛋");

	Person2 p2("狗剩");

	Person2 p3("");
	p3 = p2 = p1;

	cout << p2.pName << endl;
	cout << p3.pName << endl;

	//int a = 10;
	//int b = 20;
	//int c;
	//c = a = b; //都是20
	//cout << a << " " << b << " " << c << endl;

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}