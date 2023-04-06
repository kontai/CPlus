/*
*	MAIN
*	2021/12/05
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v01;
	for (int i = 0; i < 10; i++) {
		v01.push_back(1);
	}
	//cout << v01.capacity() << endl;
	//cout << v01.size();
	make_heap(v01.begin(), v01.end());
	system("pause");
	return EXIT_SUCCESS;
}