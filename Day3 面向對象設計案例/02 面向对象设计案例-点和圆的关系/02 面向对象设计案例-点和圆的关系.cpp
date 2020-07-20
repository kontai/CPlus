#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "circle.h"
#include "point.h"
/*
設計一個圓形類（AdvCircle），和一個點類（Point），計算點和圓的關係。
假如圓心坐標為x0, y0, 半徑為r，點的坐標為x1, y1
*/

//利用全局函數 判斷點和圓的關係
void isInCircle(Circle & c,Point &p)
{
	//獲取圓心和點的距離 的平方
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int rDistance = c.getR() * c.getR();

	if (rDistance == distance)
	{
		cout << "點在圓上" << endl;
	}
	else if ( rDistance > distance)
	{ 
		cout << "點在圓內" << endl;
	}
	else
	{
		cout << "點在圓外" << endl;
	}
}

void test01()
{
	Point p1;
	p1.setX(10);
	p1.setY(11);

	Circle c1;
	Point center;
	center.setX(10);
	center.setY(0);
	c1.setCenter(center);
	c1.setR(10);


	//利用全局判斷點和圓的關係
	isInCircle(c1, p1);

	//利用成員函數判斷點和圓的關係
	c1.isInCircleByClass(p1);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}