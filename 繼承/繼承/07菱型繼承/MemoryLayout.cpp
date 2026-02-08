#include<iostream>
#include<iomanip>

using namespace std;

// ===== 原始版本：沒有虛繼承的菱型繼承 =====
class A_NonVirtual {
public:
    int a = 20;
};

class B_NonVirtual : public A_NonVirtual {
};

class C_NonVirtual : public A_NonVirtual {
};

class D_NonVirtual : public B_NonVirtual, public C_NonVirtual {
};

// ===== 虛繼承版本 =====
class A_Virtual {
public:
    int a = 20;
};

class B_Virtual : virtual public A_Virtual {
};

class C_Virtual : virtual public A_Virtual {
};

class D_Virtual : public B_Virtual, public C_Virtual {
};

// ===== 記憶體佈局分析函數 =====
void analyzeMemoryLayouts() {
    cout << "========== 記憶體大小分析 ==========" << endl << endl;

    // 1. 基類大小
    cout << "【1】基類大小：" << endl;
    cout << "  sizeof(A_NonVirtual) = " << sizeof(A_NonVirtual) << " bytes" << endl;
    cout << "  sizeof(A_Virtual) = " << sizeof(A_Virtual) << " bytes" << endl << endl;

    // 2. 單層繼承的大小
    cout << "【2】單層繼承（B繼承A）：" << endl;
    cout << "  sizeof(B_NonVirtual) = " << sizeof(B_NonVirtual) << " bytes" << endl;
    cout << "    └─ 包含：A_NonVirtual(4bytes) + 對?" << endl;
    cout << "  sizeof(B_Virtual) = " << sizeof(B_Virtual) << " bytes" << endl;
    cout << "    └─ 包含：虛基類指標(8bytes) + A_Virtual(4bytes) + 對?" << endl << endl;

    // 3. 兩層繼承的大小
    cout << "【3】兩層繼承（B和C都繼承A）：" << endl;
    cout << "  sizeof(C_NonVirtual) = " << sizeof(C_NonVirtual) << " bytes" << endl;
    cout << "  sizeof(C_Virtual) = " << sizeof(C_Virtual) << " bytes" << endl << endl;

    // 4. 菱型繼承（D同時繼承B和C）
    cout << "【4】菱型繼承（D繼承B和C）：" << endl;
    cout << "  ┌─ 非虛繼承版本：" << endl;
    cout << "  │  sizeof(D_NonVirtual) = " << sizeof(D_NonVirtual) << " bytes" << endl;
    cout << "  │    問題：包含 2 份A的副本！" << endl;
    cout << "  │    結構：[B(含A)] + [C(含A)] = 4+4 = 8 bytes A" << endl << endl;

    cout << "  ┌─ 虛繼承版本：" << endl;
    cout << "  │  sizeof(D_Virtual) = " << sizeof(D_Virtual) << " bytes" << endl;
    cout << "  │    優點：只有 1 份A的副本！" << endl;
    cout << "  │    結構：[B虛指標] + [C虛指標] + [共享的A] = 8+8+4 = 20 bytes" << endl << endl;

    // 5. 記憶體節省分析
    cout << "【5】記憶體節省分析：" << endl;
    int nonVirtualSize = sizeof(D_NonVirtual);
    int virtualSize = sizeof(D_Virtual);
    cout << "  非虛繼承版本：" << nonVirtualSize << " bytes" << endl;
    cout << "  虛繼承版本：" << virtualSize << " bytes" << endl;
    cout << "  增加開銷：" << (virtualSize - nonVirtualSize) << " bytes" << endl;
    cout << "  說明：虛繼承增加了虛基類指標，但消除了重複的基類副本" << endl << endl;
}

// ===== 記憶體位址分析 =====
void analyzeMemoryAddresses() {
    cout << "========== 物件記憶體位址分析 ==========" << endl << endl;

    // 非虛繼承版本
    cout << "【非虛繼承版本】" << endl;
    D_NonVirtual dNonVirtual;
    cout << "  D_NonVirtual 物件位址：0x" << (unsigned long long)&dNonVirtual << endl;
    
    // 透過B和C訪問a的位址（應該不同）
    B_NonVirtual* pB = &dNonVirtual;
    C_NonVirtual* pC = &dNonVirtual;
    
    cout << "  透過 B 指標訪問的 a 位址：0x" << (unsigned long long)&pB->a << endl;
    cout << "  透過 C 指標訪問的 a 位址：0x" << (unsigned long long)&pC->a << endl;
    cout << "  問題：兩個位址不同，存在重複的a！" << endl << endl;

    // 虛繼承版本
    cout << "【虛繼承版本】" << endl;
    D_Virtual dVirtual;
    cout << "  D_Virtual 物件位址：0x" << (unsigned long long)&dVirtual << endl;
    
    B_Virtual* pBV = &dVirtual;
    C_Virtual* pCV = &dVirtual;
    
    cout << "  透過 B 指標訪問的 a 位址：0x" << (unsigned long long)&pBV->a << endl;
    cout << "  透過 C 指標訪問的 a 位址：0x" << (unsigned long long)&pCV->a << endl;
    cout << "  優點：兩個位址相同，共享同一個a！" << endl << endl;
}

// ===== 虛指標表分析 =====
void analyzeVirtualPointers() {
    cout << "========== 虛指標表（vptr）分析 ==========" << endl << endl;

    cout << "【虛繼承中的虛基類指標】" << endl;
    cout << "  虛基類指標用途：記錄虛基類相對於當前物件的偏移" << endl;
    cout << "  大小：通常 8 bytes（64位系統）" << endl << endl;

    cout << "【記憶體佈局示意圖】" << endl;
    cout << "  D_Virtual 物件佈局（假設在位址 0x1000）：" << endl;
    cout << "    0x1000 ┌─────────────────────────┐" << endl;
    cout << "           │  B 的虛基類指標 (vbptr) │  8 bytes" << endl;
    cout << "    0x1008 ├─────────────────────────┤" << endl;
    cout << "           │  C 的虛基類指標 (vbptr) │  8 bytes" << endl;
    cout << "    0x1010 ├─────────────────────────┤" << endl;
    cout << "           │  共享的 A 的成員        │" << endl;
    cout << "           │  A.a (int, 4 bytes)     │  4 bytes" << endl;
    cout << "    0x1014 ├─────────────────────────┤" << endl;
    cout << "           │  對?填充               │  4 bytes" << endl;
    cout << "    0x1018 └─────────────────────────┘" << endl << endl;
}

// ===== 完整測試 =====
int main2() {
    analyzeMemoryLayouts();
    cout << endl;
    analyzeMemoryAddresses();
    cout << endl;
    analyzeVirtualPointers();

    cout << "========== 實際物件值驗證 ==========" << endl;
    D_Virtual d;
    cout << "D_Virtual 物件的 a 值：" << d.a << endl;

    return 0;
}
