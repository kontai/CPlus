/****************************************
[5/18/2017  20:24]
解構函數.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class NoName
{
public:
	NoName() : sptr(new string), i(0), d(0)
	{
		cout << "構造函式被調用了.." << endl;
	}

	NoName(const NoName&);
	NoName& operator=(const NoName&);

 //當有成員式指針類型,就必須使用解構函數,反之,則可使用編譯器自動提供的合成函數即可
	~NoName();

	private:
	string* sptr;
	int i;
	double d;
};

NoName::NoName(const NoName& other)
{
	sptr = new string;
	*sptr = *(other.sptr);
	i = other.i;
	d = other.d;
}

NoName& NoName::operator=(const NoName& rhs)
{
	sptr = new string;
	*sptr = *(rhs.sptr);
	i = rhs.i;
	d = rhs.d;
	return *this;
}

NoName::~NoName()
{
	delete sptr;
	cout << "解構函式被調用.." << endl;
}

int maindele()
{
	NoName a;
	NoName* p = new NoName;
	delete p; //調用解構函數

	system("pause");
	return 0;
}
