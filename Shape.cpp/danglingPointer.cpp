/*************************
[4/8/2018 9:18
danglingPointer.cpp
*************************/

#include<iostream>
using namespace std;

class Usage {
	friend class Dangling;
	int *ptr;
	size_t cnt;
	Usage(int *p) :ptr(p), cnt(1) {}
	~Usage() { delete ptr; }

};

class Dangling {
	int val;
	Usage *usp;
public:
	Dangling(int *p, int i) :usp(new Usage(p)), val(i) {}
	Dangling(const Dangling& cp) :usp(cp.usp), val(cp.val) { ++cp.usp->cnt;
	cout << "calling copy constructor..." << endl;
	}
	Dangling& operator=(const Dangling &);

	~Dangling() {
		if (--usp->cnt == 0)
			delete usp;
	}


};

Dangling& Dangling::operator=(const Dangling &ass) {
	++ass.usp->cnt;
	if (--usp->cnt == 0)
		delete usp->ptr;
	usp->ptr = ass.usp->ptr;
	val = ass.val;
	cout << "calling assignment constructor..." << endl;
	return *this;
}

int mainDan() {
	int *i = new int(23);
	Dangling a1(i,50);
	Dangling a2(a1);
	Dangling a3 = a1;
	system("pause");
	return 0;
}