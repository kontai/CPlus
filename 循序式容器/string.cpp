#include<iostream>
#include<string>
#include<cctype>

using namespace std;

//substr : 子字串
//append : 附加至字串尾部
//replace : 先移除,然後插入字元(erase + insert) ,移除與插入的數目不須相同
int mainString() {
	string s("Hello,world!");
	cout << "s= " << s << endl;
	string s2 = s.substr(6, 5);   // substr(pos, n);   from pos to n
	cout << "s2= " << s2 << endl;
	string s3 = s.substr(6);   // substr(pos, n);   from pos to end;
	cout << "s3= " << s3 << endl;

	string s4 = s.append("\t\aanother word");
	cout << "s4= " << s4 << endl;

	string s5 = s4.replace(0, 12, "everything change");
	cout << "s5= " << s5 << endl;

	s4.erase();
	cout << "s4= " << s4 << endl;

	system("pause");
	return 0;
}