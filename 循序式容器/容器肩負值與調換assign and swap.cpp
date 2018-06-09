#include<iostream>
#include<string>
#include<vector>

using namespace std;

int mainAssign_Swap() {
	vector<string>lstr, lstr2, lstr3 = { "peace","world","rule","road" };

	vector<string>::size_type index = 0;
	string str, str2;
	cin.clear();
	while (getline(cin, str), !cin.eof()) {
		lstr.push_back(str);
		cin.clear();
		if (getline(cin, str2), !cin.eof());
		lstr2.push_back(str2);
		cin.clear();
		vector<string>::reverse_iterator test_swap = lstr.rbegin();  //最後一個元素
		vector<string>::reverse_iterator test_swap2 = lstr2.rbegin();

		//lstr = lstr2;		//清除lstr,將lstr2複製到lstr(容器大小也會變成與lstr2相同)
		//lstr.assign(lstr3.begin(), lstr3.end());  //將另一個容器區間,複製給左邊容器(不能呼叫自身容器區間,賦值時,本身iterator會被刪除)
		//lstr.assign(3, "aa");  //將3個字串"aa"復職給容器(容器尺寸也變成3!)

		cout << "before swap:" << endl;
		cout << lstr.at(index) << '\t' << lstr2.at(index) << endl;

		lstr.swap(lstr2);
		//置換兩容器所有元素,速度比assign快(置換條件:兩容器型別必須相同)

		cout << " after swap:" << endl;
		cout << lstr.at(index) << '\t' << lstr2.at(index) << endl;
		cout << " after swap iterator:" << endl;
		cout << *test_swap << '\t' << *test_swap2 << endl;
		//swap後,本身iterotor也不會失效!(也就是指著同樣元素)
		index++;
	}

	system("pause");
	return 0;
}