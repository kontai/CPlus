#pragma once

class Circle {
public:
	void setR(double r);
	double getR();
	double getArea();
	double getPrimeter();
	Circle operator==(Circle&);
private:
	double r;
	double primeter;
	double area;
};

int main(void);
