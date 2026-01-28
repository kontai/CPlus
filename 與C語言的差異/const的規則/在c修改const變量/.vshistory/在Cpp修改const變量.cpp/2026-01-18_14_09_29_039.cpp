#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/

const int global_const_var = 100;	//常量區,不可修改

void test() {
	int* p = (int*)&global_const_var; //將const變量的地址賦值給非常量指標
	*p = 20;
	printf("global_const_var = %d\n", global_const_var);
}

int main33() {
	//test();
	const int local_const_var = 200;	//stack區,可修改
	int* p = (int*)&local_const_var; //將const變量的地址賦值給非常量指標
	*p = 50;
	printf("local_const_var = %d\n", local_const_var); //輸出結果會發現const變量被修改了)

	return EXIT_SUCCESS;
}