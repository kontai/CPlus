#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/02/05
*AuTHOR:kontai
*
*/

void func() {
	string s("some string");

	//利用迭代器修改string內容
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s << endl;
}

int main() {
	func();
	
	return EXIT_SUCCESS;
}