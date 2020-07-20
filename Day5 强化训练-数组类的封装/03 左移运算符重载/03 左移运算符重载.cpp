#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream &cout, Person & p1);

public:
	Person(){}
	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	/*void operator<<() 重載左移運算符不可以寫到成員函數中
	{

	}*/

private:
	int m_A;
	int m_B;
};

ostream& operator<<(ostream &cout , Person & p1 )  //第一個參數 cout  第二個參數  p1 
{
	cout << "m_A = " << p1.m_A << " m_B = " << p1.m_B;

	return cout;
}


void test01()
{
	Person p1(10, 10);

	cout << p1 << "helloworld" <<endl;
	
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}