#pragma  once
#include <iostream>
using namespace std;

class MyArray
{
public:
	MyArray(); //默認構造  默認100容量
	MyArray(int capacity);
	MyArray(const MyArray& array);

	~MyArray();


	//尾插法
	void push_Back(int val);

	//根據索引獲取值
	int getData(int index);

	//根據索引設置值
	void setData(int index, int val);

	//獲取數組大小
	int getSize();

	//獲取數組容量
	int getCapacity();

	//[]運算符重載
	int& operator[](int index );

private:
	int * pAddress; //指向真正存儲數據的指針
	int m_Size; //數組大小
	int m_Capacity; //數組容量

};