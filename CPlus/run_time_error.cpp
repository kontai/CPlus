#include<iostream>
#include <string>
#include <bitset>

using namespace std;

int mainError() {
	bitset<100> bit;

	try {
		for (size_t i = 0;i != bit.size();i++)
			bit[i] = i;
		bit.to_ulong();	//產生溢位異常
	}
	catch (runtime_error err) {	//處裡異常
		cout << err.what() << endl;
	}
	system("pause");
	return 0;
}