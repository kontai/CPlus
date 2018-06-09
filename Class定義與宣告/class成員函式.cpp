#include<iostream>

using namespace std;

/************************************************************************/
/* class宣告式一般都放進表頭檔,ex:Sales_Item.h (class名稱命名)
* class主體外定義的成員函式則放進源檔(Sales_Item.ccp)
/*
/*	bool same_isbn(const Sales_Item &rha)	const	//
/*  函數末尾的const,指明此函數為const成員函數
/*  為隱喻的this參數型別,此處同等this->isbn(呼叫函數的物件,其物件的class成員isbn)
/*  "const物件"或者"point to const物件",只能用來呼叫const成員函數
/************************************************************************/

class Sales_Item {
public:
	double avg_prince() const;
	bool same_isbn(const Sales_Item &rha)	const		//定義於class內的成員函式,將被視為inline函式.
	{
		return isbn == rha.isbn;						//成員函式可存取其class的private成員
	}
	Sales_Item() :units_sold(0), revence(0.0) {
	}			//建構式:如同成員函式,但無型別;類名後接著引數列(可為空),後面的冒號一直到左大括號內可以設置成員函數初值(default).
				//建構式往往為了定義class內成員(非內建型別)的初值
	Sales_Item(const int &ir, const double &id) :units_sold(ir), revence(id) {
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revence;
};									//如同struct,class結束要加上分號;

double Sales_Item::avg_prince() const		//成員函式必須在class內定義,但函式主體可以在class外定義
{
	if (units_sold)
		return revence / units_sold;
	else
		return 0;
}

int mainClassSales() {
	system("pause");
	return 0;
}