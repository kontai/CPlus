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
	cout << "�Ͳ��F�@��O����" << endl;
}
*/

MEM::MEM(int s, int p) {
	this->size = s;
	this->price = p;

	cout << "�Ͳ��F�@��O����" << endl;
}

MEM::MEM(const MEM &mem)
{
	cout << "MEM�������c�y�ե�" << endl;
}

void MEM::showInfo()const {
	cout << "Memory-----------" << endl;
	cout << "\tsize:" << size << endl;
	cout << "\tprice:" << price << endl;
}
MEM::~MEM() { cout << "MEM�R�c��ƽե�" << endl; }
