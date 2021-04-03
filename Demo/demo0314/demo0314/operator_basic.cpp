/*
*	OPERATOR_BASIC
*	2021/03/14
*	重載-基本運算
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class op_basic{
public:
	op_basic() { m_num = 0; }
	op_basic(int num) { this->m_num = num; }

	int show_num() {
		return m_num;
	}

	op_basic& operator+(op_basic& ob) {
		op_basic temp;
		temp.m_num = this->m_num + ob.m_num;
		return temp;
	}

	op_basic& operator+(int a) {
		this->m_num += a;
		return *this;
	}

private:
	int m_num;

};


int main基本運算符重載() {
	op_basic ob1(3);
	op_basic ob2(2);
	op_basic ob3 = ob1 + ob2;
	ob3 = ob3 + 1;
	cout << "ob1=" << ob1.show_num() << ",ob2=" << ob2.show_num() << endl;
	cout << "ob3=" << ob3.show_num() << endl;

	system("pause");
	return EXIT_SUCCESS;
}