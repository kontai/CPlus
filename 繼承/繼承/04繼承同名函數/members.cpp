#include<iostream>

using namespace std;

// 基類A：定義了函數重載
class A {
public:
	int a = 20;

	// 普通成員函數 func()，無參數版本
	void func() {
		cout << "A::func()" << endl;
		cout << "a=" << a << endl;
	}

	// 普通成員函數 func()，有參數版本（函數重載）
	void func(int v) {
		cout << "A::func(int v)" << endl;
	}

	// 靜態成員函數 sfunc()，無參數版本
	static void sfunc() {
		cout << "A::sfunc()" << endl;
	}

	// 靜態成員函數 sfunc()，有參數版本（函數重載）
	static void sfunc(int v) {
		cout << "A::sfunc(int v)" << endl;
	}
};

// 類別B：公開繼承A，覆蓋A的同名函數
class B :public A {
public:
	int a = 19;  // 遮蔽基類A的成員變數a
	
	// 覆蓋基類A的func()函數
	// 注意：這會隱藏A中的所有func()重載版本（包括func(int v)）
	void func() {
		cout << "B::func()" << endl;
	}
	
	// 覆蓋基類A的靜態函數sfunc()
	static void sfunc() {
		cout << "B::sfunc()" << endl;
	}

	//靜態函數不可以是虛函數，因為靜態函數不屬於任何對象，所以無法通過對象來調用，也就無法實現多態行為。
	//virtual 	static void vfunc() {	
	//			cout << "B::vfuc()" << endl;

	//}
};

// 類別C：公開繼承A，沒有覆蓋同名函數
class C :public A {
public:
	int a = 18;  // 遮蔽基類A的成員變數a
	// func()函數被註解掉，所以C類會直接使用A類的func()和func(int v)
	//void func() {
	//	cout << "C::func()" << endl;
	//}
};

// 測試函數：演示同名函數的隱藏行為
void f() {
	// === 測試類別B的函數隱藏現象 ===
	B b;
	b.func();	// 呼叫B類的func()函數（無參數版本）
	
	// b.func(20);		
	// 錯誤！B類沒有func(int v)函數
	// 原因：B類的func()隱藏了A類的所有func()重載版本（包括func(int v)）
	// 這稱為"函數名隱藏"（name hiding），不同於函數重載

	// === 測試類別C的函數繼承現象 ===
	C c;
	cout << "=============" << endl;
	
	c.func();	// 呼叫A類的func()函數（因為C類沒有定義func()）
	c.func(20);	// 呼叫A類的func(int v)函數（因為C類沒有定義func(int v)）
				// C類可以訪問A類的所有func()重載版本

	// === 測試靜態函數的隱藏現象 ===
	b.sfunc();	// 呼叫B類的sfunc()函數（非靜態版本）
	
	// 測試C類的靜態函數訪問
	c.sfunc();		// 呼叫A類的靜態sfunc()函數（無參數版本）
	c.sfunc(20);	// 呼叫A類的靜態sfunc(int v)函數（有參數版本）
}

int main() {
	f();
	return 0;  // 添加返回值以符合良好的C++習慣
}