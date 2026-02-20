#include<iostream>
using namespace std;

template<typename nameType, typename ageType>
class MyClass {
public:
	MyClass() = default;
	MyClass(nameType name, ageType age) {
		this->name = name;
		this->age = age;
	}
	void display() {
		cout << "name: " << this->name << endl;
		cout << "age: " << this->age << endl;
	}
	~MyClass() {}

private:
	string name;
	int age;
};

// 類模版的默認類型
template<typename nameType, typename ageType = int>
class MyClass2 {
public:
	MyClass2() = default;
	MyClass2(nameType name, ageType age) {
		this->name = name;
		this->age = age;
	}
	void display() {
		cout << "name: " << this->name << endl;
		cout << "age: " << this->age << endl;
	}
	~MyClass2() {}

private:
	string name;
	int age;
};

void func() {
	MyClass<string, int> mc("tai", 20);
	mc.display();

	MyClass2<string> mc2("Joe", 18);
	mc2.display();
}

int main() {
	func();
	return 0;
}