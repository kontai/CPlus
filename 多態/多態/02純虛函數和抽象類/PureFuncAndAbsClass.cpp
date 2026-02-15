#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//純虛擬函式的類別稱為抽象類別,無法實例化,只能用來繼承
class Car {
public:
	virtual void show() = 0; //純虛擬函式,沒有實作,必須在子類別中覆寫
	virtual ~Car() {
		cout << "Car destructor" << endl;
	}
};

//繼承抽象類別,必須覆寫純虛擬函式,否則子類別也會成為抽象類別
class Toyota : public Car {
public:
	void show() {
		cout << "Toyota show" << endl;
	}
	~Toyota() {
		cout << "Toyota destructor" << endl;
	}
};

int main() {
	Car* car = new Toyota(); //透過父類別的指標來呼叫純虛擬函式
	car->show(); //呼叫子類別的show函式
	delete car; //刪除物件,會呼叫子類別的析構函式,再呼叫父類別的析構函式
	return 0;
}