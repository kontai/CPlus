#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public :
	Person()
	{
		//構造中修改屬性
		//this 永遠執行本體  
		
		this->m_A = 0;
		this->m_B = 0;
	}

	void showInfo() const //常函數 不允許修改指針指向的值
	{
		//this->m_A = 1000;
		this->m_B = 1000;
		// const Person * const this
		cout << "m_A = " << this->m_A << endl;
		cout << "m_B = " << this->m_B << endl;
	}

	void show2() const
	{
		//m_A = 100;
	}

	int m_A;
	mutable int m_B; //就算是常函數 我還是執意要修改

};

void test01()
{

	Person p1;
	p1.showInfo();

	//常對像 不允許修改屬性
	const  Person p2;
	//cout << p2.m_A << endl;
	p2.show2();
	//常對像 不可以調用普通成員函數
	//常對像 可以調用常函數
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}