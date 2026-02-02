#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/02/02
*AuTHOR:kontai
*
*/
class Singleton{
private:
	Singleton() {}	//構造函數私有化,防止外部實例化
public:
	static Singleton& getInstance() {
		static Singleton instance; //局部靜態變量,只會被初始化一次
		return instance;
	}

};

void func() {
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();
	if (&s1 == &s2) {
		cout << "s1 and s2 are the same instance." << endl;
	}
	else {
		cout << "s1 and s2 are different instances." << endl;
	}
}

int main() {
	func();

	return EXIT_SUCCESS;
}