#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

ifstream& open_file(ifstream& in, const string& file) {
	in.close();
	in.clear();
	in.open(file);
	return in;
}

int main字符轉換(int argc, char **argv) {
	map<string, string> trans_map;
	if (argc < 3)
		cerr << "not enough word?" << endl;

	ifstream input;	//創建輸入流,綁定給"字典檔"
	if (!open_file(input, argv[1]))
		cerr << "can't open file!" << endl;

	string key, value;		//將檔案轉入map
	while (input >> key >> value)
		trans_map.insert(make_pair(key, value));

	ifstream read_file;  //創建輸入流,綁定給要轉換的檔案
	if (!open_file(read_file, argv[2]))
		cerr << "cant open file!" << endl;

	string line;
	while (getline(read_file, line)) {
		istringstream istr(line);
		string word;
		bool firstword = true;  //控制是否列印空格
		while (istr >> word) {
			map<string, string>::iterator im = trans_map.find(word);
			if (im != trans_map.end())  //如果單字出現在字典
				word = im->second;	///替換單字
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << word;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}