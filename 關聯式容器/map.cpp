#include<iostream>
#include<string>
#include<map>

using namespace std;

/*
 * map又被稱為關聯式容器
 * map的value是經由key索引,不像array是由在array中的位置取得
 * 定義map必須指名key,value型別
 * 利用key(索引)關聯、解釋value(元素值),就如字典般
 */
int mainMap_Multimap() {
	map<int, string>a;
	//以下為map定義方式
															// key值 , value值
	a.insert(map<int, string>::value_type(1, "one"));
	a.insert(make_pair(2, "two"));
	a.insert(pair<int, string>(3, "three"));
	a.insert(pair<int, string>(3, "duplicate value three"));  //map 裡,key只能關聯一個value
	a[4] = "four";
	//與array or vector不同 , map會先搜尋key value"4",如找不到,則建立,並初始化為value
	//利用此特性,輸入單字並統計重複次數....
	map<string, int>word_count;
	string word;
	cout << "請輸入任意單字=>" << endl;
	while (cin >> word) {
		++word_count[word]; //如無此key,建立;如找到此key,value+1;
		cout << "word count=>   " << word << "   x" << word_count[word] << endl;
	}

	cout << "最簡單map查找:\t" << a[2] << endl;
//	cout << "key=2  共有" << word_count.count(2) << "個" << endl;   //count():返回元素個數

	cout << "map大小:" << a.size() << "\n\n" << "map內容為:" << endl;
	map<int, string>::iterator i = a.begin();
	while (i != a.end()) {
		cout << i->first << "," << i->second << endl;
		i++;
	}

	multimap<int, string>ma;
	ma.insert(multimap<int, string>::value_type(1, "one"));
	ma.insert(make_pair(2, "two"));
	ma.insert(pair<int, string>(3, "three"));
	ma.insert(pair<int, string>(3, "duplicate value three")); //multimap 裡,key能關聯多個value
	ma.insert(pair<int, string>(3, "duplicate more value three")); //multimap 裡,key能關聯多個value
	//ma[4] = "four";		 multimap 不支援使用下標方式!
	cout << "multimap大小:" << ma.size() << "\n\n" << "mutlimap內容為:" << endl;
	multimap<int, string>::iterator mi = ma.begin();

	while (mi != ma.end()) {
		cout << mi->first << "," << mi->second << endl;
		mi++;
	}

	cout << "內容為three的數量=" << ma.count(3) << endl;

	multimap<int, string>::const_iterator fi = ma.find(3);
	if (fi != ma.end()) {
		size_t n = ma.count(3);
		if (n > 1) {
			for (size_t i = 0;i != n;i++) {
				cout << "key= " << fi->first << "\tvalue[" << i << "]=" << fi->second << endl;
				++fi;
			}
		}
		//	cout << (ma.find(3))->first<<(ma.find(3))->second << endl;
	}
	else
		cout << "沒找到" << endl;
	//erase 1
	if (ma.erase(1) > 0)
		cout << "刪除1成功" << endl;
	else
		cout << "刪除失敗" << endl;

	//erase 2
	multimap<int, string>::iterator  map_erase = ma.find(2);
	if (map_erase != ma.end()) {
		ma.erase(2);
		cout << "刪除2成功" << endl;
	}
	else
		cout << "刪除失敗" << endl;

	//erase 3
	ma.erase(ma.lower_bound(3), ma.upper_bound(3));  //刪除範圍(key有一個以上value)

	system("pause");
	return 0;
}