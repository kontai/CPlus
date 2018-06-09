/****************************************
[5/13/2017  16:21]
Copy 建構式cpp.cpp

複製建構式主要以reference形式參數
****************************************/

#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Sales_item {
public:
	Sales_item() :contents(""), unit_sold(0), revenus(0) {
		cout << "Sales_item()" << endl;
	}
	Sales_item(const string &book) :contents(book), unit_sold(0), revenus(0) {
		cout << "Sales_item(const string &book)" << endl;
	}

	Sales_item(const Sales_item& rhs) :
		contents(rhs.contents), unit_sold(rhs.unit_sold), revenus(rhs.revenus) {
	cout << "Sales_item (const Sales_item&)" << endl;
}

	Sales_item& operator=(const Sales_item& rhs){
		contents = rhs.contents;
		unit_sold = rhs.unit_sold;
		revenus = rhs.revenus;
		cout << "Sales_item& operator=(const Sales_item&)" << endl;
		return *this;
	}



	~Sales_item()
	{
		cout << "~Sales_item()" << endl;
	}

		
private:
	string contents;
	int unit_sold, revenus;
};

//當引數為class對象,且非reference,copy建構式就會被調用
//non-class函數調用完畢,解構式也會被喚起,刪除暫時的副本

void fun1(Sales_item) {
}

void fun2(Sales_item& omg)
{
}

Sales_item fun3(Sales_item omg)
{
	Sales_item temp;
	temp = omg;
	return temp;
}

int mainCopyS(){
	Sales_item a;
	Sales_item b;
	fun1(a);
	fun2(a);
	a = b;
	Sales_item item = "abc";
	cout << "\n\n-------------" << endl;
	Sales_item c;
	c = fun3(item);
	cout << "-------------\n" << endl;

	vector<Sales_item>d(3);
	cout << "\n\n-------------" << endl;
	Sales_item e[3];
	cout << "\n\n-------------" << endl;

system("pause");
return 0;
}