#include<iostream>
#include<list>
#include <vector>
#include <iterator>

using namespace std;

int mainCopy()
{
	vector<int> ivec;
	for(vector<int>::size_type index=0;index!=10;index++)
		ivec.push_back(index);

	list<int> ilist;
	//copy() : 三個參數,分別是來源容器的起點,終點,目標容器
	//必須確保目的端與來源一樣大
	copy(ivec.begin(), ivec.end(), back_inserter(ilist));

	//印出list裡的值
	for (list<int>::iterator index = ilist.begin();index != ilist.end();index++)
		cout << *index << endl;

	//<<<<<更好的方法>>>>>
	list<int>better_one(ivec.begin(), ivec.end());
	for (list<int>::iterator index = better_one.begin();index != better_one.end();index++)
		cout << *index << endl;


	system("pause");
	return 0;
}