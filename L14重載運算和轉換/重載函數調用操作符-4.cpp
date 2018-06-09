/****************************************
[6/3/2017  14:52]
重載函數調用操作符-4.cpp
****************************************/

#include<iostream>
#include<set>
#include<string>
#include<algorithm>
//搜尋字串(不分大小寫)
using namespace std;

class IsNoCase
{
public:
	bool operator()(const string& a,const string& b)const{
		string upA,upB;
		upA.resize(a.size());
		upB.resize(b.size());
		transform(a.begin(), a.end(),upA.begin(),toupper);
		transform(b.begin(), b.end(),upB.begin(), toupper);
		return (upA<upB);
	}
};

int main_find(){
	set<string ,IsNoCase> str;
	str.insert("Jim");
	str.insert("tai");
	str.insert("lee");
	str.insert("chen");
	set<string>::iterator index = str.find("jim");
	if (index != str.end())
		cout << "find:"  <<  *index << endl;
	else 
		cout << "can't find!" << endl;
	



system("pause");
return 0;
}