#ifndef _COMPUTER_H_
#define _COMPUTER_H_
#include<string>
#include "cpu.h"
#include "MEM.h"


class Computer {
public:
	Computer();
	Computer(const CPU &c,const MEM &m,int p,std::string b);
	~Computer();
	void showInfo();
private:
	CPU cpu;
	MEM mem;
	int price;
	std::string brand;

};




#endif

