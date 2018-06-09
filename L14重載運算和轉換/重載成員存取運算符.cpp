/****************************************
[5/30/2017  15:24]
重載成員存取運算符.cpp
****************************************/

#include<iostream>

using namespace std;

class Screen {
public:
	Screen(Screen* inistr) : sp(new Screen(inistr)) {
	}

private:
	Screen* sp;
	char* chptr;
};

class Scrptr {
	friend class Screenptr;
	size_t use;
	Screen* sp;

	Scrptr(Screen* p) : sp(p), use(1) {
	}

	~Scrptr() {
		delete sp;
	}
};

class Screenptr {
public:
	friend class ScrArrow;
	Screenptr(Screen* p) : ptr(new Scrptr(p)) {
	}

	Screenptr(const Screenptr& orig) : ptr(orig.ptr) {
		++ptr->use;
	}

	Screenptr& operator=(const Screen& eq) {
		
		return *this;
	}

	~Screenptr() {
		if (--ptr->use == 0)
			delete ptr;
	}

	Screen& operator*() {
		return *ptr->sp;
	}

	Screen* operator->() {
		return ptr->sp;
	}

	const Screen& operator*() const {
		return *ptr->sp;
	}

	const Screen* operator->() const {
		return ptr->sp;
	}

private:
	Scrptr* ptr;
};

class ScrArrow {
	ScrArrow(const Screenptr& sp) :pts(new Screenptr(sp)) {
	}

private:
	Screenptr *pts;
};

int mainArrow_pointer() {

	system("pause");
	return 0;
}