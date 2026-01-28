#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/21
*AuTHOR:kontai
*
*/

//1.ㄧ计把计肚患
void fun(int& a,int &b) {
	int sum = a + b;
	cout << "sum=" << sum << endl;

}
void test01() {
	int a = 10;
	int b = 20;
	fun(a, b);
}

//2.まノㄧ计
 int& fun2() {
	int b = 20;
	 int& ref = b;
	return ref;
}
 void test02() {
	int &c=fun2();
	c = 20;
	cout << "c=" << c << endl;
 }

int main() {
	//test01();
	test02();

	return EXIT_SUCCESS;
}