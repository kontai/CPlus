#include<iostream>
#include <string>

using namespace std;

/*
更:
()ㄧ计,琌把计ぃ(ぃ)
()ゲ斗ノ办柑(絪亩竟碝тㄧ计,暗浪代)
()把计计秖籔,琌更跋だ兵ン
*/

void wh(int a) {
	cout << a << endl;
}

void wh(double a) {
	cout << a << endl;
}
//void wh(const double); //error:狦ま计ぃ琌reference,const籔獶const龟悔琌(琌狡籹ま计)

//const reference diff. w/ reference
//void wh(const string &);
void wh(string &a) {
	cout << a << endl;
}

//long wh(long*);
//long wh(long *const); //狡(const皐セō[狡籹],τ獶┮)

int *wh(int*a) {
	cout << a << endl;
	return a;
}
double *wh(double*a) {
	cout << a << endl;
	return a;
}

int mainOverload() {
	string ss = "One Two Three";
	wh(ss);
	wh(1.22);
	wh(20);

	system("pause");
	return 0;
}

long wh(long * const) {
	return 0;
}