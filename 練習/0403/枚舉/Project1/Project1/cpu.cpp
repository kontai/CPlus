/*
*	CPU
*	2021/04/03
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cpu.h"

using namespace std;

CPU::CPU() { cout << "calling CPU contractor" << endl; }

/*
CPU::CPU(CPU_rank r, double f, int v) :rank(r), frequency(f ), voltage(v ) {
	cout << "生產了一顆CPU" << endl;
}
*/

CPU::CPU(CPU_rank r, double f, int v){
	this->rank = r;
	this->frequency = f;
	this->voltage = v;
	cout << "生產了一顆CPU" << endl;
}
CPU::CPU(const CPU &cpu)
{
	cout << "CPU的拷貝構造調用" << endl;
}

CPU::~CPU() { cout << "CPU析構函式調用" << endl; }

void CPU::showInfo()
{
	cout << "CPU-----------" << endl;
	cout << "\tFrequency:" << frequency << endl;
	cout << "\tVoltage:" << voltage << endl;
}

//class CPU {
//public:
//	friend void test();
//
//	CPU() { cout << "calling contractor" << endl; }
//	CPU(CPU_rank r, double f, int v) :rank(r), frequency(f = 0), voltage(v = 0) {
//		cout << "manufactures a CPU" << endl;
//	}
//	~CPU() { cout << "calling decontractor" << endl; }
//
//private:
//	int getVoltage() const{
//		return voltage;
//	}
//
//
//	CPU_rank rank;
//	double frequency;
//	int voltage;
//};

