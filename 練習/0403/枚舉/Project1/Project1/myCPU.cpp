#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Computer.h"

using namespace std;


void test() {
	CPU cpu01(p1, 666, 110);
	cpu01.getVoltage();
}
//����Comoputer class
/*
void test02(const CPU &cpu, const MEM &mem, int price, string brand) {
	Computer comp(cpu, mem, price, brand);
	try{
	comp.showInfo();
	}
	catch (Computer &e)
	{
		cout << "���~�o��" << endl;
	}
	catch (...) {

		cout << "���~�o��,���L�k�P�w�C" << endl;
	}
}
*/

void test03(Computer &comp) {
	try{
	comp.showInfo();
	}
	catch (Computer &e)
	{
		cout << "���~�o��" << endl;
	}
	catch (...) {

		cout << "���~�o��,���L�k�P�w�C" << endl;
	}
}

int  main()
{
	CPU cpu(p2, 3300, 220);
	MEM mem(32, 3000);
	Computer comp(cpu, mem, 14000, "ASUS");
	Computer *pComp = &comp;
	//test();
	//test02(cpu,mem,14000,"ASUS");
	test03(comp);

	system("pause");
	return 0;
}