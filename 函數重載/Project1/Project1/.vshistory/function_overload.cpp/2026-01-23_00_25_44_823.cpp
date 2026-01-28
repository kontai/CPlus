#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/23
*AuTHOR:kontai
*
*/


void fun(double a, double b) {
	cout << "fun(double a,double b) called" << endl;
}

void fun(int a, int b) {
	cout << "fun(int a,int b) called" << endl;
}

void fun(int a, double b) {
	cout << "fun(int a,double b) called" << endl;
}

void fun(double a, int b) {
	cout << "fun(double a,int b) called" << endl;
}

//¼Ò¸W¨â¥i
//void fun(int a, int b, int c = 10) {
//	cout << "fun(int a,int b,int c=10) called" << endl;
//}

int main() {
	fun(10, 20);

	return EXIT_SUCCESS;
}