#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

// this可以解決命名衝突
class Person
{
public:
	Person(  int age)
	{
		this->age = age;
	}

	//對比年齡
	void compareAge( Person & p)
	{
		if (this->age == p.age )
		{
			cout << "年齡相等" << endl;;
		}
		else
		{
			cout << "年齡不相等" << endl;;
		}
	}

	//年齡相加
	 Person& PlusAge(Person & p)
	{
		 this->age += p.age;
		 return *this; //*this指向對像本體
	}

	int age;
};

void test01()
{
	Person p1(10);
	
	cout << "p1的年齡" << p1.age << endl;

	Person p2(10);

	p1.compareAge(p2);

	p1.PlusAge(p2).PlusAge(p2).PlusAge(p2); //鏈式編程

	cout << "p1的年齡" << p1.age << endl;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}