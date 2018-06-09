#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int mainExam435() {
	string str;
	vector<string>vs;
	while (cin >> str) {
		vs.push_back(str);
	}

	char **ps = new char*[vs.size()];

	int len = 0;

	for (vector<string>::iterator vlen = vs.begin();vlen != vs.end();vlen++) {
		char *p = new char[(*vlen).size() + 1];
		strcpy(p, (*vlen).c_str());
		ps[len] = p;
		cout << ps[len] << endl;
		len++;
	}
	for (size_t i = 0;i != len;i++) {
		delete ps[i];
	}
	delete ps;

	/*
	//array of int initialize vector//

	const size_t arr_size = 10;
	int arr[arr_size] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int>vec(arr,arr+10);
	cout << vec[9] << endl;
	*/
	/*
	//array of int initialize vector//
	vector<int>vin = { 0,1,2,3,4,5,6,7,8,9 };
	int *asp = new int[vin.size()+1]();
	int j = 0;
	for (vector<int>::iterator i = vin.begin();i != vin.end() ;i++,j++) {
	asp[j] = *i;
	cout << "ar[" << j << "]=" << asp[j] << endl;
	}
	delete[] asp;
	*/

	system("pause");

	return 0;
}