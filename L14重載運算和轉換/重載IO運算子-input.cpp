/****************************************
[5/22/2017  22:16]
重載IO運算子-input.cpp
****************************************/

/*
 *格式:istream& operator>>(istream& in,Sales_item2& s)   
 *class-member不可設定為const(input目的就是寫至該對象)
 *
 * 與output不同的是,需要判斷輸入是否有效(*重要)
 */
#include<iostream>
#include<string>

using namespace std;

class Sales_item2
{
public:
	friend istream& operator>>(istream& in, Sales_item2& s);
	Sales_item2():units_sold(0),revenue(0){ }
private:
	string isbn;
	size_t units_sold;
	double revenue;

};

istream& operator>>(istream& in,Sales_item2& s){
	double price;
	in >> s.isbn >> s.units_sold >> price;
	//檢查輸入是否成功(此範例只做較為簡單的檢測--輸入成功就OK)
	//詳見p.287
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item2(); //輸入失敗:將物件重置為預設狀態
	return in;
}

int mainIO_input(){
	Sales_item2 a;
	Sales_item2 *b = new Sales_item2();
	cin >>a;


system("pause");
return 0;
}