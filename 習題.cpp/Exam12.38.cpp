/****************************************
[5/10/2017  20:56]
Exam12.38.cpp
****************************************/

#include<iostream>

using namespace std;

class Foo {
public:
	Foo(int num) :cnt(num) {
	}
	int rtnum() {
		return cnt;
	}

private:
	int cnt;
};

class Bar {
public:
	static Foo FooVal();
private:
	static int in1;
	static Foo bb;
	static int callsFooVal;
};

//初始化static數據成員
int Bar::in1 = 20;
Foo Bar::bb = 0;

//Foo Bar::FooVal() {
//	callsFooVal++;
//	return bb;
//}
//
int mainExam12_38() {
	system("pause");
	return 0;
}