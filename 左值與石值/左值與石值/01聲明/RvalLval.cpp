#include <iostream>
using namespace std;

void func() {
	int l = 10;
	int& rl = l;	//左值引用
	//int& lc = 10;	//错误，不能引用常量
	const int& lc2 = 10;	//正确，可以引用常量,但无法修改(const int tmp=10; int& rc2=tmp;)

	int* p = &l;
	int*& pr = p;	//指针的引用
}
int f() {}
void func2() {
	int i = 10;
	//int&& ri = i;	 //错误，不能直接引用左值
	int&& ri = std::move(i);	//正确，使用std::move将左值转换为右值引用
	int&& r = 10;
	r = 20;	//引用的变量是可以修改的
	&r;	//引用的变量是可以取地址的

	int a = 5, b = 6;
	int&& re = a + b;	//正确，可以引用表达式
	re = 9;	//引用的变量是可以修改的
	&re;	//引用的变量是可以取地址的
	int&& re2 = f();	//正确，可以引用函数返回值

	int* p = &a;
	int*&& pr = std::move(p);	//正确，可以引用指针的右值引用
}
int main()
{
	return 0;
}