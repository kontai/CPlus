/*
*	2021/02/21 17:34
*	D:\workspace\CPlus\½m²ß\0221\demo0221\demo0221
*
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include "Circle.h"

using namespace std;


void Circle::setR(double r) {
	this->r = r;
}

double Circle::getArea() {
	return r * r * 3.14;
}

int main(void)
{
	Circle c1;
	c1.setR(10);
	cout << "¥b®|=" << c1.getArea() << endl;
	Circle c2 = Circle(c1);
	c2==c1?

	system("pause");
	return 0;
}