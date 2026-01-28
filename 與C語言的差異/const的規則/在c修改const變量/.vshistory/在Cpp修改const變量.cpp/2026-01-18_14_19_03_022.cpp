#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/

const int var = 100;	//常量區,不可修改

void test1() {
	cout << "var= " << var << endl;
	//int* p = (int*)&var; //將const變量的地址賦值給非常量指標
	//*p = 20;
	//printf("global_const_var = %d\n", var);
}

int main() {
	test1();

	return EXIT_SUCCESS;
}