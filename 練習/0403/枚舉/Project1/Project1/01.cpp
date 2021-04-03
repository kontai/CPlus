/*
*	01
*	2021/04/03
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#if 0
using namespace std;

inline extern int sub2num(int a, int b)
{
	return a - b;
}

int main() {

	enum WEEK{mon=1,thu,thr,wed,fri,sat,sun};
	WEEK enum1 = mon;
	cout << enum1 << endl;;
	cout << WEEK::fri << endl;
	//cout << typeid(WEEK).name() << endl;
	int sum=sub2num(1, 2);
	cout << sizeof(enum1) << endl;

	system("pause");
	return EXIT_SUCCESS;
}
#endif
