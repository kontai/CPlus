#include <iostream>

using namespace std;
class Maker {
public:
	//無參數建構子
	Maker() {
		this->a = 0;
		cout << "Maker() called" << endl;
	}

	//有參數建構子
	Maker(int a) {
		this->a = a;
		cout << "Maker(int a) called, a = " << a << endl;
	}

	//複製構造函數
	Maker(const Maker& m) {
		this->a = m.a;
		cout << "Copy constructor called, a = " << a << endl;
	}

	~Maker() {
		cout <<  "~Maker() called" << endl;
	}

private:
	int a;
};

void fun() {
	Maker m1;
	Maker m2(10);
	Maker m3 = m2; //呼叫複製構造函數
	Maker m4(m2); //呼叫複製構造函數
	Maker m5;
	m5 = m4;	//不會呼叫複製構造函數，這是指派運算子
	Maker m6 = 20;	//呼叫有參數建構子
	Maker m7 = Maker();	//臨時物件，會呼叫無參數建構子

	Maker();	//臨時物件，會呼叫無參數建構子

}


int main()
{
	//fun();
	return 0;
}