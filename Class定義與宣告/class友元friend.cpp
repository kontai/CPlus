/****************************************
[5/6/2017  10:52]
classねじfriend.cpp
****************************************/

//ねじす�\�DΘ���胼・s��class private��ン
#include<iostream>


using namespace std;

class CaseA
{
public:
	CaseA():a(0),b(0){ }
	CaseA(int x,int y):a(x),b(y){ }

	//�擢iねじ�tΑ.統�DclassΘ���胼，]�牋��s��private��ン!
	friend int Add(CaseA&);

	 friend istream& Read(istream &, CaseA &);
private:
	int a, b;
	
};

int Add(CaseA& t)
{
	return t.a + t.b;  //�b�DΘ���胼�non-member�s��Θ���胼！�ン
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