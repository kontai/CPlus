#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Person
{
public:

	Person()
	{}
	//初始化屬性
	Person(char * name,int age)
	{
		m_Name = (char*)malloc(strlen(name) + 1);
		strcpy(m_Name, name);

		m_age = age;
	}
	//拷貝構造 系統會提供默認拷貝構造，而且是簡單的值拷貝
	//自己提供拷貝構造，原因簡單的淺拷貝會釋放堆區空間兩次，導致掛掉
	//深拷貝
	Person(const Person&p)
	{
		m_age = p.m_age;
		m_Name = (char*)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
	}

	~Person()
	{
		cout << "析構函數調用" << endl;
		if (m_Name!=NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}


	//姓名
	char * m_Name;
	//年齡
	int m_age;
};


void test01()
{
	Person p1("敵法",10);
	Person p2(p1); //調用拷貝構造

	
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}