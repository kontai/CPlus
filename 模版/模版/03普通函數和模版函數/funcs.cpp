#include<iostream>
using namespace std;

void func(int a, int b) {
	cout << "普通函數" << endl;
}

template<typename T>
void func(T a, T b) {
	cout<<"模版函數TT"<<endl;
}

template<typename T>
void func(T a, T b, T c) {
	cout << "模版函數TTT" << endl;
}

void testFunc() {

	int a=10;
	int b=20;
	func(a, b);	//類型匹配，不用二次轉換
	func<>(a, b);	//強制使用模板

	char x = 'a';
	char y = 'b';
	func(x, y);	//如果使用普通函數將會類型轉換,損失數據

}

int main() {

	testFunc();


	return 0;
}