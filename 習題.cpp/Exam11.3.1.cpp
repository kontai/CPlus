#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

int mainExam11_3_1() {
	list<int> ilst, ilstf, ilstb, ilstt;
	for (int i= 0;i != 20;i++) 
	{ ilst.push_back(i);
		
	}

		
	replace_copy(ilst.begin(), ilst.end(), back_inserter(ilstf), 2, 0);
	for (list<int>::iterator i = ilstf.begin();i != ilstf.end();i++)
		cout << *i;
		cout <<'\n' ;
		replace_copy(ilst.begin(), ilst.end(), front_inserter(ilstb), 2, 0);
	for (list<int>::iterator i = ilstb.begin();i != ilstb.end();i++)
		cout << *i;
		cout <<'\n' ;
	replace_copy(ilst.begin(), ilst.end(), inserter(ilstt,ilstt.begin()), 2, 0);
	for (list<int>::iterator i = ilstt.begin();i != ilstt.end();i++)
		cout << *i;
		cout <<'\n' ;
		list<int>ils;
		unique_copy(ilstt.begin(), ilstt.end(), back_inserter(ils));
	for (list<int>::iterator i = ils.begin();i != ils.end();i++)
		cout << *i;
		cout <<'\n' ;
	system("pause");
	return 0;
}
