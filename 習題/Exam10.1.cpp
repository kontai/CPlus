#include<iostream>
#include<string>
#include<vector>

using namespace std;

int mainExam10_1() {
	pair<string, int>strwint;
	vector< pair<string, int> >vstrwint;
	string si;
	int in;
	while (cin >> si >> in) {
		strwint = make_pair(si, in);
		//		strwint = pair<string, int>(si, in);
		vstrwint.push_back(strwint);
	}
	/*
		while(cin>>strwint.first>>strwint.second)
		{
			vstrwint.push_back(strwint);
		}
	*/

	system("pause");
	return 0;
}