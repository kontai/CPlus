/*************************
[17/6/2018 15:56
structcpp.cpp
*************************/

#include<iostream>
#include<string>

using namespace std;

struct Student
{
	int age, number,classes;
	string name;
};

int mainSTR(){
	Student tai = { 23,18,30,"tai" };
	cout << tai.age << endl;
	cout << tai.number << endl;
	cout << tai.classes << endl;
	cout << tai.name << endl;
	

	system("pause");
	return 0;
}