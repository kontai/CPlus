#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

//istringstream:將輸入流綁定於string,只可讀入
//ostringstream:將輸入流綁定於string,只可寫出
//iostringstream:將輸入流綁定於string,可讀也可寫
//如同C語言中的sscanf , sprintf ----  格式化輸入輸出

int cnt(string);

int mainStringStream() {
	ostringstream out;
	int inA = 22, inB = 55;
	out << "Hello! " << inA;   //將字串賦予給ostringstream
	cout << out.str() << endl;
	string str = out.str();
	cout << str << endl;

	istringstream in;
	int change_int = 0;
	string st2int = "5566";
	in.str(st2int);
	in >> change_int;   //由字串轉換成整數
	cout << change_int << endl;

	cout << "請輸入編碼(任意字母+數字<CTRL+Z結束)=>";
	string find_int;
	int  total = 0;
	while (getline(cin, find_int)) {
		in.clear();
		in.str(find_int);
		string dump;
		while (in >> dump) {
			total += cnt(dump);
		}
	}
	cout << "字串內整數種和=" << total << endl;
	system("pause");
	return 0;
}
int cnt(string str) {
	string::iterator id = str.begin();
	int sum = 0, f_total = 0;
	while (id != str.end()) {
		if (*id >= '0' && *id <= '9')
			sum = *id - '0' + 10 * sum;
		else {
			f_total += sum;
			sum = 0;
		}
		id++;
	}

	f_total += sum;
	cout << f_total << endl;
	return f_total;
}