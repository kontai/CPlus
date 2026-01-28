#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/18
*AuTHOR:kontai
*
*/

const int var = 100;	//c++全局const變量,在編譯階段,會被優化成字面量使用 

void test1() {
	cout << "var= " << var << endl;	//經過優化後,cout<<"var= "<<100<<endl;
	const int b = 20;
	int* p = (int*)&b;	//通過指針修改const變量)
	*p = 30;	
	cout << "b= " << b << endl;
	cout << "*p= " << *p << endl;
	//int* p = (int*)&var; 
	//*p = 20;
	//printf("global_const_var = %d\n", var);
}

int main() {
	test1();

	return EXIT_SUCCESS;
}