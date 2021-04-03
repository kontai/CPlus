/*
*	02
*	2021/03/27
*
*/

#if 0

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2>class Clazz {
public:
	Clazz(T1 name, T2 age) {
		this->name = name;
		this->age = age;
	}
	Clazz &showType() {
		string str = typeid(name).name();
		cout << str.length() << endl;
		cout << typeid(name).name() << endl;
		cout << typeid(age).name() << endl;
		cout << typeid(this).name() << endl;
		return *this;
	}

	void showInfo() {
		cout << name << endl;
		cout << age << endl;
	}

private:
	T1 name;
	T2 age;
};

//��ƼҪO�ե�I
void call01(Clazz<string, int> &c1) {
	cout << "��ƼҪO�եμҦ�I" << endl;
}

//��ƼҪO�ե�II
template<class T1, class T2>
void call02(Clazz<T1, T2> &c1) {
	cout << "��ƼҪO�եμҦ�II" << endl;
}

//��ƼҪO�ե�III
template<class T>
void call03(T &c1) {
	cout << "��ƼҪO�եμҦ�III" << endl;
	c1.showInfo();

}

int main() {
	int a = 3;
	//fun1(a);

	Clazz<string, int>c1("kontai", 12);
	//c1.showType().showInfo();
	//call01(c1);
	//call02(c1);
	call03(c1);
	c1.showType();


	system("pause");
	return EXIT_SUCCESS;
}

#endif
