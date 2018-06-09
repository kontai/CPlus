#include<iostream>
#include <cassert>
#include <string>

using namespace std;

int mainNDEBUG() {
	/*
#ifndef NDEBUG
	cerr << "從ifndef到endif之間的程式碼,只有在開發時會執行"
			<< "\n開發完成,此段程式碼可藉由#define NZDEBUG來移除";

	string str;
	cin >> str;
	assert(isupper(str[0]));
	//當首字非大寫字母,返回false,assert當中斷程序,並顯示錯誤訊息
	///////////////////
	assert : 非標準庫函數,而是巨集NDEBAUG所定義
	#ifdef NDEBUG
	#define assert(condition) ((void)0)
	#else
	#define assert(condition) /*implementation defined*/
	//////////////////

	 /*
		 可選輸出訊息
		 cerr << "檔案:" << __FILE__
			 << "\n目前行號:" << __LINE__
			 << "\n日期:" << __DATE__
			 << "\n時間:" <<__TIME__;
	  */
	system("pause");
	return 0;
}