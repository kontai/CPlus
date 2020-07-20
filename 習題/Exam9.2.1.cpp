#include<iostream>
#include<vector>
#include <string>
#include <list>

using namespace std;

/*
vector<int>::iterator find_int( vector<int>::iterator first,const vector<int>::iterator last,int num)
{
	while(first!=last)
	{
		if (*first == num)
			return first;
		first++;
	}
	return last;
}

int main9_13()
{
	vector<int>ivec;
	vector<int>::size_type index = 0;
	while(index!=10)
	{
		ivec.push_back(index * 2);
		index++;
	}

	vector<int>::iterator it=find(ivec.begin(), ivec.end(), 5);
	if (it != ivec.end())
		cout << *it << endl;
	else
		cout << "not found!";

	system("pause");
	return 0;
}
*/

/*
int main9_14()
{
	string str;
	vector<string>vstr;

	while(cout << "please input=>",getline(cin,str))
	{
		vstr.push_back(str);
	}

	vector<string>::iterator it = vstr.begin();
while(it!=vstr.end())
{
	cout << *it << endl;
	it++;
}
	system("pause");
	return 0;
}
*/

int main9_15() {
	string str;
	list<string>lstr;

	while (cout << "please input=>", getline(cin, str)) {
		lstr.push_back(str);
	}

	list<string>::iterator it = lstr.begin();
	while (it != lstr.end()) {
		cout << *it << endl;
		it++;
	}
	system("pause");
	return 0;
}