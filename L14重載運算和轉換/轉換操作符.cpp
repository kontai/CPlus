/****************************************
[6/3/2017  17:13]
Âà´«¾Þ§@²Å.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;
class Dot 
{
public:
	Dot(string y,int b,double w):black(b),white(w),yellow(y){ }
	operator int() const{
		return  black;
	}
	operator double() const{
		return  white;
	}
	operator string() const{
		return  yellow;
	}
private:
	int black;
	double white;
	string yellow;
};

int mainTrans_operator(){
	int a;
	double a2;
	string a3;
	Dot b("abc", 2, 3.2);
	a = b;
	a2 = b;
	a3 = b;
	cout << a << endl;
	cout <<	a2 << endl;
	cout <<	a3 << endl;


system("pause");
return 0;
}