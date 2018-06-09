/****************************************
[5/6/2017  10:52]
class友元friend.cpp
****************************************/

//友元允許非成員函式存取class private物件
#include<iostream>


using namespace std;

class CaseA
{
public:
	CaseA():a(0),b(0){ }
	CaseA(int x,int y):a(x),b(y){ }

	//宣告友元含式.讓非class成員函式也能夠存取private物件!
	friend int Add(CaseA&);

	 friend istream& Read(istream &, CaseA &);
private:
	int a, b;
	
};

int Add(CaseA& t)
{
	return t.a + t.b;  //在非成員函式non-member存取成員函式物件
}


istream& Read(istream &keyin,CaseA& Cain)
{
	cout << "give some integer=>";
	keyin >> Cain.a;
	keyin >> Cain.b;
	return keyin;
}


int mainFriend(){
	CaseA ta(33,66);
	cout << Add(ta) << endl;
	CaseA tb;

	int a;
	Read(cin, tb)>>a;
	cout << a;
	



system("pause");
return 0;
}