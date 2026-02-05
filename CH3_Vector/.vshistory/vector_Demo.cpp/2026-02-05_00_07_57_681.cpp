#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

/*
*2026/02/05
*AuTHOR:kontai
*
*/

void func() {
	vector<int> viarr{ 1,2,3,4,5,6,7,8,9,10 };
	for (auto& i : viarr) {	//使用參考方式修改元素
		i <<= 1;	//每個元素左移1位元(乘以2)
	}

	for (auto i : viarr) {
		cout << i << ' ';
	}
}
int main() {
	func();
	return EXIT_SUCCESS;
}