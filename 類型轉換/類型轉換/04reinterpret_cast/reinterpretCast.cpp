#include<iostream>
#include<cstdint>
#include<cassert>
using namespace std;

/*
* "reinterpret" 意思是「重新解釋」
* 它不會更改記憶體裡面的任何一個 Bit，它只是強迫編譯器：「閉嘴，把這塊記憶體位址當作這個新型別來看待！
* 它做的是「位元重新解讀」。
* 使用時機：
*		將一個整數（例如硬體暫存器位址）強行轉換為指標。
*		在不同的、毫無關聯的指標型別之間強行轉換。
*/

// 指標 → 整數 → 指標（位址暫存/傳遞）
void  f01() {
	int i = 7;

	std::uintptr_t v = reinterpret_cast<std::uintptr_t>(&i);
	int* p = reinterpret_cast<int*>(v);

	assert(p == &i);
	std::cout << *p << "\n";
}

// 函式指標轉換（能轉，但呼叫可能 UB）
int f() { return 42; }

void f02() {
	void(*fp1)() = reinterpret_cast<void(*)()>(f);
	// fp1(); // 未定義行為（cppreference 特別提醒）[web:3]

	int(*fp2)() = reinterpret_cast<int(*)()>(fp1);
	std::cout << fp2() << "\n"; // cppreference 範例中這樣展示 [web:3]
}

// 用位址做簡單 hash（把指標視為整數
//Microsoft Learn 提供一個例子：把 void* 轉成整數做 XOR/shift，產生一個基於位址的雜湊碼（用途是「用位址映射成索引」）
//https://learn.microsoft.com/zh-tw/cpp/cpp/reinterpret-cast-operator?view=msvc-170

unsigned short Hash(void* p) {
	//unsigned int val = reinterpret_cast<unsigned int>(p);
	/*
	* 在 32-bit 系統 (如 x86, ARM Cortex-M) 下：指標 p 是 4 Bytes (32-bit)，unsigned int 也是 4 Bytes。兩邊大小一樣，完美轉換。
	* 在 64-bit 系統 (如 x64 Windows/Linux) 下：指標 p 變成了 8 Bytes (64-bit)，但 unsigned int 通常還是 4 Bytes (32-bit)。
	*/

	uintptr_t val = reinterpret_cast<uintptr_t>(p);	// 更安全的做法,32bit 與 64bit 都能用
	uintptr_t shift=val>>16;
	cout << "val: " << val << endl;
	cout<<"shift: "<<shift<<endl;
	return static_cast<unsigned short>(val ^ (val >> 16));
}

void f03() {
	int a[20];
	for (int i = 0; i < 20; i++)
		std::cout << Hash(a + i) << "\n";
}

int main() {
	f01();
	f02();
	f03();
	return 0;
}