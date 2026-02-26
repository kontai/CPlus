#include <iostream>
using namespace std;

void fun() {
	string s("11111111111111111");
	string s1("22222222222222222");
	s1 = s; // s是左值，所以调用拷贝赋值函数

	string s2("333333333333333333");
	s2 = std::move(s); // s被move后变为右值，所以调用移动赋值函数，s的资源会被转移用来赋给s2
	system("pause");
	// 要注意的是，move一般是不这样用的，因为s的资源被转走了
}
int main()
{
	fun();
	return 0;
}