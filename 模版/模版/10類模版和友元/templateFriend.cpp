#include <iostream>
#include<string>

using namespace std;

template<typename nameType, typename ageType>
////類內實現友元函式
class MyClass {
	friend void display(MyClass<nameType, ageType>& m) {
		cout << "Name: " << m.name << ", Age: " << m.age << endl;
	}
public:
	MyClass(nameType n, ageType a) :name(n), age(a) {}

private:
	nameType name;
	ageType age;
};

template<typename nameType, typename ageType>
class MyClass2;
template<typename nameType, typename ageType>
void display2(MyClass2<nameType, ageType>& m);

template<typename nameType, typename ageType>
class MyClass2 {
	friend void display2<>(MyClass2<nameType, ageType>&);
public:
	MyClass2(nameType n, ageType a) :name(n), age(a) {}

private:
	nameType name;
	ageType age;
};

template<typename nameType, typename ageType>
void display2(MyClass2<nameType, ageType>& m)
{
	cout << "Name: " << m.name << ", Age: " << m.age << endl;
}

void test() {
	//MyClass mc("kontai", 20);
	//display(mc);

	MyClass2 mc2("MJ", 20);
	display2(mc2);
}
int main() {
	test();
	return 0;
}