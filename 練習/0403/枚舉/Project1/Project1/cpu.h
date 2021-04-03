#pragma once

enum CPU_rank { p1 = 1, p2, p3, p4, p5, p6, p7 };

class CPU {
public:
	friend void test();


	CPU();
	CPU(CPU_rank r, double f, int v);
	CPU(const CPU &cpu);
	~CPU();
	void showInfo();

private:
	int getVoltage() const {
		return voltage;
	}


	CPU_rank rank;
	double frequency;
	int voltage;
};
