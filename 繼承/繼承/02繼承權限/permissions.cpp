#include<iostream>

/*
* 2026/02/08
* 02繼承權限 - 演示C++中三種繼承方式的權限機制
* 
* 概念說明：
* - 公有繼承(public)：基類的public成員保持public，protected成員保持protected
* - 私有繼承(private)：基類的public和protected成員都變成private
* - 保護繼承(protected)：基類的public和protected成員都變成protected
* - 無論何種繼承，基類的private成員都無法被派生類訪問
*/

using namespace std;

// 基類：定義不同權限等級的成員變數
class Base {
public:
	int pub_v;			// 公有成員：可被任何地方訪問
private:
	int pri_v;			// 私有成員：只能在Base類內部訪問
protected:
	int pro_v;			// 保護成員：只能在Base及其派生類內部訪問
};

// ============ 公有繼承 ============
// 特點：派生類繼承了基類的所有公有和保護成員，且權限不變
class DerivedPublic :public Base {
public:
	void func() {
		pub_v = 1;		// ✓ 可訪問：pub_v在public繼承下仍為public
		pro_v = 2;		// ✓ 可訪問：pro_v在public繼承下仍為protected，派生類內可訪問
		//pri_v = 3;		// ✗ 不可訪問：基類private成員無法被繼承
	}
};

// ============ 私有繼承 ============
// 特點：派生類繼承的所有成員（包括基類的public和protected）都變成private
class DerivedPrivate :private Base {
public:
	void func() {
		pub_v = 1;		// ✓ 可訪問：pub_v在private繼承下變成private，但派生類內仍可訪問
		pro_v = 2;		// ✓ 可訪問：pro_v在private繼承下變成private，但派生類內仍可訪問
		//pri_v = 3;		// ✗ 不可訪問：基類private成員無法被繼承
	}
};

// ============ 保護繼承 ============
// 特點：派生類繼承的所有成員（包括基類的public和protected）都變成protected
class DerivedProtected :protected Base {
public:
	void func() {
		pub_v = 1;		// ✓ 可訪問：pub_v在protected繼承下變成protected，派生類內可訪問
		pro_v = 2;		// ✓ 可訪問：pro_v在protected繼承下仍為protected，派生類內可訪問
		//pri_v = 3;		// ✗ 不可訪問：基類private成員無法被繼承
	}
};

// ============ 類外訪問演示 ============
// 展示在類定義外部，各種繼承方式對成員的訪問限制
void outClass()
{
	// ---- 公有繼承示例 ----
	DerivedPublic dpub;
	dpub.pub_v = 1;		// ✓ 可訪問：pub_v在public繼承下仍為public
	//dpub.pri_v = 1;		// ✗ 編譯錯誤：'int Base::pri_v' is private within this context
	//dpub.pro_v = 1;		// ✗ 編譯錯誤：'int Base::pro_v' is protected within this context

	// ---- 私有繼承示例 ----
	DerivedPrivate dpri;
	//dpri.pub_v = 1;		// ✗ 編譯錯誤：'int Base::pub_v' is inaccessible within this context
							//   (pub_v在private繼承下變成private)
	//dpri.pri_v = 1;		// ✗ 編譯錯誤：'int Base::pri_v' is private within this context
	//dpri.pro_v = 1;		// ✗ 編譯錯誤：'int Base::pro_v' is inaccessible within this context
							//   (pro_v在private繼承下變成private)

	// ---- 保護繼承示例 ----
	DerivedProtected dpro;
	//dpro.pub_v = 1;		// ✗ 編譯錯誤：'int Base::pub_v' is inaccessible within this context
							//   (pub_v在protected繼承下變成protected)
	//dpro.pri_v = 1;		// ✗ 編譯錯誤：'int Base::pri_v' is private within this context
	//dpro.pro_v = 1;		// ✗ 編譯錯誤：'int Base::pro_v' is inaccessible within this context
							//   (pro_v在protected繼承下變成protected)
}

// 程序入口點
int main() {
	


	return 0;
}