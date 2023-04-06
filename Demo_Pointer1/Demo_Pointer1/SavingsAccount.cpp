#include<cmath>
#include<iostream>
#include"1.h"
using namespace std;


SavingsAccount::SavingsAccount(int id, double rate):id(id),rate(rate) {
	cout << "rate= " << rate << endl;
}

void SavingsAccount::show() {
	Balance(Balance() * floor(12.3));
	cout << "#" << "\tBalance: " << Balance();
}

