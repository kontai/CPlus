/****************************************
[4/4/2017  15:41]
class宣告與定義.cpp
****************************************/

#include<iostream>

using namespace std;
//宣告,但無定義(不完整的型別);
 //class使用前必須定義,不然編譯器不知道存放這型別的物件,該分配多少大小
class Nondefind;

class Load {
	//Nondefind a;

	Nondefind *b;
};

class X {
	//此處X尚未完整定義,但只要宣告過,就可拿自身pointer 或 reference 做自己的成員變數
	X  *Y;
};
class Y {
	//相互調用
	X de;
	X *call;
	Y *th;
};

///////以上為定義一個class,但未分配使用空間

int mainClassDeclare() {
	/*
		//錯誤:未定義的class
		Nondefind obj;

		//錯誤,pointer 或 reference 調用前,就必須要完整定義
		Nondefind *obj;
	*/

	//定義物件,並分配空間(空間足以容納放置一個該class物件)
	X abc;

	//每個物件都有各自儲存空間,並與其他物件獨立
	X def;

	system("pause");
	return 0;
}