#include "MyArray.h"

//默認構造
MyArray::MyArray()
{
	this->m_Capacity = 100;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}
//有參構造  參數 數組容量
MyArray::MyArray(int capacity)
{
	//cout << "有參函數調用" << endl;
	this->m_Capacity = capacity;
	this->m_Size = 0;
	this->pAddress = new int[this->m_Capacity];
}

//拷貝構造
MyArray::MyArray(const MyArray& array)
{
	cout << "拷貝構造調用" << endl;
	this->pAddress = new int[array.m_Capacity]; 
	this->m_Size = array.m_Size;
	this->m_Capacity = array.m_Capacity;

	for (int i = 0; i < array.m_Size;i++)
	{
		this->pAddress[i] = array.pAddress[i];
	}

}
//析構
MyArray::~MyArray()
{
	if (this->pAddress != NULL)
	{
		//cout << "析構調用" << endl;
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
}

void MyArray::push_Back(int val)
{
	//判斷越界？ 用戶自己處理
	this->pAddress[this->m_Size] = val;
	this->m_Size++;
}

int MyArray::getData(int index)
{
	return this->pAddress[index];
}

void MyArray::setData(int index, int val)
{
	this->pAddress[index] = val;
}

int MyArray::getSize()
{
	return this->m_Size;
}

int MyArray::getCapacity()
{
	return this->m_Capacity;
}

//[]重載實現
int& MyArray::operator[](int index)
{

	return this->pAddress[index];
}
