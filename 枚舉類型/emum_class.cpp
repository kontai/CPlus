/*************************
[18/6/2018 6:53
emum_class.cpp
*************************/
/*
�榡:
enum class �T�|���W:���h����(�w�]int){�T�|�C��};

Example:
enum class Type{General,Light,Medium,Heavy};
enum class Type:char{General,Light,Medium,Heavy};
enum class Category{General=1,Pistol,MachineGun,Canon};

�n�B:
1.�@�ΰ�j��: ��@�ΰ쭭��b�T�|����
	��:�ϥ�Type���T�|��    General Type::General
2.���������ഫ: �T�|����H���i�P��������a�����ഫ
3.�i���w���h����
*/
#include<iostream>

using namespace std;

enum class Side{Right,left};
enum class Thing{Wrong,Right}; //���Ĭ�

//enum  Side {Right2,left};
//enum  Thing {Wrong,Right}; �T�������Ʃw�q

int mainEM(){
	Side s = Side::Right;
	Thing w = Thing::Wrong;

//�sĶ���~,�L�k����������P�T�|��
//	cout << (s == w) << endl;  


	system("pause");
	return 0;
}