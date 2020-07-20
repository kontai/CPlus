#include<iostream>
#include<fstream>
#include<string>
#include <vector>

using namespace std;
void process(string st) {
	cout << st;
}

int mainExam8_6() {
	string file("c:\\temp\\1.txt"), st;
	vector<string>vstr;

	ifstream in;
	in.open(file.c_str());

	if (!in) {
		cerr << "unable open file!" << endl;
		return -1;
	}

	while (in >> st) {
		vstr.push_back(st);
	}

	vector<string>::iterator it = vstr.begin();
	while (it != vstr.end()) {
		cout << *it << endl;
		it++;
	}

	system("pause");
	return 0;
}