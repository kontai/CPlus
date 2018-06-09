/*************************
[3/6/2018 7:44
empty_mapcpp.cpp
*************************/

#include<iostream>

using namespace std;

class Simple_1 {
public:
	Simple_1() :va1(0), va2(0), str("") {}
	Simple_1(int a, int b) :va1(a), va2(b) {}
	Simple_1(int a, string& b) :va1(a), str(b) {}

	friend const Simple_1& add_2c(const  Simple_1& r1, const  Simple_1& r2);
	friend void add_2(Simple_1&);
	//~Simple_1();

private:
	int va1, va2;
	string str;
};

void add_2(Simple_1& sp) {
	cout << sp.va1 + sp.va2 << endl;
}



const  Simple_1& add_2c(const   Simple_1& r1, const  Simple_1& r2) {
	Simple_1 temp;
	temp.va1 += r1.va1 + r2.va1;
	temp.va2 += r1.va2 + r2.va2;
	temp.str = r1.str + r2.str;
	cout << "temp.va1"<< temp.va1 << "\ttemp.va2"<< temp.va2 << endl;
	return temp;
}

int maini2() {
	Simple_1 a(2, 333);
	Simple_1 b(3, 555);

	add_2(a);
	add_2c(a, b);



	system("pause");
	return 0;
}