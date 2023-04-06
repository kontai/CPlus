/*
*	COMPUTER
*	2021/04/03
*
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Computer.h"

using namespace std;

Computer::Computer() { cout << "calling Computer contractor" << endl; }

/*
Computer::Computer(CPU &c, MEM &m, int p, std::string b) :cpu(c), mem(m), price(p), brand(b) {
	cout << "�Ͳ��F�@�xComputer" << endl;
}
*/
Computer::Computer(const CPU &c, const MEM &m, int p, std::string b) {
	cpu = c;
	mem = m;
	price = p;
	brand = b;
	cout << "�Ͳ��F�@�xComputer" << endl;
}

void Computer::showInfo()
{
	cpu.showInfo();
	mem.showInfo();

	cout << "Computer---------" << endl;
	cout << "\tbrand:" << brand << endl;
	cout << "\tprice:" << price << endl;
}
Computer::~Computer() { cout << "Computer�R�c�禡�ե�" << endl; }
