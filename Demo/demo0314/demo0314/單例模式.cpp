/*
*	NULL_CLASS
*	2021/03/14
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "null_class.h"

using namespace std;

int One::func() {
	return 0;
}

OneClass* OneClass::newObject = new OneClass;
int  OneClass::count = 0;
int main³æ¨Ò¼Ò¦¡() {
	//cout << sizeof(One) << endl;
	OneClass *oc1=OneClass::creator();
	OneClass *oc2=OneClass::creator();
	cout << (oc1 == oc2 ? "true" : "false") << endl;
	cout << (OneClass::count) << endl;

	system("pause");
	return EXIT_SUCCESS;
}