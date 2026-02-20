#include<iostream>
using namespace std;

//template<class T>
template<typename T>
void mySwap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}


template<typename T>
void mySwap2(T a,T b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
void mySwap3();

int main() {
	int a = 10;
	int b = 20;
	double c = 3.22;

	mySwap(a, b);	//類型推斷
	mySwap<>(a, b);	//類型推斷
	mySwap<int>(a, b);	// 顯式模板類型
	//mySwap<int>(a, c);	// 當型參為引用時，實參類型不匹配，編譯器會報錯
	//mySwap2(a, c);		//自動推導, 類型不匹配
	mySwap2<int>(a, c);	//明確告訴編譯器 T=int,會隱式轉換
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//mySwap2();	// 未指定類型，編譯器會報錯
	mySwap3<int>();	// 顯示模板類型



	return 0;
}