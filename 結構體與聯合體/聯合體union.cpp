/*************************
[17/6/2018 16:02
�p�X��union.cpp
*************************/

#include<iostream>

using namespace std;

union Mark
{
	char grade;
	bool pass;
	int percent;
};

int mainUNI(){
	Mark a;
	a.grade = 'A';
	cout << a.pass << endl;
	cout << a.grade << endl;
	cout << sizeof(a)<<endl;
	a.pass = true;
	cout << a.pass << endl;
	cout << a.grade << endl;
	cout << sizeof(a)<<endl;  
	// �p�X��u��P�ɦs�b�@�Ӽƾ�,�s�W���N�|���N�ª�
	// �p�X��Ҧ������@�Τ@���s�x�Ŷ�
	// �p�X��Ҧ����s�j�p,���Ҧ����������ؤo�̤j��(int:4,bool:1...)
	

	system("pause");
	return 0;
}