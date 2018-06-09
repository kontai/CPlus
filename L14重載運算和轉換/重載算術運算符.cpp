/****************************************
[5/23/2017  21:18]
重載算術和關係運算符.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Sales_item3
{
public:
	Sales_item3(const string &book,const int units,const double amount):
		isbn(book),unit_sold(units),revenue(amount){ }
/*
 * 由於+= , -= 等算術運算子需要返回的是class對象,所以習慣上都重載為成員函數
 * 參數列只有一個形參(左運算元隱喻this)
 */
	Sales_item3& operator+=(const Sales_item3&);
	Sales_item3& operator-=(const Sales_item3&);
	friend ostream& operator<<(ostream &, const Sales_item3&);

private:
	string isbn;
	int unit_sold;
	double revenue;
};

Sales_item3& Sales_item3::operator+=(const Sales_item3& rhs)
{
  //"this->"可不用寫(已在class作用域內)
	this->unit_sold += rhs.unit_sold;
	this->revenue += rhs.revenue;
	return *this;
}

Sales_item3 operator+(const Sales_item3& lhs,const Sales_item3& rhs){
	/*
	 * 如同一般正規加法運算,相加運算後,將結果傳給新對象(左值)
	 * 且返回值非reference,所以將一般+,-運算設成non-class函數
	 */
	Sales_item3 ret(lhs); 
	ret += rhs;
	return ret;
}

Sales_item3& Sales_item3::operator-=(const Sales_item3& rhs)
{
	
	this->unit_sold -= rhs.unit_sold;
	this->revenue -= rhs.revenue;
	return *this;
}

Sales_item3 operator-(const Sales_item3& lhs, const Sales_item3& rhs) {
	Sales_item3 ret(lhs);
	ret -= rhs;
	return ret;
}
 ostream& operator<<(ostream& out, const Sales_item3& rhs){
	 out << rhs.isbn << "\t" << rhs.unit_sold << "\t" << rhs.revenue << endl;
	 return out;
 }
int mainArithm() {
	Sales_item3 item1(string("0-00-000"), 3, 20.0);
	Sales_item3 item2(string("0-00-000"), 6, 120.0);
	cout << item1 + item2 << endl;
	Sales_item3 item3(item1);
	item3 -= item1;
	cout << item3 << endl;
	


system("pause");
return 0;
}