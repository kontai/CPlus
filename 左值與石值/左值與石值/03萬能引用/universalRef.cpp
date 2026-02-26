#include<iostream>

void Func(int& x) { std::cout << "左值引用" << std::endl; }

void Func(const int& x) { std::cout << "const左值引用" << std::endl; }

void Func(int&& x) { std::cout << "右值引用" << std::endl; }

void Func(const int&& x) { std::cout << "const右值引用" << std::endl; }

template<typename T>
void f(T&& t)  // 万能引用
{
	//Func(t);  // 根据参数t的类型去匹配合适的重载函数
	Func(std::forward<T>(t));  // 根据参数t的类型去匹配合适的重载函数

}
int main()
{
	int a = 4;  // 左值
	f(a);

	const int b = 8;  // const左值
	f(b);

	f(10); // 10是右值

	const int c = 13;
	f(std::move(c));  // const左值被move后变成const右值

	return 0;
}