#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <vector>

using namespace std;
int mainE518() {
	string str;
	vector<string*>vs;
	while (cin >> str) {
		string *ps = new string;
		*ps = str;
		vs.push_back(ps);
	}
	vector<string*>::iterator iit = vs.begin(); //將變數宣告在外區域,以便釋放記憶體
	while (iit != vs.end()) {
		cout << **iit << ' ' << (*iit)->size() << endl;
		iit++;
	}

	iit = vs.begin();  //將指標移回開頭
	while (iit != vs.end()) {
		delete *iit;
		iit++;
	}

	system("pause");
	return 0;
}