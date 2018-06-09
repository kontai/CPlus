#include "stdafx.h"
#include<iostream>
#include<string>
#include <vector>

//vector 如同可動態分配大小的Array
//vector(n)vinit  : vinit內有一個已初始化物件的n份拷貝
//push_back 放入一個元素至vector尾端)
//可利用下標方式提取,探訪,修改元素值

using namespace std;

void mainVec() {
	string str("this is string!");
	vector<char>ch1(8);
	cout << ch1.size() << endl;
	for (string::size_type i = 0;i < str.size();i++) {
		ch1.push_back(str[i]);
	}
	ch1[0] = 'c';
	cout << ch1.size() << endl;
	cout << ch1[0] << endl;

	vector<string>vst;
	vst.push_back(str);
	vst.push_back("another string");
	cout << vst[0] << endl;
	cout << vst[1] << endl;

	vector<string>vsarr[3];
	vsarr[0].push_back(str);
	vsarr[1].push_back("another string");
	cout << vsarr[0][0] << endl;
	//	cout << vsarr[0][1] << endl;

	system("pause");
}