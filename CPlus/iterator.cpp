#include<iostream>
#include<vector>
#include<string>

using namespace std;

//iterator 如同C語言的指標
//begin()傳回容器第一元素指標,end()傳回容器末尾的下一個指標

int  mainIterator() {
	vector<string>vs;
	string ch = "impressive";
	string ch2 = "impossible";
	vs.push_back(ch);
	vs.push_back(ch2);

	cout << vs[0] << '\n' << vs[1] << endl;

	vector<string>::iterator ivst = vs.begin();
	vector<string>::size_type len = vs.size();
	while (len--) {
		*ivst = "boring";
		ivst++;
	}

	cout << vs[0] << '\n' << vs[1] << endl;
	string *st = &ch;
	*st = "changed";
	cout << *st << '\n' << ch << endl;
	system("pause");

	return 0;
}