#include<iostream>
#include<cctype>

using namespace std;

class Calc {
public:
	Calc(int a = 0, int b = 0) :a(a), b(b),sum(0) {
	}

	Calc &add(int aa,int bb) {
		a = aa;
		b = bb;
		sum += a + b;

		cout << "a+b=" << sum << endl;
		return *this;
	}
	Calc &sub(int ab,int ba) {
		a = ab;
		b = ba;
		sum -= a - b;
		cout << "a-b=" << sum << endl;
		return *this;
	}

	Calc &sum1(){
		cout << "a=" << a << " b=" << b <<" sum="<<sum<< endl;
		return *this;
	}

	Calc& out_sum(ostream &out) {
		out << "Final sum"<<sum << endl;
		return *this;
	}
private:
	int a, b, sum;
	string str;
};

int maini(int argc, char argv[]) {
	Calc a1(2, 3);
	a1.add(2, 3).sub(33, 21).out_sum(cout);

	system("pause");
	return 0;
}