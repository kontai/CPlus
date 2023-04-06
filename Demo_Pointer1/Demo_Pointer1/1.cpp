/*
*	1
*	2021/10/31
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include "1.h"
#include<initializer_list>
#include<iostream>

using namespace std;
inline void add(int &);
int main() {
	int x = 0;
	//add(x);
	//cout << "x= " << x << endl;

	initializer_list<int> list; //可變參數

	SavingsAccount sa(1,22.2);
	cout << sa.getBalance() << endl;
	system("pause");
	return EXIT_SUCCESS;
}

//void add(int &a) {
//	a++;
//}