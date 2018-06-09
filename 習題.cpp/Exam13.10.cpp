/****************************************
[5/14/2017  15:23]
Exam13.10.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
	Employee():user_ptr(new string),user_name("kontai"),user_id(counter)
	{
		++counter;
	}
	Employee(const string &nm):user_ptr(new string),user_name(nm),user_id(counter)
	{
		++counter;
	}
	Employee(const Employee& rnm)
	{
		user_ptr = new string;
		*user_ptr = *(this->user_ptr);
		++counter;
	}

	Employee& operator=(const Employee& asnm){
		user_name = asnm.user_name;
		user_ptr = new string;
		*user_ptr = *(asnm.user_ptr);
		return *this;
	}
	static int get_i()
	{
		return  counter;
	};
private:
	string *user_ptr;
	string user_name;
	int user_id;
	static int counter;
};

int Employee::counter = 1;

int mainExam13_10(){
	Employee a;
	Employee a2("abc");

	Employee a3(a2);
	cout << "a3="<<a3.get_i()<<endl;

	Employee a4=a3;
	cout << "a4="<<a4.get_i()<<endl;


	




system("pause");
return 0;
}