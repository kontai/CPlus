#include<iostream>

using namespace std;

class A {
public :
	int a = 20;
};

class B :public A {
public :
	int a = 10;
};

class C :public A {
public:
	int a = 5;
};

void func() {
	B b;
	C c;
	cout << "b.a=" << b.a << endl;	// 10，B類的a遮蔽了A類的a
	cout << "c.a=" << c.a << endl;	// 5，C類的a遮蔽了A類的a

	// 如果需要訪問A類的a，可以使用作用域解析運算子
	cout << "b.A::a=" << b.A::a << endl;	// 20，訪問A類的a
	cout << "c.A::a=" << c.A::a << endl;	// 20，訪問A類的a
}

int main() {
	func();

	return 0;
}