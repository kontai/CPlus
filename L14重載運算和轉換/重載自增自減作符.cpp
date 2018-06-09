/****************************************
[5/30/2017  09:29]
重載成員訪問操作符.cpp
****************************************/

#include<iostream>

//當class含有"智能指針",才需要重載成員訪問操作符

using namespace std;

class AString
{
public:
	AString():ptr(""){ }
	AString(char const *);
	AString(AString const&);
	~AString();

	AString& operator++();  //前加加
	AString const operator++(int);  //後加加
	AString& operator--();  //前減減
	AString const operator--(int);  //後減減

	void print()
	{
		cout << ptr << endl;
	}
private:
	char *ptr;
};

AString::AString(char const *charptr)
{
	charptr = charptr ? charptr : "";
	ptr = new char[strlen(charptr) + 1];
	strcpy(ptr, charptr);
}

AString::AString(AString const& charptr)
{
	ptr = new char[strlen(charptr.ptr) + 1];
	strcpy(ptr, charptr.ptr);
}

AString::~AString()
{
	cout << "delete ponter" << endl;
	delete[] ptr;
}
	AString& AString::operator++(){
		for (size_t i=0;i<strlen(ptr);i++)
		{
			++ptr[i];
		}
		return *this;
}

	AString const AString::operator++(int){
		AString copy(*this);
		++(*this); //調用前加加
		return copy;
	}

AString& AString::operator--(){
	for (size_t i = 0;i<strlen(ptr);i++) {
		--ptr[i];
	}
	return *this;
}

AString const AString::operator--(int){
	AString copy(*this);
	--(*this);  //調用前減減
	return copy;
}

int mainPP_D(){
	AString ss1("abslouly");
	AString ss2="n/a";
	ss2.print();
	ss2++;
	ss2.print();
	ss2--;
	ss2.print();

system("pause");
return 0;
}