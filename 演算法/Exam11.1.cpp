#include<iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int mainExam11_1()
{
	vector<int>ivec;
	int in,search_num;

	cout << "Enter any number (CTRL-Z to end):";
	while (cin >> in) {
		ivec.push_back(in);
	}
		
	cin.clear();

	cout << "Enter any number want search(CTRL-Z to end):";
	while (cin >> search_num)
		cout << count(ivec.begin(), ivec.end(), search_num) << endl;

	system("pause");
	return 0;
}