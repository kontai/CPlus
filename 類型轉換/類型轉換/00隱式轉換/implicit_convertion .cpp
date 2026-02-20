#include<iostream>

using namespace std;

/*
算術提升（integer promotion）

*/

//char 可能是 unsigned 或 signed。
//一個負值被提升後，符號擴展會影響結果
void f01() {
	char c = 1;
	int x = c;   // 自動提升
	cout << "x:  " << x << endl;

	char c2 = -1;
	unsigned	int x2 = c2;	// 當char是負值時，unsigned int 會自動轉成正值，符號擴展會影響結果。
	cout << "x2:  " << x2 << endl;
	cout << endl;
}

	//narrowing conversion（窄化轉換）
void f02(){
	cout << "narrowing conversion（窄化轉換）" << endl;
	double d = 3.14;
	int i = d;   // 小數直接砍掉
	cout << "i: " << i << endl;

	//C++11 之後你可以用 {} 防止這種危險
	//int j = { 3.14 };	//編譯器會報錯，因為 3.14 不能被直接轉換成 int。
}

int main() {
	f01();
	f02();

	return 0;
}