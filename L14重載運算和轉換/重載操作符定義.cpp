/****************************************
[5/21/2017  10:39]
重載操作符定義.cpp
****************************************/

#include<iostream>
/*
 * 重載運算不可將build-in型別重新定義
 * int operator+(int,int) X錯誤
 * 
 * 不能為build-in型別定義新運算子
 * int a[10],b[19];
 * a+b   X build-in ints 無法做array相加
 *  
 * 重載運算子至少必須有一個class type 或 emuneration type(列舉)
 * 
 * 運算子優先順序(precedence)、結合率(Associativity)無法改變
 * = 、 [] 、 () 、 ->  必須定義為成員函式,否則編譯會出錯
 */
using namespace std;

class Sales_item
{
public:
	Sales_item(int c) :a(c){ }
	int  operator+(const Sales_item& ia2) {
		return a + ia2.a;
	}
	Sales_item& operator+=(const Sales_item& it2) {
		a += it2.a;
		return *this;
	}
	friend ostream& operator<<(ostream&, const Sales_item&);
	friend istream& operator>>(istream&, Sales_item&);
private:
	int a;
};

 ostream& operator<<(ostream& os, const Sales_item& out) {
	os << out.a << endl;
	return os;
}
istream& operator>>(istream& is, Sales_item& in) {
	is >> in.a ;
	return is;
}

int mainInstro(){
	Sales_item item1(3), item2(2);
	cout << item1+item2 << endl;
	cout << item1.operator+(item2) << endl;
	cin >> item1 >> item2;
	cout << item1+item2 << endl;



system("pause");
return 0;
}