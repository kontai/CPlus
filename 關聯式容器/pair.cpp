#include<iostream>
#include<string>

using namespace std;

/*
 pairs 類型提供的操作

 pair<T1, T2> 創建一個空的 pair 物件，它的兩個元素分別是 T1 和 T2 p1; 	類型，採用值初始化（第 3.3.1 節）

 pair<T1, T2> p1(v1, v2); 創建一個 pair 物件，它的兩個元素分別是 T1 和 T2 ，其中 first 成員初始化為 v1，而 second 成員初始化為 v2

make_pair(v1, v2) 以 v1 和 v2 值創建一個新 pair 物件，其元素類型分別是 v1 和 v2 的類型

 p1 < p2 	兩個 pair 物件之間的小於運算，其定義遵循字典次序：如果 p1.first < p2.first 或者 !(p2.first < p1.first) &&  p1.second < p2.second，則返回 true

 p1 == p2 	如果兩個 pair 物件的 first 和 second 成員依次相等，則這兩個對象相等。該運算使用其元素的 == 操作符

 p.first 	返回 p 中名為 first 的（公有）資料成員
 p.second 	返回 p 的名為 second 的（公有）資料成員

 */

typedef pair<string, string> Author;

int mainPair() {
	//Author pstr("honor", "return"); 使用typedef簡化初始化
	pair<string, string> pstr;
	string first_s, second_s;
	while (cin >> first_s >> second_s) {
		pstr = make_pair(first_s, second_s);  //利用make_pair初始化,比起下式,更明確表明pair行為
	//	pstr = pair<string, string>(first_s, second_s);	作用如上
	}
	//while(cin>>pstr.first>>pstr.second)  //pair成員變數是public,所以可直接初始化成員

	system("pause");
	return 0;
}