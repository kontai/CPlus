#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/
struct MyStruct {
	int a;
	double b;
	char c;
};

int main() {
	//直接初始化,C++支援此語法,前面加struct關鍵字可有可無
	MyStruct ms = { 10, 3.14, 'A' };
	return EXIT_SUCCESS;
}