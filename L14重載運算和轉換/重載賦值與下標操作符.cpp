/****************************************
[5/25/2017  21:26]
重載賦值操作符.cpp
****************************************/

#include<iostream>

using namespace std;
class String
{
public:
	String(const char*);
	
	String& operator=(const String&);
	String& operator=(const char*);
	String& operator=(char*);

	char& operator[](size_t) throw(String);

	void print()const
	{
		cout << pstring << endl;
	}

	
	
private:
	char *pstring;
	static String errorMessage;
};

String String::errorMessage("Subscript out of range");

String::String(const char* ch)
{
	ch = ch ? ch : "";
	pstring = new char[strlen(ch) + 1];
	strcpy(pstring, ch);
}

String& String::operator=(const String& ass){
	if(strlen(pstring)!=(strlen(ass.pstring)))
	{
		char *CpStr = new char[strlen(ass.pstring) + 1];
		delete[] pstring;  //刪除pstring所指位址
		pstring = CpStr;	//將pstring指向新建立的動態空間
	}
	strcpy(pstring, ass.pstring);

		return *this;
}

char& String::operator[](size_t index) throw(String)
{
		if (index >= strlen(pstring))
			throw errorMessage;

		return pstring[index];
}

int mainAss_Subscr(){
	String str("hotdog");
	String str2("pizza");
	str2.print();
	str2 = str;
	str2.print();
	cout << str2[2] << endl;

	String const str3("tea");
	str3.print();



system("pause");
return 0;
}