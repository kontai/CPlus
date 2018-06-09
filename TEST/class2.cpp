/****************************************
[4/20/2017  21:21]
class2.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Constr
{
public:
	Constr() {
	}
	Constr(const string& str):name(str),age(0){}
	

//private:
	string name;
	int age;
};

using namespace std;

int main_class2() {
	Constr a;
	Constr *p = &a;
	p->name = "abc";
	cout << a.name<<'\t'<<a.age << endl;
	cout << sizeof(Constr)<< endl;



system("pause");
return 0;
}