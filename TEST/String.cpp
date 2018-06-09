/****************************************
[6/4/2017  10:10]
doT.cpp
****************************************/

#include<iostream>
#include<fstream>

using namespace std;
class String
{
public:
	String(const char* str)
	{
		str = str ? str : "";
		ptr = new char[strlen(str) + 1];
		strcpy(ptr, str);
	}

	String& operator=(const String& tmp){
		if (strlen(ptr) != strlen(tmp.ptr)) {
			delete[] ptr;
			ptr = new char[strlen(tmp.ptr) + 1];
		}
		strcpy(ptr, tmp.ptr);
		cout << "prepare...." << endl;
		return *this;
	}

	
	~String()
	{
		delete[] ptr;
	}
	void print()
	{
		cout << ptr << endl;
	}
private:
	char *ptr;
};

int mainString(){

system("pause");
return 0;
}