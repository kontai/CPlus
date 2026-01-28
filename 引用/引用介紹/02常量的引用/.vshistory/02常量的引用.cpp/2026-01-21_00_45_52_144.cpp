#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/01/21
*AuTHOR:kontai
*
*/

int main() {
	int a = 10;
	int &ref = a;
	ref = 20;

	int& ref2 = 10;
	const int& ref3 = 10;
	ref3 = 200;

//bool?型
	bool is = 0;//注意：is的值除0以外，都是真
	if (is)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}
	return EXIT_SUCCESS;
}