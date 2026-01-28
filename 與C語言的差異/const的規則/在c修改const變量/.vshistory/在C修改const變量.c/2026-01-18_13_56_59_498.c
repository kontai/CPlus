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
const int global_const_var = 100;

int main() {
	int* p = (int*)&global_const_var; //將const變量的地址賦值給非常量指標
	*p = 20;
	printf("global_const_var = %d\n", global_const_var); //輸出結果會發現const變量被修改了)

	return EXIT_SUCCESS;
}