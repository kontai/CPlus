/*************************
[16/6/2018 17:49
combin_structor.cpp
*************************/

#include<iostream>

using namespace std;

class PoinT {
public:
	PoinT() {}
	PoinT(int x, int  y) :x(x), y(y) { cout << "initial constructor" << endl; }
	PoinT(const PoinT&);
	PoinT(PoinT, PoinT);
	int getX();
	int getY();

	~PoinT() {
		cout << "destroy constructor...of PoinT" << endl;
	}


private:
	int x, y;
};

class LinE {
public:
	LinE();
	LinE(PoinT &, PoinT &);
	LinE(LinE&);
	~LinE() {
		cout << "destroy constructor...of LinE" << endl;
	}

private:
	int lx, ly;
	PoinT Px, Py;
	double len;
};

int PoinT::getX() {
	return  x;
}

int PoinT::getY() {
	return y;
}

PoinT::PoinT(const PoinT &p) {
	PoinT whatever;
	x = p.x;
	y = p.y;
	cout << "calling copy constructor of PoinT" << endl;
}
PoinT::PoinT(PoinT ix, PoinT iy){
	LinE(ix, iy);
	cout << ix.x + iy.x << "\n" << ix.y + iy.y << endl;
}

LinE::LinE() {
	cout << "Initialing constructor of LinE" << endl;
}


LinE::LinE(PoinT  &pa, PoinT  &pb):Px(pa),Py(pb) {
	double x = static_cast<double> (pa.getX() - Py.getX());
	double y = static_cast<double> (pa.getY() - Py.getY());
	len = sqrt(x*x + y * y);
	cout <<"length =  "<< len << endl;
}

LinE::LinE(LinE &l):Px(l.Px),Py(l.Py) {}


int mainCS() {
	PoinT a(1,1),b(5,4);
	LinE c(a,b);
	LinE d(c);
	


	system("pause");
	return 0;
}