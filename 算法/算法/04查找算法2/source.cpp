#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

class MyClass {
public:
	MyClass(string k, int v) :key(move(k)), value(v) {}
	bool operator()(int a, int b)const {
		return a == b;
	}
	//bool operator==(const MyClass& a)const {
	//	return value == a.value;
	//}

	const	string& getKey() {
		return key;
	}
	int getValue() const {
		return value;
	}

private:
	string key;
	int value;
};

void test1() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(50);

	//adjacent_find 尋找相鄰對象
	vector<int>::iterator it = adjacent_find(v.begin(), v.end(), [](int a, int b) {return a == b; });
	if (it != v.end()) {
		cout << *it << endl;
	}
	else {
		cout << "not find" << endl;
	}
}
void test2() {
	vector<MyClass> v;
	v.emplace_back("aaa", 20);
	v.emplace_back("bbb", 30);
	v.emplace_back("ccc", 30);
	v.emplace_back("ddd", 40);
	v.emplace_back("eee", 50);
	v.emplace_back("fff", 50);
	//vector<MyClass>::iterator it = adjacent_find(v.begin(), v.end(),
	//	[](const MyClass& a, const MyClass& b) {return a == b; });
	vector<MyClass>::iterator it = adjacent_find(v.begin(), v.end(),
		[](const MyClass& a, const MyClass& b) {return a.getValue() == b.getValue(); });
	if (it != v.end()) {
		cout << it->getKey() << ", " << it->getValue() << endl;
	}
	else {
		cout << "not find" << endl;
	}
}

int main() {
	//test1();
	test2();
	return 0;
}