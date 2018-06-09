#include <iostream>
#include <cassert>
#include<string>

using namespace std;

const string &str(const string &a, const string &b) {
	string tmp = a;
	return tmp; //返回reference to local object會產生錯誤,函式結束,local記憶體空間被釋放,返回所參照的是不明記憶體位置
}

int mainRfToLocal(int argc, char *argv[]) {
	string x("abc"), y("def");
	string ss = str(x, y);
	cout << ss << endl;

	system("pause");
	return EXIT_SUCCESS;
}