#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	int m_A; //非靜態成員變量，屬於對像身上
	void func( ) {}; //非靜態成員函數 不屬於對像身上
	static int m_B; //靜態成員變量 ，不屬於對像身上
	static void  func2(){}; //靜態成員函數 ，不屬於對像身上
	double m_C; // 12 錯誤  16正確
};

//結論 ： 非靜態成員變量 ，才屬於對像身上

void test01()
{
	// 6 、 0 、 4 、 1
	cout << "sizo of (Person) = " << sizeof(Person) << endl;
	//空類的大小為 1  每個實例的對象 都有獨一無二的地址，char維護這個地址
	// Person p[10]  p[0] p[1]
}


void test02()
{
	//this指針指向被調用的成員函數所屬的對象

	Person p1;
	p1.func(); //編譯器會偷偷 加入一個 this指針  Person * this

	Person p2;
	p2.func();
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}