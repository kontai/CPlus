/*
2018/08/25 20:05:52
define_Derived.cpp
*/

#include<iostream>

using namespace std;

class Color
{
public:
	Color(int i=0):val(i){}
	int mm(int x, int y) { return x + y+val; }
	Color(Color &p){
		ptr = new Color(val);
		ptr->val = p.val;
	}
	
	~Color() {};
	
private:
	int val;
	Color *ptr;
};

class Hair {
	Hair() {}
	Hair(int x):size(x){}
	Hair(Hair& ptr) {
		delete[]cl;
		cl = new Color[size];

	}
	~Hair(){}

private:
	Color *cl;
	int size;
};

int main(){
	Color a(20);
	Color b = a;

//	int (Color::*ptr)(int, int);
//	ptr = &Color::mm;
//	cout << (a.*ptr)(2, 3);

	Color *ptr = &a;
	Color *p2 = new Color();
	cout << p2->mm(25.23) << endl;

	system("pause");
	return 0;
}