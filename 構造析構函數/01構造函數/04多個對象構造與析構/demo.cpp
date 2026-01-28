#include<iostream>
#include<string>

using namespace std;
struct BMW {
	BMW() {
		cout << "BMW() called" << endl;
	}
	BMW(int a) {}
	~BMW()
	{
		cout << "~BMW() called" << endl;
	}
};

struct Buick
{
	Buick() {
		cout << "Buick() called" << endl;
	}
	~Buick()
	{
		cout << "~Buick() called" << endl;
	}
};

struct Maker {
public:
	Maker() {
		cout << "Maker() called" << endl;
	}
	Maker(int a) {}
	~Maker() {
		cout << "~Maker() called" << endl;
	}
private:
	BMW bmw;
	Buick buick;
};

void func() {
	Maker mk;
}

int main() {
	func();
}