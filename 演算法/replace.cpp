/*******************
2017/03/2320
replace.cpp
*******************/
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>

using namespace std;

int main234(){
	vector<int>vec = { 0,1,2,3,4,5 };
	list<int>lst={11,22,33,44,55};
	replace(vec.begin(), vec.end(), 2, 33);
	vector<int>new_vec(6,0);
	cout << new_vec.size() << '\t' << new_vec.capacity() << endl;
	new_vec.push_back(1);
	cout << new_vec.size() << '\t' << new_vec.capacity() << endl;
	new_vec.reserve(20);
	cout << new_vec.size() << '\t' << new_vec.capacity() << endl;

system("pause");
return 0;
}

int main567()
{
	list<int>trans_list(100);
	vector<int>vec(100) ;
	reverse_copy(trans_list.begin(), trans_list.end(), vec.begin());
	




	system("pause");
	return 0;
}