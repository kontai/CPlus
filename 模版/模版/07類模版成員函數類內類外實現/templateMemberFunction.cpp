#include<iostream>
#include<string>
using namespace std;

template<typename nameType, typename ageType>
class MyClass {
public:
	MyClass(const nameType& name, ageType age);
	//{
	//	this->name = name;
	//	this->age = age;
	//}
	void Display() {
		cout << "Name: " << name << ", Age: " << age << endl;
	}

private:
	//類內實現
	nameType name;
	ageType age;
};

//類外實現
template<typename nameType, typename ageType>
MyClass<nameType, ageType> ::MyClass(const nameType& name,ageType age) {
	this->name = name;
	this->age = age;
	cout << "构造函數: " << endl;
}

void func() {
	MyClass<string, int> mc("kontai", 20);
	mc.Display();
}

int main() {
	func();
	return 0;
}