#include <iostream>
#include<vector>
#include<map>
#include<fstream>
#include<set>		//含入頭檔

using namespace std;

//set : 與map有共同操作,insert , count , find , erase等;
//與map不同是(1)只存在key,並無value (2)無法使用下標
//當只需要查找是否存在某元素時很有用
//key必須是獨一無二,如遇到重複,則會忽略
int mainSet() {
	vector<int>ivec;
	for (vector<int>::size_type i = 0;i != 10;i++) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	set<int> iset(ivec.begin(), ivec.end());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;  //重複的key被省略掉

	iset.find(1);		//返回一個iterator指向key為1的元素
	iset.count(1);		//返回1

	set<int>::iterator set_it = iset.find(1);
	//*set_it = 11;	key是常數,無法更改



	system("pause");
	return 0;
}

/*
	void restrict_wc(ifstream& remove_file,map<string,int>& word_count)
	{
		set<string>exclude_word;
		string remove_word;
		while(remove_file>>remove_word)
			exclude_word.insert(remove_word);
		string key_in;
		while (cin >> key_in)
			if (!exclude_word.count(key_in))
				++word_count[key_in];

	}
*/
