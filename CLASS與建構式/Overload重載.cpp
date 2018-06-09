#include<iostream>
#include <string>

using namespace std;

/*
  更:
  ()ㄧ计,琌把计ぃ(ぃ)
  ()ゲ斗ノ办柑(絪亩竟碝тㄧ计,暗浪代)
  ()把计计秖籔,琌更跋だ兵ン
 */

void wh(int) {
};
void wh(double);
//void wh(const double); //error:狦ま计ぃ琌reference,const籔獶const龟悔琌(琌狡籹ま计)

//const reference diff. w/ reference
void wh(const string &);
void wh(string &);

long wh(long*);
long wh(long *const); //狡(const皐セō[狡籹],τ獶┮)

int *wh(int*);
double *wh(double*);

int mainOver_load() {
	wh("warning ");
	wh(1.22);
	wh(20);

	system("pause");
	return 0;
}

long wh(long * const) {
	return 0;
}
