#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout << "Maker的構造" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷貝構造" << endl;
	}
	~Maker()
	{
		cout << "Maker的析構" << endl;
	}
};

// --- 情况 1：拋出局部對象，並以「值傳遞」接收 ---
// 這種方式效率最低，會產生三個對象
void func1()
{
	Maker m;    // 1. 建立局部對象（第一個）
	throw m;    // 2. 拋出時會拷貝出一份臨時副本（第二個），然後局部對象 m 被析構
}

void test01()
{
	try
	{
		func1();
	}
	catch (Maker m1) // 3. 接收時再次拷貝（第三個），catch 塊結束後，副本與臨時對象皆析構
	{
		cout << "接收一個Maker類型的異常" << endl;
	}
}

// --- 情况 2：拋出匿名對象，並以「值傳遞」接收 ---
// 產生兩個對象
void func2()
{
	throw Maker(); // 1. 產生一個匿名對象（第一個）
}

void test02()
{
	try
	{
		func2();
	}
	catch (Maker m1) // 2. 接收時拷貝到 m1（第二個）
	{
		cout << "接收一個Maker類型的異常" << endl;
	}
}

// --- 情况 3：拋出匿名對象，並以「引用」接收（最推薦！） ---
// 只產生一個對象，效率最高，且能利用多態
void func3()
{
	throw Maker(); // 1. 產生一個匿名對象
}

void test03()
{
	try
	{
		func3();
	}
	catch (Maker &m1) // 直接引用匿名對象，不發生拷貝構造
	{
		cout << "接收一個Maker類型的異常" << endl;
	} // 匿名對象在此處析構
}

// --- 情况 4：拋出堆區（Heap）對象的指針 ---
// 只產生一個對象，但需要手動釋放內存
void func4()
{
	// 拋出一個指向堆區對象的指針
	throw new Maker(); 
}

void test04()
{
	try
	{
		func4();
	}
	catch (Maker *m1) // 接收指針
	{
		cout << "接收一個Maker類型的異常" << endl;
		// 注意：必須手動 delete，否則會發生內存洩漏
		delete m1;
	}
}

int main()
{
	// 你可以切換 test01() 到 test04() 來觀察控制台輸出的構造與析構順序
	test04();
	
	system("pause");
	return EXIT_SUCCESS;
}