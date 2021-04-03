/*
*	OPERATOR_LM
*	2021/03/14
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
class op_lm {
	friend  ostream& operator<<(ostream& out, op_lm& ob);
public:
	op_lm(){}
	//void show_num() { cout << m_num; }
private:
	int m_num=2;
};
ostream& operator<<(ostream& out, op_lm& ob) {
	out << ob.m_num;
	return out;
}

int main() {
	//¥ª²¾¹Bºâ²Å­«¸ü
	op_lm ob1;
	//ob1.show_num();
	cout << ob1 << endl;
	system("pause");
	return EXIT_SUCCESS;
}