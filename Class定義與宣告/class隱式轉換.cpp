/****************************************
[5/4/2017  14:36]
class隱式轉換.cpp
****************************************/

#include<iostream>
#include <string>

using namespace std;

class Implicit {
public:
	explicit Implicit(const string &st=""):str(st) {}
	 //Implicit(const string &st=""):str(st) {}

	bool same_isbn(Implicit& ref) {
		return str == ref.str;
	}

private:
	string str;

};


int mainClassExplicit(){
	Implicit aa("abcd");
	Implicit bb=Implicit("abc");

	//當有設立建構式時,"def"會隱式轉換成Implicit("def");
	//Implicit cc = "def"; 
	//當建構式以explicit宣告,定義/調用class對象不能夠依靠隱式轉換,編譯會報錯
system("pause");
return 0;
}