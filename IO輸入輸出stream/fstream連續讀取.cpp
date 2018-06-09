#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void process(string &s) {
}
int mainFstreamR() {
	vector<string>file;		//vector內含多個程式檔名
	ifstream input;
	vector<string>::iterator it = file.begin();
	while (it != file.end()) {
		input.open(it->c_str());
		if (!input) {
			cerr << "unable open file!" << endl;
			break;
		}

		string s;
		while (cin >> s)
			process(s);

		input.close();	//因ifstream於外部宣告,所以在進入下一個迴圈前要將input解除綁定
		input.clear();  //須將iostate狀態清除 在讀取檔案過程,只要遇到end-of-file或其他錯誤
								//未做clear()動作,任何對input輸入的動作都會失敗
		it++;
	}

	system("pause");
	return 0;
}