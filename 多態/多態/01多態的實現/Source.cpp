#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

/*
*2026/02/12
*AUTHOR:kontai
*
多態:
解決了在父類別中宣告函式,在子類別中覆寫該函式的問題
不必為每一個類別寫一個函式,只要在父類別中宣告為虛擬函式,在子類別中覆寫該函式即可實現多態
多態實現的條件:
1.必須有繼承關係
2.父類別中必須有虛擬函式
3.子類別中必須覆寫父類別的虛擬函式
4.透過父類別的指標或參考來呼叫虛擬函式
5.父類別的虛擬函式必須有虛擬析構函式,以確保在刪除物件時能正確呼叫子類別的析構函式(否則只會調用父類的析構函數,造成記憶體洩漏)

*/
class Car {
public:
	Car() {
		cout << "Car constructor" << endl;
	}

	//靜態綁定:在編譯時就確定要呼叫哪一個函式
	void display() {
		cout << "Car display" << endl;
	}

	//動態綁定:在編譯時無法確定要呼叫哪一個函式,在執行時才會確定要呼叫哪一個函式
	virtual void show() {
		cout << "Car show" << endl;
	}

	virtual ~Car() {
		cout << "Car destructor" << endl;
	}
};

class Toyota : public Car {
public:
	Toyota() {
		cout << "Toyota constructor" << endl;
	}

	void display() {
		cout << "Toyota display" << endl;
	}

	virtual void show() {
		cout << "Toyota show" << endl;
	}
	~Toyota() {
		cout << "Toyota destructor" << endl;
	}
};

class Honda : public Car {
public:
	Honda() {
		cout << "Honda constructor" << endl;
	}

	void display() {
		cout << "Honda display" << endl;
	}

	virtual void show() {
		cout << "Honda show" << endl;
	}
	~Honda() {
		cout << "Honda destructor" << endl;
	}
};

class BMW : public Car {
public:
	BMW() {
		cout << "BMW constructor" << endl;
	}

	void display() {
		cout << "BMW display" << endl;
	}

	virtual void show() {
		cout << "BMW show" << endl;
	}
	~BMW() {
		cout << "BMW destructor" << endl;
	}
};

void func(Car* car) {
	car->display(); // 呼叫父類別的 display 函式(因為 display 是靜態綁定,所以會呼叫父類別的 display 函式)
	car->show();    // 呼叫子類別的 show 函式 (因為 show 是動態綁定,所以會呼叫子類別的 show 函式)
								//1.	通過 carPtr 取得虛指標 vptr
								//2.	通過 vptr 查找虛函數表
								//3.	在虛函數表中找到 show() 的位置
}

void test() {
	Car* car1 = new Toyota();
	Car* car2 = new Honda();
	Car* car3 = new BMW();
	func(car1);
	func(car2);
	func(car3);
	delete car1;
	delete car2;
	delete car3;
}

int main() {
	test();
	return EXIT_SUCCESS;
}