/*************************
[27/6/2018 23:45
指針數組cpp.cpp
*************************/

#include<iostream>
#include<limits.h>
#include<cassert>

using namespace std;

class A {
public:
	A() { cout << "calling default constructor" << endl; }
	A(int a, int b) :ca(a), cb(b) {
		cout << "initial constructor" << endl;
	}

	void add(int, int);
	void info();

	A(A& s) {
		ca = s.ca;
		cb = s.cb;
		cout << "initial A& constructor" << endl;
	}

	~A() { cout << "calling destructor" << endl; }
private:
	int ca, cb;
	//A *pa;
};

void A::add(int x, int y) {
	ca = x;
	cb = y;
	//	cout << pa << '\t' << &pa << '\t' << &pa[0] << endl;
}

void A::info() {
	cout << ca << ',' << cb << endl;
}

class AP {
public:
	AP(int size) :size(size) {
		pa = new A[size];
	}

	AP(const AP&);

	~AP() {
		cout << "Deleting..." << endl;
		delete[] pa;
	}

	A& ele(int cnt) {
		assert(cnt >= 0 && cnt < size);
		return pa[cnt];
	}

private:
	A * pa;
	int size;
};

//深複製,避免對象消除時,成為野指標
AP::AP(const AP& ap) {
	size = ap.size;
	pa = new A[size];
	for (int i = 0; i < size; i++)
		pa[i] = ap.pa[i];
}

int mainAPclass() {
	A a1;
	A b1(a1);
	AP ap1(3);
	ap1.ele(0).add(2, 3);
	ap1.ele(1).add(5, 10);

	AP ap2(ap1);

	cout << "ap2.ele(0)=";
	ap2.ele(0).info();
	cout << "ap2.ele(1)=";
	ap2.ele(1).info();
	putchar('\n');

	ap1.ele(0).add(6, 9);
	ap1.ele(1).add(12, 15);

	cout << "ap2.ele(0)=";
	ap2.ele(0).info();
	cout << "ap2.ele(1)=";
	ap2.ele(1).info();

	system("pause");
	return 0;
}