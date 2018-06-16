/*************************
[9/6/2018 15:48
st.cpp
*************************/

#include<iostream>
#include<cctype>
#include<string>
#include<filesystem>

using namespace std;
class Boo {
public:
	Boo(int a, int b, string ss) : va1(a), ccnt(b), ckind(ss), anl_pair(ss, a) {
}
	Boo(const string &str) :ckind(str) {}
	friend int back_animal(const string, int,Boo &);
private:
	int va1;
	int ccnt;
	string ckind;
	pair<string, int>anl_pair;
};



int back_animal( const string kind, int cnt,Boo &i) {
	i.ccnt = cnt;
	char kind2[200]="";
	strcpy(kind2, i.ckind.c_str());
	return i.anl_pair.second;
}


int mainSt(){
	char kk[] = "cc";
	string cc("cc") ;
	Boo a(22, 33, "ss");

	Boo b("this is string");

	

	system("pause");
	return 0;
}