#include<iostream>
#include<string>

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

// 方式 I
void func1(MyClass<string, int>& m) {
	m.display();
	cout<<__func__<<endl;
	cout << endl;
}

//方式 II
template<typename nType,typename aType>
void func2(MyClass<nType, aType>& m) {
	m.display();
	cout<<__func__<<endl;
	cout << endl;
}

// 方式 III
template<typename T>
void func3(T& m) {
	m.display();
	cout<<__func__<<endl;
	cout << endl;
}

void test() {
	MyClass<string, int> mc("tai", 18);
	func1(mc);
	func2(mc);
	func3(mc);
}

int main() {
	test();
	return 0;
}