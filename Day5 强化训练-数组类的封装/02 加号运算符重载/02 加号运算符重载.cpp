#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(){};
	Person(int a, int b) :m_A(a), m_B(b)
	{}

	//+號運算符重載 成員函數 二元
	/*Person operator+ ( Person & p)
	{
	Person tmp;
	tmp.m_A = this->m_A + p.m_A;
	tmp.m_B = this->m_B + p.m_B;
	return tmp;
	}*/

	int m_A;
	int m_B;
};

//利用全局函數 進行+號運算符的重載
Person operator+ ( Person &p1,Person& p2) //二元  p1 + p2   
{
	Person tmp;
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p1.m_B + p2.m_B;
	return tmp;
}

Person operator+ (Person &p1, int a) //二元
{
	Person tmp;
	tmp.m_A = p1.m_A + a;
	tmp.m_B = p1.m_B + a;
	return tmp;
}


void test01()
{
	Person p1(10, 10);
	Person p2(10, 10);

	Person p3 = p1 + p2; // p1 + p2  從什麼表達式轉變的？ p1.operator+(p2)  operator+(p1,p2)
	Person p4 = p1 + 10; //重載的版本
	cout << "p3 的 m_A: " << p3.m_A << "  m_B: " << p3.m_B << endl;

	//operator+(p1, p2);
	
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}