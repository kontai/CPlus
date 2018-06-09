#include<iostream>
#include <string>

using namespace std;

inline	const  int  call()			//在函數返回之前使用inline,會在函式呼叫點進行(行內in line)擴展,避免而外開銷(但只限用於小型函式)
												//使用inline,應將函式定義於表頭檔,提供編譯器進行擴展
{
	static  int a = 0;
	return a++;
}

int mainLine() {
	int a = 0;
	while ((a = call()) < 20)		//此處call()擴展成a++;
		cout << a << endl;

	system("pause");
	return 0;
}