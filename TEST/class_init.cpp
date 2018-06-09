#include<iostream>
#include<string>
#include<map>

using namespace std;
class A1
{
public:
	A1(const string myname,int myage,const string mycity):
		name(myname),age(myage),city(mycity){};
	void get() {
		cout << "My Name=" << this->name << endl;
		cout << "My Age=" << this-> age<< endl;
		cout << "My City=" << this->city << endl;
	}
//	~A1();

private:
	string name,city;
	short age;
	string::size_type st;

};

class B1:public A1 {


};



int maininit(){
	A1 a1("tai", 30, "taouyam");;
	//A1::A1("tai",30,"taouyam");
	a1.get();


	system("pause");
	return 0;
}