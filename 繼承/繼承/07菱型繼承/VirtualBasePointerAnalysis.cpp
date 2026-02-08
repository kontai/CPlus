#include<iostream>
#include<cstring>

using namespace std;

// ============================================
// 虛基類指標深度探索
// ============================================

class A {
public:
	int a = 20;
	virtual ~A() = default;
};

class B : virtual public A {
public:
	int b = 10;
};

class C : virtual public A {
public:
	int c = 5;
};

class D : public B, public C {
public:
	int d = 30;
};

// ============================================
// 虛基類指標結構分析
// ============================================

void analyzeVBPtrStructure() {
	cout << "========== 虛基類指標結構分析 ==========" << endl << endl;

	D d;

	cout << "【物件大小信息】" << endl;
	cout << "  sizeof(A) = " << sizeof(A) << endl;
	cout << "  sizeof(B) = " << sizeof(B) << endl;
	cout << "  sizeof(C) = " << sizeof(C) << endl;
	cout << "  sizeof(D) = " << sizeof(D) << endl << endl;

	cout << "【虛基類指標說明】" << endl;
	cout << "  虛繼承中，每個派生類包含一個虛基類指標 (vbptr)" << endl;
	cout << "  虛基類指標用來記錄虛基類相對於當前物件的偏移" << endl;
	cout << "  大小：通常 8 bytes（64位系統）" << endl << endl;
	
	// 更安全的分析方法：透過成員位址計算
	cout << "【虛基類指標位置與作用】" << endl;
	cout << "  D 物件起始位址：0x" << (unsigned long long)&d << endl;
	
	// 計算各成員的相對位置，從而推斷虛基類指標的存在
	unsigned long long base_addr = (unsigned long long)&d;
	unsigned long long addr_a = (unsigned long long)&d.a;
	unsigned long long addr_b = (unsigned long long)&d.b;
	unsigned long long addr_c = (unsigned long long)&d.c;
	unsigned long long addr_d_member = (unsigned long long)&d.d;

	cout << "  虛基類 A 的位址：0x" << addr_a << " (相對偏移: " << (addr_a - base_addr) << " bytes)" << endl;
	cout << "    └─ 這個位址由虛基類指標計算得到" << endl;
	cout << "  D 的成員位址：0x" << addr_d_member << " (相對偏移: " << (addr_d_member - base_addr) << " bytes)" << endl;
	cout << "  B 的成員位址：0x" << addr_b << " (相對偏移: " << (addr_b - base_addr) << " bytes)" << endl;
	cout << "  C 的成員位址：0x" << addr_c << " (相對偏移: " << (addr_c - base_addr) << " bytes)" << endl << endl;
	
	cout << "【記憶體佈局推斷】" << endl;
	cout << "  根據成員位址可推斷記憶體佈局：" << endl;
	cout << "  ├─ 偏移 0-7: vfptr (虛函數表指標)" << endl;
	cout << "  ├─ 偏移 8-15: vbptr_B (虛基類指標)" << endl;
	cout << "  ├─ 偏移 16-23: vbptr_C (虛基類指標)" << endl;
	cout << "  ├─ 偏移 24-27: D 的成員 d" << endl;
	cout << "  ├─ 偏移 28-31: B 的成員 b" << endl;
	cout << "  ├─ 偏移 32-35: C 的成員 c" << endl;
	cout << "  └─ 最後: 虛基類 A 的成員 a" << endl << endl;
}

void analyzeMemberAddresses() {
	cout << "========== 成員變數位址分析 ==========" << endl << endl;

	D d;
	d.a = 100;
	d.b = 200;
	d.c = 300;
	d.d = 400;

	cout << "【各成員變數的位址】" << endl;
	cout << "  &d.a (虛基類 A)：0x" << (unsigned long long)&d.a << endl;
	cout << "  &d.b (B)：      0x" << (unsigned long long)&d.b << endl;
	cout << "  &d.c (C)：      0x" << (unsigned long long)&d.c << endl;
	cout << "  &d.d (D)：      0x" << (unsigned long long)&d.d << endl << endl;

	cout << "【透過指標訪問】" << endl;
	A* pa = &d;
	B* pb = &d;
	C* pc = &d;

	cout << "  A* pa 指向的 a 位址：0x" << (unsigned long long)&pa->a << endl;
	cout << "  B* pb 指向的 a 位址：0x" << (unsigned long long)&pb->a << endl;
	cout << "  C* pc 指向的 a 位址：0x" << (unsigned long long)&pc->a << endl << endl;

	cout << "【位址相同確認】" << endl;
	if (&pa->a == &pb->a && &pb->a == &pc->a) {
		cout << "  ? 所有指標都指向同一個虛基類 A！" << endl;
		cout << "  ? 虛繼承確實消除了重複！" << endl;
	}
	cout << endl;
}

void analyzeMemoryLayout() {
	cout << "========== 詳細記憶體佈局分析 ==========" << endl << endl;

	D d;
	// 初始化所有成員，方便觀察
	d.a = 111;
	d.b = 222;
	d.c = 333;
	d.d = 444;

	unsigned char* pBase = (unsigned char*)&d;
	cout << "【逐字節記憶體內容】" << endl;
	cout << "  物件起始位址：0x" << (unsigned long long)pBase << endl;
	cout << "  物件總大小：" << sizeof(D) << " bytes" << endl << endl;

	// 安全地列出記憶體內容，避免超出物件邊界
	int memsize = sizeof(D);
	int display_size = (memsize < 64) ? memsize : 64;  // 最多顯示 64 字節

	cout << "  前 " << display_size << " 字節的內容（十六進制）：" << endl;
	for (int i = 0; i < display_size; i++) {
		if (i % 16 == 0) {
			cout << endl << "  +0x" << (unsigned long long)i << ": ";
		} else if (i % 8 == 0) {
			cout << "  ";
		}
		cout.width(2);
		cout.fill('0');
		cout << hex << (int)pBase[i] << " ";
	}
	cout << dec << endl << endl;

	cout << "【記憶體映射詳解】" << endl;
	cout << "  虛繼承記憶體佈局特點：" << endl;
	cout << "  1. 虛函數表指標 (vfptr): 8 bytes - 用於虛函數調用" << endl;
	cout << "  2. 虛基類指標 (vbptr_B): 8 bytes - 指向虛基類 A 的偏移" << endl;
	cout << "  3. 虛基類指標 (vbptr_C): 8 bytes - 指向虛基類 A 的偏移" << endl;
	cout << "  4. 派生類成員: D 的成員 d (4 bytes int)" << endl;
	cout << "  5. 中間派生類成員: B 的成員 b (4 bytes int)" << endl;
	cout << "  6. 中間派生類成員: C 的成員 c (4 bytes int)" << endl;
	cout << "  7. 虛基類成員: A 的成員 a (4 bytes int)" << endl;
	cout << "  8. 對齁填充: 確保記憶體對齁" << endl << endl;

	cout << "【關鍵發現】" << endl;
	cout << "  虛基類 A 只在記憶體中出現一次！" << endl;
	cout << "  無論透過 B 或 C 訪問，都指向同一份 A 的副本" << endl << endl;
}

void analyzePointerArithmetic() {
	cout << "========== 指標算術分析 ==========" << endl << endl;

	D d;
	d.a = 111;
	d.b = 222;
	d.c = 333;
	d.d = 444;

	unsigned long long addr_d = (unsigned long long)&d;
	unsigned long long addr_a = (unsigned long long)&d.a;
	unsigned long long addr_b = (unsigned long long)&d.b;
	unsigned long long addr_c = (unsigned long long)&d.c;
	unsigned long long addr_d_member = (unsigned long long)&d.d;

	cout << "【位址計算】" << endl;
	cout << "  &d = 0x" << addr_d << endl;
	cout << "  &d.a = 0x" << addr_a << " (偏移 " << (addr_a - addr_d) << " bytes)" << endl;
	cout << "  &d.b = 0x" << addr_b << " (偏移 " << (addr_b - addr_d) << " bytes)" << endl;
	cout << "  &d.c = 0x" << addr_c << " (偏移 " << (addr_c - addr_d) << " bytes)" << endl;
	cout << "  &d.d = 0x" << addr_d_member << " (偏移 " << (addr_d_member - addr_d) << " bytes)" << endl << endl;

	cout << "【成員變數的值】" << endl;
	cout << "  d.a = " << d.a << endl;
	cout << "  d.b = " << d.b << endl;
	cout << "  d.c = " << d.c << endl;
	cout << "  d.d = " << d.d << endl << endl;
}

void compareInheritanceStyles() {
	cout << "========== 虛繼承 vs 普通繼承 ==========" << endl << endl;

	// 定義普通繼承版本用於比較
	class A_Normal {
	public:
		int a = 20;
	};

	class B_Normal : public A_Normal {
	};

	class C_Normal : public A_Normal {
	};

	class D_Normal : public B_Normal, public C_Normal {
	};

	cout << "【大小比較】" << endl;
	cout << "  普通繼承 D：" << sizeof(D_Normal) << " bytes" << endl;
	cout << "    └─ 結構：[B(含A)] + [C(含A)]" << endl;
	cout << "    └─ 問題：重複的 A" << endl << endl;

	cout << "  虛繼承 D：" << sizeof(D) << " bytes" << endl;
	cout << "    └─ 結構：[vbptr] + [vbptr] + [虛基類A]" << endl;
	cout << "    └─ 優點：共享的 A" << endl << endl;

	cout << "【位址位置】" << endl;
	D_Normal d_normal;
	D d_virtual;

	cout << "  普通繼承：" << endl;
	cout << "    B 的 a 位址：0x" << (unsigned long long)((B_Normal*)&d_normal)->a << endl;
	cout << "    C 的 a 位址：0x" << (unsigned long long)((C_Normal*)&d_normal)->a << endl;
	cout << "    → 不同位址（有 2 份 a）" << endl << endl;

	cout << "  虛繼承：" << endl;
	cout << "    B 的 a 位址：0x" << (unsigned long long)((B*)&d_virtual)->a << endl;
	cout << "    C 的 a 位址：0x" << (unsigned long long)((C*)&d_virtual)->a << endl;
	cout << "    → 相同位址（只有 1 份 a）" << endl << endl;
}

// ============================================
// 主函數
// ============================================
int main() {
	analyzeVBPtrStructure();
	cout << endl << endl;

	analyzeMemberAddresses();
	cout << endl << endl;

	analyzeMemoryLayout();
	cout << endl << endl;

	analyzePointerArithmetic();
	cout << endl << endl;

	compareInheritanceStyles();

	cout << "========== 總結 ==========" << endl;
	cout << "虛繼承通過以下機制解決菱型繼承問題：" << endl;
	cout << "1. 使用虛基類指標（vbptr）記錄虛基類的位置" << endl;
	cout << "2. 虛基類在記憶體中只有一份副本" << endl;
	cout << "3. 運行時透過虛基類指標動態尋址虛基類" << endl;
	cout << "4. 完全消除了二義性問題" << endl;
	cout << endl;

	return 0;
}
