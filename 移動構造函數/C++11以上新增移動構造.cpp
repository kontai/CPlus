/*************************
[10/7/2018 17:35
C++11以上新增移動構造.cpp
*************************/

#include<iostream>

using namespace std;

class A {
public:
	A(int x = 5) :p(new int(x)) { cout << "calling constructor" << endl; }

	A(const A& a) :p(new int(*a.p)) { cout << "calling &" << endl; }

	//// &&是右值引用(將形參移動給右值)
	//A(A& a) :p(a.p) {
	//	cout << "a.p=" << a.p << endl;
	//	cout << "p=" << p << endl;
	//	a.p = nullptr;
	//	cout << "將原本指針設為空指針後..." << endl;
	//	cout << "a.p=" << a.p << endl;
	//	cout << "p=" << p << endl;
	//	cout << "calling &&" << endl;
	//}

	int get();

	~A() {
		delete p;
		cout << "Deleting" << endl;
	}

private:
	int *p;
};

A set() {
	A ptr;
	return ptr;
}

int A::get() {
	return *p;
}

int main() {
	cout<<set().get()<<endl;

	system("pause");
	return 0;
}