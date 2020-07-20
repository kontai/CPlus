#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:

	MyString(const char * str)
	{
		//
	}

	explicit MyString(int a)
	{
		mSize = a;
	}

	char* mStr;
	int mSize;
};

void test01()
{
	
	MyString str = "abc";
	MyString str2(10);
	//MyString str3 = 10; //做什麼用圖？ str2字符串為 "10" 字符串的長度10 
	//隱式類型轉換  Mystring str3 = Mystring (10);
	// explicit關鍵字 ，防止隱式類型轉換

}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}