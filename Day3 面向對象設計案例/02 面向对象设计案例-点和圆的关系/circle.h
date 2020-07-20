#pragma  once
#include <iostream>
using namespace std;
#include "point.h"

//圓類
class Circle
{
public:

	//設置半徑
	void setR(int r);
	/*{
		m_R = r;
	}*/
	//獲取半徑
	int getR();
	/*{
		return m_R;
	}*/

	//設置圓心
	void setCenter(Point p);
	/*{
		m_Center = p;
	}*/
	//獲取圓心
	Point getCenter();
	/*{
		return m_Center;
	}*/

	//利用成員函數判斷點和圓關係
	void isInCircleByClass(Point & p);
	//{
	//	//獲取圓心和點的距離 的平方
	//	int distance = (m_Center.getX() - p.getX()) * (m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY()) * (m_Center.getY() - p.getY());
	//	int rDistance = m_R* m_R;
	//	if (rDistance == distance)
	//	{
	//		cout << "成員函數：：點在圓上" << endl;
	//	}
	//	else if (rDistance > distance)
	//	{
	//		cout << "成員函數：：點在圓內" << endl;
	//	}
	//	else
	//	{
	//		cout << "成員函數：：點在圓外" << endl;
	//	}
	//}

private:
	int m_R; //半徑
	Point m_Center; //圓心
};