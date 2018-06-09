#include<iostream>
#include<fstream>
#include<sstream>
#include <string>

using namespace std;

int main檔案輸入與輸出() {
	ifstream input;
	input.open("c:\\temp\\1.txt");
	if (!input) {
		cerr << "file not exist" << endl;
	}
	string strA, strB;
	while (input >> strA >> strB)
		;
	input.close();

	ofstream output;
	string file_path = "c:\\temp\\2.txt";
	output.open(file_path, ios::app);
	if (!output)
		cerr << "open file fail!";
	output << "nothing is impossible," << "otherwise you do nothong\n"
		<< "1.\n" << "2.\n";
	system("pause");
	return 0;
}