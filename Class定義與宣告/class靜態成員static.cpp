/****************************************
[5/9/2017  20:58]
class靜態成員static.cpp
****************************************/

#include<iostream>
#include<string>

//static成員名稱落在class作用域中,可以避免和其他classes的成員或是和global物件發生名稱衝突
//厲行封裝。static成員可以是private,global物件卻不能
//閱讀程式碼可以輕鬆看出一個程式碼和其class之間有關聯,使程式意圖更清楚

using namespace std;

class Account {
public:
	void applyint() {
		amount += amount*interestRate;
	}

	static double rate() {
		return interestRate;
	}
	static void rate(double);

private:
	string owner;
	//static double amount;
	double amount;
	int  index;
	static double interestRate;
	static  double initRate();
	//整數型const static成員變數可以在class本體內直接初始化
	static const  int initVal = 3;
	//initVal是const;
	static double arr_con[initVal];
};

// **注意** static數據成員必須在類定義外部定義,且只定義一次
//在class外,不須再加上static關鍵字,這關鍵字只在class本體內宣告上出現
double Account::interestRate = 3.4;

void Account::rate(double newRate) {
	interestRate = newRate;
}

//const static 成員變數已經在class主體內初始化,仍要在外部定義
const int Account::initVal;

class Bar
{
public:
	//....
private:
	Bar *mem1;
	static Bar mam2; //static成員獨立於任何物件而存在
  //Bar mem3;		 //錯誤

public:
	Bar& wiii( char = red);
private:
	static const char red = '#';

};

int mainStaticClass() {
	Account ac1;
	Account *ac2 = &ac1;

	//以下是呼叫static rate()的三種等價方法
	double rate;
	rate = ac1.rate();
	rate = ac2->rate();
	rate = Account::rate(); //使用scope運算子,直接透過class取得(static特性)
	cout << rate << endl;

	system("pause");
	return 0;
}