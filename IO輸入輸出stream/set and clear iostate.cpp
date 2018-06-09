#include<iostream>
#include <fstream>

using namespace std;

void out1(ifstream&in) {
	cout << "fail()=" << in.fail() << endl;
	cout << "eof()=" << in.eof() << endl;
}
void out() {
	cout << "fail()=" << cin.fail() << endl;
	cout << "eof()=" << cin.eof() << endl;
}
void clr() {
	cin.clear();
	cin.ignore(200, '\n');
}
void process_state() {
	int a;
	while (cin >> a, !cin.eof()) {
		out();
		if (cin.fail()) {
			clr();
		}
	}
}

int mainSet_iostate() {
	ifstream in;
	in.setstate(ifstream::failbit | ifstream::eofbit);		//設立failbit & badbit 為 "true" ;
	cout << "Origing in============" << endl;
	out1(in);
	istream::iostate old_in = in.rdstate();   //rdstate() : 目前iostate值 (以bitset方式儲存.處理)
	in.clear();					//清除iostates所有狀態;
	cout << "After clear() in============" << endl;
	out1(in);
	in.clear(old_in);    //回復原始iostates狀態
	cout << "After clear(old_in) in============" << endl;
	out1(in);
	/*
		istream::iostate old_state = in.rdstate();
		cin.clear();
		process_state();
		out();
		cin.setstate(old_state);
		out();
	*/
	system("pause");
	return 0;
}