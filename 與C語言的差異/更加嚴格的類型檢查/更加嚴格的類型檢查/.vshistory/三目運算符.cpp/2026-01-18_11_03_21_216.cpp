#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/

int main() {
	int a = 10;
	int b = 20;

	//In c
	*(a > b ? &a : &b) = 100;

	//(a > b ? a : b) = 100;
	cout << "a = " << a << ", b = " << b << endl;
	return EXIT_SUCCESS;
}