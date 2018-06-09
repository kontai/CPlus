#include<iostream>
#include <vector>

using namespace  std;

//c++ Primer 4/e p.330
//(大小)size() : 元素數量
//(容量)capacity()  : 查詢系統為容器實際配置大小(為實現快速配置,系統會預留備用空間),其值 >= size()
//reserve() : 指定capacity大小,設定值須比原始值大才有作用,無法縮減

int mainCapacity_reserve() {
	vector<int>	ivec;
	cout << "未初始化 vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;
	vector<int>::size_type i = 0;
	while (i != 24)
		ivec.push_back(i++);
	cout << "賦值後 vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << "耗盡capacity預留空間   vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	//當size=capacity時,如再增添元素,就會重新配置儲存空機
	ivec.push_back(0);
	cout << "試著再push一元素  	vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	ivec.reserve(60);
	cout << "reserve 10個元素  	vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	system("pause");
	return 0;
}