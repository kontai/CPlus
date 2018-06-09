#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int mainFstreamIO() {
	string ifile("c:\\temp\\1.txt");

	ifstream in;   //創建ifstream,為綁定檔案
	in.open("c:\\temp\\1.txt");	 //呼叫open()將ifstream物件綁定於指定檔案
	//以上兩式作用如同	ifstream in(ifile.c_str())
	//ifstream in(ifile.c_str()); //創建ifstream,並將他綁定於指定檔案上
	//檔案名稱須為C-String,建議用string轉化為c-string  string.c_str()

	ofstream out;
	out.open("c:\\temp\\1.txt");
	//	ofstream out(ifile.c_str());	//創建ofstream,並將他綁定於指定檔案上

	if (!in) {
		cerr << "unable to open file!" << endl;
		system("pause");
		return -1;
	}

	in.close();	//關閉in
	out.close();	//關閉out
	in.open("c:\\2.txt");		//更換檔案目標,要先關閉綁定

	system("pause");
	return 0;
}