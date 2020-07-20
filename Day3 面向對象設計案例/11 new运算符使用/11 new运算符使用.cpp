#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默認構造調用" << endl;
	}

	Person(int a)
	{
		cout << "有參構造調用" << endl;
	}

	~Person()
	{
		cout << "析構函數調用" << endl;
	}

};

void test01()
{
	//Person p1;  棧區開闢

	Person * p2 = new Person; //堆區開闢

	//所有new出來的對象 都會返回該類型的指針
	//malloc 返回 void* 還要強轉
	//malloc會調用構造嗎？ 不會  new會調用構造
	// new 運算符  malloc 函數
	//釋放 堆區空間
	// delete也是運算符 配合 new用  malloc 配合 free用
	delete p2;

}

void test02()
{
	void *p = new Person(10); 
	//當用void* 接受new出來的指針 ，會出現釋放的問題
	delete p;
	//無法釋放p ，所以避免這種寫法
}

void test03()
{
	//通過new開闢數組 一定會調用默認構造函數,所以一定要提供默認構造
	Person * pArray = new Person[10];
	//Person pArray2[2] = { Person(1), Person(2) }; //在棧上開闢數組，可以指定有參構造


	//釋放數組 delete []
	delete [] pArray;
}

int main(){

	//test01();

	//test02();

	test03();

	system("pause");
	return EXIT_SUCCESS;
}