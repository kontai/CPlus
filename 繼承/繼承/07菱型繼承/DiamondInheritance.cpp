#include<iostream>

using namespace std;

// ============================================
// 方案1：不使用虛繼承（有問題的版本）
// ============================================
class A_NormalInheritance {
public:
	int a = 20;
};

class B_NormalInheritance : public A_NormalInheritance {
};

class C_NormalInheritance : public A_NormalInheritance {
};

class D_NormalInheritance : public B_NormalInheritance, public C_NormalInheritance {
};

// ============================================
// 方案2：使用虛繼承（正確的版本）
// ============================================
// 虛繼承：使用virtual關鍵字來解決菱形繼承問題
class A {
public:
	int a = 20;
};

// 虛繼承：使用virtual關鍵字來解決菱形繼承問題
class B :virtual public A {
};

// 虛繼承：使用virtual關鍵字來解決菱形繼承問題
class C :virtual public A {
};

class D :public B, public C {
};

// ============================================
// 分析函數
// ============================================

void analyzeNormalInheritance() {
	cout << "========== 非虛繼承版本（有問題）==========" << endl;
	cout << "【記憶體大小】" << endl;
	cout << "  sizeof(A_NormalInheritance) = " << sizeof(A_NormalInheritance) << " bytes" << endl;
	cout << "  sizeof(B_NormalInheritance) = " << sizeof(B_NormalInheritance) << " bytes" << endl;
	cout << "  sizeof(C_NormalInheritance) = " << sizeof(C_NormalInheritance) << " bytes" << endl;
	cout << "  sizeof(D_NormalInheritance) = " << sizeof(D_NormalInheritance) << " bytes" << endl;
	cout << "    └─ 問題：包含了 2 份 A 的副本（各 4 bytes）" << endl << endl;

	cout << "【位址分析】" << endl;
	D_NormalInheritance d;
	B_NormalInheritance* pb = &d;
	C_NormalInheritance* pc = &d;
	
	cout << "  D 物件位址：       0x" << (unsigned long long)&d << endl;
	cout << "  透過 B 的 a 位址： 0x" << (unsigned long long)&(pb->a) << endl;
	cout << "  透過 C 的 a 位址： 0x" << (unsigned long long)&(pc->a) << endl;
	cout << "  位址不同：說明有 2 份 a 的副本！" << endl << endl;

	cout << "【值分析】" << endl;
	cout << "  d 中透過 B 訪問的 a 值：" << pb->a << endl;
	cout << "  d 中透過 C 訪問的 a 值：" << pc->a << endl;
	cout << "  注意：二者雖然值相同，但存儲位置不同！" << endl << endl;

	cout << "【編譯錯誤示例】" << endl;
	cout << "  如果嘗試：d.a = 30；會編譯失敗" << endl;
	cout << "  原因：編譯器不知道要修改哪個 a（B 的還是 C 的？）" << endl;
	cout << "  這就是二義性（Ambiguity）問題！" << endl << endl;
}

void analyzeVirtualInheritance() {
	cout << "========== 虛繼承版本（正確）==========" << endl;
	cout << "【記憶體大小】" << endl;
	cout << "  sizeof(A) = " << sizeof(A) << " bytes" << endl;
	cout << "  sizeof(B) = " << sizeof(B) << " bytes" << endl;
	cout << "  sizeof(C) = " << sizeof(C) << " bytes" << endl;
	cout << "  sizeof(D) = " << sizeof(D) << " bytes" << endl;
	cout << "    └─ 優點：只有 1 份 A 的副本" << endl;
	cout << "    └─ 代價：增加了虛基類指標 (vbptr)，每個 8 bytes" << endl << endl;

	cout << "【位址分析】" << endl;
	D d;
	B* pb = &d;
	C* pc = &d;
	
	cout << "  D 物件位址：       0x" << (unsigned long long)&d << endl;
	cout << "  透過 B 的 a 位址： 0x" << (unsigned long long)&(pb->a) << endl;
	cout << "  透過 C 的 a 位址： 0x" << (unsigned long long)&(pc->a) << endl;
	cout << "  位址相同：說明只有 1 份 a 的副本！" << endl << endl;

	cout << "【值分析】" << endl;
	cout << "  d 中透過 B 訪問的 a 值：" << pb->a << endl;
	cout << "  d 中透過 C 訪問的 a 值：" << pc->a << endl;
	cout << "  完全相同：因為它們指向同一個物件！" << endl << endl;

	cout << "【無二義性訪問】" << endl;
	cout << "  d.a = 30；✓ 編譯成功！" << endl;
	cout << "  原因：只有一個 a，編譯器知道應該訪問哪個" << endl << endl;
}

void demonstrateMemoryLayout() {
	cout << "========== 記憶體佈局示意圖 ==========" << endl << endl;

	cout << "【非虛繼承版本】" << endl;
	cout << "  D_NormalInheritance 物件：" << endl;
	cout << "    ┌─────────────────────┐ " << endl;
	cout << "    │  B 部分             │ " << endl;
	cout << "    │  ├─ A.a = 20 (B)    │ 4 bytes" << endl;
	cout << "    ├─────────────────────┤ " << endl;
	cout << "    │  C 部分             │ " << endl;
	cout << "    │  ├─ A.a = 20 (C)    │ 4 bytes (重複!)" << endl;
	cout << "    └─────────────────────┘ " << endl;
	cout << "    總計：8 bytes，有 2 份 a" << endl << endl;

	cout << "【虛繼承版本】" << endl;
	cout << "  D 物件：" << endl;
	cout << "    ┌─────────────────────┐ " << endl;
	cout << "    │  B 的 vbptr         │ 8 bytes (虛基類指標)" << endl;
	cout << "    ├─────────────────────┤ " << endl;
	cout << "    │  C 的 vbptr         │ 8 bytes (虛基類指標)" << endl;
	cout << "    ├─────────────────────┤ " << endl;
	cout << "    │  虛基類 A           │ " << endl;
	cout << "    │  ├─ A.a = 20        │ 4 bytes (只有一份!)" << endl;
	cout << "    ├─────────────────────┤ " << endl;
	cout << "    │  對齁填充           │ 4 bytes" << endl;
	cout << "    └─────────────────────┘ " << endl;
	cout << "    總計：24 bytes，只有 1 份 a" << endl << endl;
}

void demonstrateConstructionOrder() {
	cout << "========== 構造順序分析 ==========" << endl << endl;

	cout << "【虛繼承時的構造順序】" << endl;
	cout << "  D d; 創建順序：" << endl;
	cout << "    1. 虛基類 A 被首先構造（因為是虛基類）" << endl;
	cout << "    2. B 被構造（D 繼承的第一個派生類）" << endl;
	cout << "    3. C 被構造（D 繼承的第二個派生類）" << endl;
	cout << "    4. D 被構造（最後構造）" << endl << endl;

	cout << "【虛基類指標初始化】" << endl;
	cout << "  B 的 vbptr：記錄虛基類 A 相對於 B 的偏移" << endl;
	cout << "  C 的 vbptr：記錄虛基類 A 相對於 C 的偏移" << endl;
	cout << "  這些指標在構造時被初始化，用於運行時訪問虛基類" << endl << endl;
}

void compareMemoryCost() {
	cout << "========== 記憶體成本比較 ==========" << endl << endl;

	int normalSize = sizeof(D_NormalInheritance);
	int virtualSize = sizeof(D);

	cout << "  非虛繼承版本：" << normalSize << " bytes" << endl;
	cout << "    └─ 內容：[B(含A)] + [C(含A)]" << endl;
	cout << "    └─ 問題：2 份 A，二義性，難以使用" << endl << endl;

	cout << "  虛繼承版本：" << virtualSize << " bytes" << endl;
	cout << "    └─ 內容：[vbptr] + [vbptr] + [A]" << endl;
	cout << "    └─ 優點：只有 1 份 A，語義清晰，容易使用" << endl << endl;

	cout << "  額外開銷：" << (virtualSize - normalSize) << " bytes" << endl;
	cout << "  說明：雖然增加了內存，但換來了正確的語義和易用性" << endl << endl;
}

// ============================================
// 主函數
// ============================================
int main1() {
	// 分析非虛繼承版本
	analyzeNormalInheritance();

	cout << endl << endl;

	// 分析虛繼承版本
	analyzeVirtualInheritance();

	cout << endl << endl;

	// 記憶體佈局
	demonstrateMemoryLayout();

	cout << endl;

	// 構造順序
	demonstrateConstructionOrder();

	cout << endl;

	// 成本比較
	compareMemoryCost();

	cout << endl;

	// 最後驗證虛繼承版本正常工作
	cout << "========== 虛繼承版本功能驗證 ==========" << endl;
	D d;
	cout << "  d.a = " << d.a << endl;
	d.a = 99;
	cout << "  修改後 d.a = " << d.a << endl;
	cout << "  ✓ 虛繼承版本可以正常訪問和修改 a，沒有二義性！" << endl;

	return 0;
}