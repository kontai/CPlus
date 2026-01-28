#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
*2026/01/18
*AuTHOR:kontai
*
*/
//const 全域變量
const int global_const_var = 100;	//常量區,不可修改

void test() {
	int* p = (int*)&global_const_var; //將const變量的地址賦值給非常量指標
	*p = 20;
	printf("global_const_var = %d\n", global_const_var);
}

int main22() {
	//test();
	const int local_const_var = 200;	//stack區,可修改
	int* p = (int*)&local_const_var; //將const變量的地址賦值給非常量指標
	*p = 50;
	printf("local_const_var = %d\n", local_const_var); //輸出結果會發現const變量被修改了)

	//調用另一文件中的const變量
	//C語言中,const修飾的全域變量預設是extern類型的,可以在其他文件中使用extern關鍵字聲明後使用
	extern const int const_var;
	printf("const_ver: %d\n", const_var);

	return EXIT_SUCCESS;
}