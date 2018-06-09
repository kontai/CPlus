/****************************************
[4/18/2017  21:30]
class作用域.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

char test;

class PlanA {
public:
	typedef string::size_type index;
	char ch;
	int ia;
	index info(index, index)const;
	void test_func(char test) //以下為作用域範例
	{
		char in_local = test;

		char in_class = this->test;
		//or
		char in_class_2 = PlanA::test;

		char in_global = ::test;
	}
	PlanA() :ch('a'), ia(0) {
	}
	/*
	 * class成員定義式內的名稱搜尋:
	 * 搜尋順序:
	 * 成員函式local作用域內宣告--> class成員宣告-> 出現於成員函式定義式前的作用域內的宣告
	 */
	 //	typedef char index;
private:
	char test;
};

class PlanB {
public:
	char ch;
	int ia;
};
PlanA::index PlanA::info(index x, index y)const
//index定義於class,此處再class作用域外,所以要全名修飾
//class外部成員函式,在函式名稱後的引數&函式主體,會被當作class內部定義,不必全名修飾
//此主體也在class作用域裡,所以可直接使用class物件
{
	x = ch;
	return x;
}

//PlanA::index whatb(PlanA::index);
PlanA::index whata(PlanA::index ca) {
	typedef PlanA::index index; //m.....
	index a;
	//a = whatb(ca);
	return ca;
}
int mainScope() {
	//PlanA yank;
	//PlanB yank2=yank; //錯誤,yank與yank2不同型別

	PlanA woo;
	PlanA *haa = &woo;  //利用指標存取refence的成員
	haa->ch = 2;
	woo.ch = 3;
	PlanA **gain = &haa;
	(*gain)->ch = 4;

	system("pause");
	return 0;
}