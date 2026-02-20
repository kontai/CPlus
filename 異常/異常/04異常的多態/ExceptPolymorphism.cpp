#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout << "Maker的構造 (Constructor)" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷貝構造 (Copy Constructor)" << endl;
	}
	~Maker()
	{
		cout << "Maker的析構 (Destructor)" << endl;
	}
};

// --- 方式 1：拋出局部物件，並以「值傳遞」接收 ---
// 缺點：效率最低，總共產生三個物件
void func1()
{
	Maker m;    // 1. 建立局部物件（第一個）
	throw m;    // 2. 拋出時，將 m 拷貝到「異常轉移區」產生臨時副本（第二個），隨後局部物件 m 析構
}

void test01()
{
	try
	{
		func1();
	}
	catch (Maker m1) // 3. 接收時，從臨時副本再拷貝一份給 m1（第三個）
	{
		cout << "接收一個 Maker 類型的異常" << endl;
	} // catch 結束，m1 與臨時副本都會在此時析構
}

// --- 方式 2：拋出匿名物件，並以「值傳遞」接收 ---
// 產生二個物件
void func2()
{
	// 1. 產生一個匿名物件（第一個），直接作為異常拋出
	throw Maker(); 
}

void test02()
{
	try
	{
		func2();
	}
	catch (Maker m1) // 2. 接收時，將拋出的匿名物件拷貝給 m1（第二個）
	{
		cout << "接收一個 Maker 類型的異常" << endl;
	}
}

// --- 方式 3：拋出匿名物件，並以「引用 &」接收 ---
// 【最推薦的方式】：只產生一個物件，且具備多態性
void func3()
{
	throw Maker(); // 1. 產生一個匿名物件
}

void test03()
{
	try
	{
		func3();
	}
	catch (Maker &m1) // 直接引用拋出的物件，不發生拷貝構造，效率最高
	{
		cout << "接收一個 Maker 類型的異常" << endl;
	} // 匿名物件在 catch 結束後才析構

}

// --- 方式 4：拋出堆區（Heap）指標 ---
// 只產生一個物件，但存在記憶體洩漏風險
void func4()
{
	// 拋出在堆區（new）建立的物件指標
	throw new Maker(); 
}

void test04()
{
	try
	{
		func4();
	}
	catch (Maker *m1) // 接收指標
	{
		cout << "接收一個 Maker 類型的異常" << endl;

		// 必須手動 delete，否則會發生記憶體洩漏
		delete m1; 
	}
}

int main()
{
	// 測試時可以切換不同的 test 函數來觀察 Output
	test04();
	
	system("pause");
	return EXIT_SUCCESS;
}