#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/02/02
*AuTHOR:kontai
*
*/

class SingletonPtr {
private:
	SingletonPtr() {}	//構造函數私有化,防止外部實例化
	static	SingletonPtr* sptr;
public:
	static SingletonPtr* getInstance() {
		return sptr;
	}
};

SingletonPtr* SingletonPtr::sptr = new SingletonPtr();	//類外初始化靜態成員變量

void funcPtr() {
	SingletonPtr* p1 = SingletonPtr::getInstance();
	SingletonPtr* p2 = SingletonPtr::getInstance();

	//比較兩個指針是否指向同一個實例
	cout << "p1 address: " << p1 << endl;
	cout << "p2 address: " << p2 << endl;
}

int main() {
	funcPtr();
	return EXIT_SUCCESS;
}