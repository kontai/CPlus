/*
*	¼ÒªO
*	2021/03/21
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
template<class T>
void switch2number(T &a, T &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}


int main() {
	int a = 3;
	int b = 6;
	switch2number(a, b);
	cout << "a=" << a << " b=" << b << endl;
	system("pause");
	return EXIT_SUCCESS;
}