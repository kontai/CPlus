#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include<iterator>
#include <fstream>
using namespace std;

int mainExam_11_18() {

	istream_iterator<int> in(cin), ieof;
	vector<int>ivec(in,ieof);
	ofstream eve("c:\\temp\\even.txt",ios::app);
	ofstream odd("c:\\temp\\odd.txt",ios::app);
	ostream_iterator<int> outEven(eve," ");
	ostream_iterator<int> outOdd(odd," ");
	vector<int>::iterator it = ivec.begin();
	while (it!=ivec.end()) {
		if (*it % 2) 
			outOdd =*it++;
		else
			outEven = *it++;
}


	system("pause");
	return 0;
}
