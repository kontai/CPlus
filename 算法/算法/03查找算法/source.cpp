#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

bool myFind(int v) {
	return v == 20;
}

struct myFindStr {
	bool operator()(int v)const {
		return v == 20;
	}
};

void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(50);
	v.push_back(30);

	//find
	vector<int>::iterator it = find(v.begin(), v.end(), 20);
	if (it != v.end()) {
		cout << "已找到: " << *it << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	//find_if	函數
	vector<int>::iterator it2 = find_if(v.begin(), v.end(), myFind);
	if (it2 != v.end()) {
		cout << "已找到: " << *it2 << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	//find_if 對象
	vector<int>::iterator it3 = find_if(v.begin(), v.end(), myFindStr());
	if (it3 != v.end()) {
		cout << "已找到: " << *it3 << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	//find_if lambda
	int find_value = 20;
	vector<int>::iterator it4 = find_if(v.begin(), v.end(), [find_value](int v) {return v == find_value; });
	if (it4 != v.end()) {
		cout << "已找到: " << *it4 << endl;
	}
	else {
		cout << "未找到" << endl;
	}
}

int main() {
	test01();
	return 0;
}