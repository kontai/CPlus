#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "MyArray.h"
using namespace std;


void test01()
{
	//堆區創建數組
	MyArray * array = new MyArray(30);

	MyArray  * array2 = new MyArray(*array);  //new方式指定調用拷貝構造
	MyArray array3 = *array;    //構造函數返回的本體

	//MyArray * array4 = array; //這個是聲明一個指針 和array執行的地址相同，所以不會調用拷貝構造

	delete array;
	//尾插法測試
	for (int i = 0; i < 10;i++)
	{
		array2->push_Back(i);
	}
	//獲取數據測試
	for (int i = 0; i < 10;i++)
	{
		cout << array2->getData(i) << endl;
	}
	
	//設置值測試
	array2->setData(0, 1000);

	cout << array2->getData(0) << endl;;

	//獲取數組大小
	cout << "array2 的數組大小為： " << array2->getSize() << endl;


	//獲取數組容量
	cout << "array2 的數組容量為： " << array2->getCapacity() << endl;

	//獲取 設置 數組內容  如何用[]進行設置和訪問
	array3.push_Back(100000);
	cout << array3.getData(0) << endl;
	cout << array3[0] << endl;
	array3[0] = 100; // 100000 = 100
	cout << array3[0] << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}