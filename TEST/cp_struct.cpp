/*************************
[16/6/2018 7:37
cp_struct.cpp
½Æ»sºc³y¨ç¼Æ
*************************/

#include<iostream>
#include<string>

using namespace std;

class A {

public:
	A() :va1(0), va2(0), str("") { cout << "default construct...." << endl; }
	A(int a,int b,const string &s):va1(a),va2(b),str(s){
		cout << "initialing construct...." << endl;
	}
	~A() { cout << "delete class...." << endl; }

	void funC(const A &rh) {
		va1 = rh.va1;
		va2 = rh.va2;
		str = rh.str;
	}

	int get() {
		return va1;
	}

private:
	int va1, va2;
	string str;
};

	void funP( A rh) {
		cout << rh.get()<< endl;
	}


	A funC2() {
		A tmp;
		return tmp;
	}


int mainCPC(){
	A a1;
	A b1(2, 5, "testing");
	b1.funC(a1);
	a1=funC2();
	funP(b1);



	

	system("pause");
	return 0;
}