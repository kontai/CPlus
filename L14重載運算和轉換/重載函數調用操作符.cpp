/****************************************
[5/31/2017  21:28]
函數調用操作符.cpp
****************************************/

#include<iostream>
#include<vector>
#include<list>
#include <algorithm>

using namespace std;
struct absInt
{
	int operator()(int val){
		return val < 0 ? -val : val;
	}
};

template<typename elementType>void FuncDisplay(const elementType& ele)
{
	cout << ele << ' ';
}

template<typename elementType>struct DisplayElement {
void operator()(const elementType& ele)const{
	cout << ele << ' ';
}
};

int mainReFunc(){
	int i = -20;
	absInt obj;
	unsigned int res = obj(i);
	cout << res << endl;

	vector<int>vec;
	for(vector<int>::size_type i=0;i<10;i++)
		vec.push_back(i);

	list<char>ls;
	for(char i='a';i<'k';i++)
		ls.push_back(i);

	for_each(vec.begin(), vec.end(), DisplayElement<int>());
	putchar('\n');
	for_each(ls.begin(), ls.end(), DisplayElement<char>());

system("pause");
return 0;
}