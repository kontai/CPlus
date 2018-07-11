/*************************
[17/6/2018 16:02
聯合體union.cpp
*************************/

#include<iostream>

using namespace std;

union Mark
{
	char grade;
	bool pass;
	int percent;
};

int mainUNI(){
	Mark a;
	a.grade = 'A';
	cout << a.pass << endl;
	cout << a.grade << endl;
	cout << sizeof(a)<<endl;
	a.pass = true;
	cout << a.pass << endl;
	cout << a.grade << endl;
	cout << sizeof(a)<<endl;  
	// 聯合體只能同時存在一個數據,新增的將會取代舊的
	// 聯合體所有成員共用一塊存儲空間
	// 聯合體所佔內存大小,為所有成員類型尺寸最大的(int:4,bool:1...)
	

	system("pause");
	return 0;
}