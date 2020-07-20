#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->m_Age = age;
	}

	void showAge()
	{
		cout << "年齡為：" << this->m_Age << endl;
	}
	~Person()
	{
		cout << "Person的析構調用" << endl;
	}

	int m_Age;
};


//智能指針
//用來托管自定義類型的對象，讓對像進行自動的釋放
class smartPointer
{
public:
	smartPointer(Person * person)
	{
		this->person = person;
	}

	//重載->讓智能指針對像 想Person *p一樣去使用
	Person * operator->()
	{
		return this->person;
	}

	//重載 * 
	Person& operator*()
	{
		
		return *this->person;
	}

	~smartPointer()
	{
		cout << "智能指針析構了" << endl;
		if (this->person !=NULL)
		{
			delete this->person;
			this->person = NULL;
		}
	}

private:
	Person * person;
};

void test01()
{
	//Person p1(10); //自動析構

	//Person * p1 = new Person(10);
	//p1->showAge();
//	delete p1;


	smartPointer sp(new Person(10)); //sp開闢到了棧上，自動釋放
	sp->showAge(); // sp->->showAge(); 編譯器優化了 寫法

	(*sp).showAge();
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}