#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/21
*AuTHOR:kontai
*
*/

void fun(int& a,int &b) {
	int sum = a + b;
	cout << "sum=" << sum << endl;

}
void test01() {
	int a = 10;
	int b = 20;
	fun(a, b);
}

int main() {
	test01();
	
	return EXIT_SUCCESS;
}