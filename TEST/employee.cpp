/*************************
[15/7/2018 7:52
employee.cpp
*************************/

#include<iostream>
#include<string>

using namespace std;
class Account {
public:
	Account() {}
	Account(const string &ac, const string &nm, string mon) :
		acc(ac), name(nm), money(mon) {}

	void acInfo();

	~Account() {
		cout << "deleting..." << endl;
	}

private:
	string acc, name, money;
};

void Account::acInfo() {
	cout << "Account= "<<acc << endl;
	cout << "Name= "<<name << endl;
	cout << "Money= "<<money << endl;
}




int mainC() {
	/*****  Method I  : ÀRºA¼Æ²Õ
	Account a[3] = {
		Account("0233106-35","tai","1000"),
		Account("0234106-35","nick","2000"),
		Account("0219106-35","joe","3000")
	};
	*/

	Account a[3];
	Account *p;
	p = new Account("0233106-35", "tai", "1000");
	a[0] = *p;
	p++;
	p =new Account("0234106-35", "nick", "2000");
	a[1] = *p;
	p++;
	p = new Account("0219106-35", "joe", "3000");
		a[2] = *p;

	for (int i = 0; i < 3; i++)
		a[i].acInfo();

	system("pause");
	return 0;
}