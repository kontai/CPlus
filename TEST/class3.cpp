/****************************************
[5/4/2017  15:29]
class3.cpp
****************************************/

#include<iostream>
#include <string>
#include<cctype>

using namespace std;

class Temp
{
	string cost;
	
public:
	explicit Temp(string &st):cost(st){ }
	Temp(){ }

	Temp& issame(string ss)
	{
		if (ss == cost)
			cout << "same" << endl;
		else
		{
			cout << "different" << endl;;
			cost = ss;
		}
		return *this;
	}
	Temp& issame(istream &is)
	{
		string istr;
		is >> istr;
			if (istr == cost)
			cout << "same" << endl;
		else
		{
			cout << "different" << endl;;
			cost = istr;
		}
		return *this;
	}
};

int mainExplicitAAA(){
	string ss = "abc";
	string isexplicit = "diff";
	Temp Css(ss);
	Css.issame("bb");
	Css.issame(isexplicit);
	Css.issame(cin);


system("pause");
return 0;
}