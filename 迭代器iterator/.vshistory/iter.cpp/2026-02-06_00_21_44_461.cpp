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

	vector<int> v01{ 1,2,3,4,5 };
	const vector<int> cv01{ 10,11 };
	auto it1 = v01.begin();		//it1是vector<int>::iterator類型
	auto cit1 = cv01.begin();	//cit1是vector<int>::const_iterator類型

	auto it2 = v01.cbegin();		//it2是vector<int>::const_iterator類型(c++11)
									//不管v01是否為const，cbegin(),cend()都會返回const_iterator類型
	cout << *it1 << endl;
	cout << *cit1 << endl;
}
int main() {
	//func();
	iterType();

	return EXIT_SUCCESS;
}