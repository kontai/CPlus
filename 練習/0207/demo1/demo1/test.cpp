/*
*	2021/02/07 18:54
*	D:\workspace\CPlus\�m��\0207\demo1\demo1
*
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person() {}
	Person(string name, int age) {
		this->name = name;
		this->age = age;
	}
	~Person() { cout << "�R�c��ƳQ�ե�!" << endl;

	system("pause");
	}
};
int main(void)
{
	Person p1 =  Person();

	return 0;
}