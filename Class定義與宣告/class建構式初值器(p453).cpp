/****************************************
[4/24/2017  21:05]
class建構式初值器.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

/*
 * 對於const類型或reference類型成員變數,或其class型別沒有default建構式的成員變數
 * 必須使用初值器初始化
 */
class constRef {
public:
	//利用初值列初始化
	constRef(int jj) :i(jj), ci(jj), ri(jj) {
	};
	/*
		//在建構式主體,利用"賦值"初始化"

		constRefII(int jjj)
		{
			i = jjj;
			//ci = jj;  //錯誤,const無法賦值
			ri = jjj;
		}
	*/
private:
	int i;
	const int ci;
	int &ri;
};

//建構式初始化順序//
/*
 * 建構式初始化順序是根據變數定義順序,不是初始化執行順序
 */

class Order {
	int i;
	int j;
public:
	Order(int val) :j(val), i(j) {
	} //錯誤,拿未被初始化的j來初始化i
};

class Sales_item {
public:
	Sales_item(const string &book) :isbn(book), units_sold(0), revenus(0.0) {
	}

	//參數列如有預設引數,將會取代預設建構式
	//Sales_item(const string &num=""):isbn(num),units_sold(0),revenus(0.0){ }

	//以下兩個建構式由於都是預設建構式,當定義class對象沒給引數時,會造成衝突
	Sales_item(istream &is = cin); //將cin作為參數列引數

	// "已有預設引數"與下列建構式(default初始值)重複
	//Sales_item():units_sold(0),revenus(0.0){ }

private:
	string isbn;
	int units_sold;
	double revenus;
};


int mainClassInit() {
	//Sales_item next;
	Sales_item last("9-99-999");
	//Sales_item  fin(cin);

	system("pause");
	return 0;
}