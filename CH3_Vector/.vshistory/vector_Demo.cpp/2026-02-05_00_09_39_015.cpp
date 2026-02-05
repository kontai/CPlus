#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

/*
*2026/02/05
*AuTHOR:kontai
*
*/

//vector初始化的方式
void vectorInitialization() {
	vector<int> v1;					//空vector
	vector<int> v2(10);				//10個元素,預設值為0
	vector<int> v3(10, 42);			//10個元素,每個元素值為42
	vector<int> v4{ 10 };			//1個元素,值為10
	vector<int> v5{ 10,42 };		//2個元素,值分別為10與4	2

}

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