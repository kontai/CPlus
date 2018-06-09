#include <iostream>
#include<numeric>
#include <vector>
#include <iterator>

using namespace std;

int mainAccumulate() {
	vector<int>ivec;
	cout << "Enter number (CTRL+Z  to end):" << endl;
	int anynum;
	while (cin >> anynum)
		ivec.push_back(anynum);
	//accumulate(t1,t2,n)   :計算元素總和;t1元素起始,t2元素末尾,n初始值; n+t[x]+t[x+1]+.....+t[x+y]
	cout << accumulate(ivec.begin(), ivec.end(), 5);

	system("pause");
	return 0;
}