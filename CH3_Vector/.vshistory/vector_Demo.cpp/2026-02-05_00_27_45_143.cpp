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

	vector<int>vc1 = v2; 		//複製v2給vc1
	vector<int>vc2(v2);			//複製v2給vc2
	//vector<string>sv = vc1;	//錯誤,型態不符

	vector<string> v6{ "hi" };		//1個元素,值為"hi"
	//vector<string>v7("hi");	//錯誤,無法將字串轉換為整數
	vector<string>v8{ 10 };	//10個元素,預設值為空字串
	vector<string>v9{ 10,"hi" };	//10個元素,每個元素值為"hi"
	vector<string>v10(10, "hi"); //10個元素,每個元素值為"hi"	,與上行等價
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

void addElement() {
	vector<int> vec;	//空vector
	for (decltype(vec.size())i = 0; i < 10; i++) {
		//vec[i] = (int)i;	//錯誤,vec沒有元素,無法使用下標存取
		vec.push_back(i);
	}
}
int main() {
	func();
	addElement();
	return EXIT_SUCCESS;
}