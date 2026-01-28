#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AUTHOR:kontai
*
*本檔案演示 C++ 結構體的增強功能：
*1. 結構體中包含成員函數
*2. 聚合初始化（Aggregate Initialization）
*/

// 定義一個結構體，包含資料成員和成員函數
struct MyStruct {
	int a;        // 整數型成員變數
	double b;     // 浮點數型成員變數
	char c;       // 字元型成員變數

	// 結構體內的成員函數
	// 可以直接在結構體中定義函數，類似於類別
	void func() {
		cout << "This is a member function of MyStruct." << endl;
	}
};

int main2() {
	// 使用聚合初始化語法建立並初始化結構體物件
	// 前面加 struct 關鍵字可有可無
	MyStruct ms = { 10, 3.14, 'A' };

	// C++14 支援此語法，按照定義順序對應初始化：
	// a = 10, b = 3.14, c = 'A'
	MyStruct ms1{ 15, 1.61, 'C' }; // C++11 及以上版本支援此語法


	//MyStruct ms2 = { .a = 20, .b = 2.71, .c = 'B' }; // C++20 支援指定成員初始化

	// 程式正常結束，返回成功狀態碼
	return EXIT_SUCCESS;
}