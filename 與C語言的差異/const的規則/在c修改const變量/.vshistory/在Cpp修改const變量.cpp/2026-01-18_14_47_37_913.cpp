#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/

const int var = 100;	//c++全局const變量,在編譯階段,會被優化成字面量使用

void test1() {

	cout << "var= " << var << endl;	//經過優化後,cout<<"var= "<<100<<endl;

	const int b = 20;
	int* p = (int*)&b;	//通過指針修改const變量)
	*p = 30;
	cout << "b= " << b << endl;	//因為b是const變量,編譯器編譯時優化,直接用20替換,所以這裡輸出還是20
	cout << "*p= " << *p << endl;	//實際記憶體中被修改了,所以這裡輸出30
}

void test2() {
	//volatile關鍵字告訴編譯器不要優化這個變量,每次都從記憶體中讀取
	volatile const int b = 20;

	int* p = (int*)&b;	//通過指針修改const變量)
	*p = 30;
	cout << "b= " << b << endl;	//因為b是const變量,編譯器編譯時優化,直接用20替換,所以這裡輸出還是20
	cout << "*p= " << *p << endl;	//實際記憶體中被修改了,所以這裡輸出30

	//取址
	cout << "&b= " << &b << endl;	//輸出1-----
	cout << "(int)&b= " << (int)&b << endl;
	cout << "p= " << p << endl;
}

int main() {
	//test1();
	test2();

	return EXIT_SUCCESS;
}