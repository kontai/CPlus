/*************************
[18/6/2018 6:53
emum_class.cpp
*************************/
/*
格式:
enum class 枚舉類名:底層類型(預設int){枚舉列表};

Example:
enum class Type{General,Light,Medium,Heavy};
enum class Type:char{General,Light,Medium,Heavy};
enum class Category{General=1,Pistol,MachineGun,Canon};

好處:
1.作用域強制: 其作用域限制在枚舉類中
	例:使用Type的枚舉值    General Type::General
2.限制隱式轉換: 枚舉類對象不可與整形隱式地互相轉換
3.可指定底層類型
*/
#include<iostream>

using namespace std;

enum class Side{Right,left};
enum class Thing{Wrong,Right}; //不衝突

//enum  Side {Right2,left};
//enum  Thing {Wrong,Right}; 枚成員重複定義

int mainEM(){
	Side s = Side::Right;
	Thing w = Thing::Wrong;

//編譯錯誤,無法直接比較不同枚舉類
//	cout << (s == w) << endl;  


	system("pause");
	return 0;
}