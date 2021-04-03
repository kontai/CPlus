/*
*	MEM
*	2021/04/03
*
*/

#include<iostream>
#include"MEM.h"

using namespace std;

MEM::MEM() { cout << "calling MEM contractor" << endl; };

/*
MEM::MEM(int s, int p) :size(s ), price(p ) {
	cout << "生產了一支記憶體" << endl;
}
*/

MEM::MEM(int s, int p) {
	this->size = s;
	this->price = p;

	cout << "生產了一支記憶體" << endl;
}

MEM::MEM(const MEM &mem)
{
	cout << "MEM的拷貝構造調用" << endl;
}

void MEM::showInfo()const {
	cout << "Memory-----------" << endl;
	cout << "\tsize:" << size << endl;
	cout << "\tprice:" << price << endl;
}
MEM::~MEM() { cout << "MEM析構函數調用" << endl; }
