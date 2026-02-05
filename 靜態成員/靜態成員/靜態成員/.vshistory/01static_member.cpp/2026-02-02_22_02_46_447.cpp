// 包含必要的標準庫
#include<iostream>
#include<string>

using namespace std;

/*

*/

// 演示靜態成員的類別
class MyClass {
public:
	// 靜態成員函數：可以直接通過類別名稱呼叫，無需建立物件
	static void display() {
		// 靜態成員函數可以訪問靜態成員變數
		cout << "Static member function called. val = " << val << endl;
		// 靜態成員函數無法訪問非靜態成員變數（需要物件實例）
		//cout << "val2 cannot be accessed here: "<<val2 << endl;
	}

	// 非靜態成員函數：可以訪問靜態和非靜態成員
	void show_static() {
		// 在非靜態成員函數中可以訪問靜態成員變數
		cout << "Accessing static member from non-static member function. val = " << val << endl;
	}

private:
	// 私有靜態成員函數：只能在類別內部呼叫
	static void pri_display() {
		cout << "Private static member function called." << endl;
	}

	// 靜態成員變數：所有物件實例共享同一份
	static int val;

	// 非靜態成員變數：每個物件實例都有獨立的副本
	int val2;	// 無法在靜態成員函數中訪問

	// 靜態常數成員：支援類內初始化
	const static int const_val = 20;

	// 靜態常數成員：需要在類外定義
	const static int const_val2;
};

// 靜態成員變數的類外定義與初始化
int MyClass::val = 10;

// 靜態常數成員的類外定義
const int MyClass::const_val2 = 30;

// 演示通過類別名稱直接呼叫靜態成員函數
void func() {
	MyClass::display();	// 無需建立物件即可呼叫靜態成員函數
	//MyClass::pri_display(); // 編譯錯誤：無法訪問私有靜態成員函數
}

// 演示通過物件實例呼叫非靜態成員函數
void func2() {
	MyClass mc;	// 建立類別物件
	mc.show_static();	// 正確：通過物件呼叫非靜態成員函數
	//MyClass::show_static(); // 編譯錯誤：非靜態成員函數需要物件實例
}

void func3() {
	static int local_static_var = 0; // 靜態區域變數，只初始化一次
}

// 程式入口點
int main() {
	func();	// 呼叫演示函數

	//local_static_var = 5;	// 編譯錯誤：無法在此作用域訪問

	return 0;	// 程式正常結束
}