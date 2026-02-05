#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

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

void iterType() {
	vector<int>::iterator it;	//iterator可以修改內容
	vector<int>::const_iterator cit;	//const_iterator不能修改內容

	vector<int> v01;
	const vector<int> cv01;
	auto it1 = v01.begin();
	auto cit1 = cv01.begin();
}
int main() {
	func();

	return EXIT_SUCCESS;
}