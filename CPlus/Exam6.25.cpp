#include<iostream>
#include<cassert>
#include<string>

using namespace std;

int mainExam6_25() {
	string str;
	while (cin >> str) {
#ifndef NDEBUG
		cout << str << endl;  //開發模式,輸出str		發行模式,此段不會執行
#endif
	}

	system("pause");
	return 0;
}