#include <iostream>
using namespace std;

// ============================================================
// 為什麼模板實現可以放在 .hpp 中而不會重複定義？
// ============================================================

/*
核心答案：
  模板不是真正的代碼，只是「代碼生成器」的藍圖
  編譯器在每個使用點才會實例化出真正的代碼
  相同的實例化結果會被編譯器自動合併

普通函數：
  實現 → 立即生成機器碼 → 多個 .cpp 包含 → 多份機器碼 → 鏈接錯誤

模板函數：
  實現 → 不生成機器碼 → 使用時才實例化 → 編譯器合併相同實例 → 不會重複
*/

// ============================================================
// 示例 1: 普通函數 - 會重複定義
// ============================================================

// ❌ 如果這段代碼被多個 .cpp 包含，會報錯
/*
// NormalFunction.h
void normalFunction(int x) {  // ← 實現在 .h 中
	cout << "Normal: " << x << endl;
}

// file1.cpp
#include "NormalFunction.h"  // → 生成一份 normalFunction 的機器碼

// file2.cpp
#include "NormalFunction.h"  // → 又生成一份 normalFunction 的機器碼

// 鏈接時：
//   ❌ 錯誤：multiple definition of `normalFunction(int)'
*/

// ============================================================
// 示例 2: 模板函數 - 不會重複定義
// ============================================================

// TemplateFunction.hpp
template<typename T>
void templateFunction(T x) {  // ← 實現在 .hpp 中，沒問題！
	cout << "Template: " << x << endl;
}

// file1.cpp
// #include "TemplateFunction.hpp"
// templateFunction(10);      // → 實例化 templateFunction<int>

// file2.cpp
// #include "TemplateFunction.hpp"
// templateFunction(20);      // → 實例化 templateFunction<int>

// 鏈接時：
//   ✅ 正確：編譯器發現兩個相同的 templateFunction<int>
//            自動合併，只保留一份

// ============================================================
// 關鍵機制：編譯與鏈接的差異
// ============================================================

void explain_mechanism() {
	cout << "\n【編譯流程對比】" << endl;
	cout << "========================================" << endl;

	cout << "\n普通函數：" << endl;
	cout << "  .cpp #include .h" << endl;
	cout << "       ↓" << endl;
	cout << "  編譯器立即生成機器碼" << endl;
	cout << "       ↓" << endl;
	cout << "  每個 .cpp → 一個 .o 文件" << endl;
	cout << "       ↓" << endl;
	cout << "  鏈接器合併 .o 文件" << endl;
	cout << "       ↓" << endl;
	cout << "  發現同名符號 → ❌ 錯誤：重複定義" << endl;

	cout << "\n模板函數/類：" << endl;
	cout << "  .cpp #include .hpp" << endl;
	cout << "       ↓" << endl;
	cout << "  編譯器看到使用點才實例化" << endl;
	cout << "       ↓" << endl;
	cout << "  每個 .o 可能有相同的實例化代碼" << endl;
	cout << "       ↓" << endl;
	cout << "  鏈接器檢查實例化的模板" << endl;
	cout << "       ↓" << endl;
	cout << "  相同實例自動合併 → ✅ 正確：只保留一份" << endl;
}

// ============================================================
// 特殊情況：inline 函數也不會重複定義
// ============================================================

// ✅ inline 函數可以在 .h 中實現
inline void inlineFunction(int x) {
	cout << "Inline: " << x << endl;
}

// 原因：inline 關鍵字告訴鏈接器「允許多個定義，自動合併」

void explain_inline() {
	cout << "\n【inline 的特殊性】" << endl;
	cout << "========================================" << endl;
	cout << "inline 函數 = 建議編譯器「內聯展開」" << endl;
	cout << "副作用 = 允許多個定義，鏈接器會合併" << endl;
	cout << "" << endl;
	cout << "這就是為什麼類內定義的成員函數不會重複：" << endl;
	cout << "  class MyClass {" << endl;
	cout << "      void func() { }  // ← 隱式 inline" << endl;
	cout << "  };" << endl;
}

// ============================================================
// 為什麼模板必須實現在 .hpp 中？
// ============================================================

void explain_why_hpp() {
	cout << "\n【為什麼模板必須在頭文件？】" << endl;
	cout << "========================================" << endl;
	cout << "原因：編譯器需要看到完整的模板定義才能實例化" << endl;
	cout << "" << endl;
	cout << "錯誤示範：" << endl;
	cout << "  // MyTemplate.h" << endl;
	cout << "  template<typename T>" << endl;
	cout << "  class MyTemplate {" << endl;
	cout << "      void func();  // 只有聲明" << endl;
	cout << "  };" << endl;
	cout << "" << endl;
	cout << "  // MyTemplate.cpp" << endl;
	cout << "  template<typename T>" << endl;
	cout << "  void MyTemplate<T>::func() { }  // 實現在 .cpp" << endl;
	cout << "" << endl;
	cout << "  // main.cpp" << endl;
	cout << "  #include \"MyTemplate.h\"" << endl;
	cout << "  MyTemplate<int> obj;" << endl;
	cout << "  obj.func();  // ❌ 鏈接錯誤！找不到實例化的代碼" << endl;
	cout << "" << endl;
	cout << "為什麼錯誤？" << endl;
	cout << "  1. main.cpp 編譯時，只看到聲明，無法實例化 func()" << endl;
	cout << "  2. MyTemplate.cpp 編譯時，沒有任何使用點，不會實例化" << endl;
	cout << "  3. 鏈接時找不到 MyTemplate<int>::func() 的實現" << endl;
}

// ============================================================
// C++11 的 extern template（進階）
// ============================================================

void explain_extern_template() {
	cout << "\n【進階：顯式實例化】" << endl;
	cout << "========================================" << endl;
	cout << "如果確實想分離模板實現，可以用顯式實例化：" << endl;
	cout << "" << endl;
	cout << "  // MyTemplate.h" << endl;
	cout << "  template<typename T>" << endl;
	cout << "  class MyTemplate { void func(); };" << endl;
	cout << "" << endl;
	cout << "  // MyTemplate.cpp" << endl;
	cout << "  #include \"MyTemplate.h\"" << endl;
	cout << "  template<typename T>" << endl;
	cout << "  void MyTemplate<T>::func() { }" << endl;
	cout << "  template class MyTemplate<int>;     // 顯式實例化" << endl;
	cout << "  template class MyTemplate<double>;  // 顯式實例化" << endl;
	cout << "" << endl;
	cout << "  // main.cpp" << endl;
	cout << "  #include \"MyTemplate.h\"" << endl;
	cout << "  MyTemplate<int> obj;  // ✅ 鏈接成功" << endl;
	cout << "" << endl;
	cout << "限制：必須預先知道所有可能的實例化類型" << endl;
}

// ============================================================
// 總結
// ============================================================

void summary() {
	cout << "\n【總結】" << endl;
	cout << "========================================" << endl;
	cout << "為什麼 .hpp 可以包含模板實現而不報錯？" << endl;
	cout << "" << endl;
	cout << "1. 模板不是真正的代碼，是代碼生成器" << endl;
	cout << "2. 只有在使用時才實例化出真正的代碼" << endl;
	cout << "3. 相同的實例化結果會被鏈接器自動合併" << endl;
	cout << "4. 編譯器需要看到完整定義才能實例化" << endl;
	cout << "5. 所以模板實現必須放在頭文件（.hpp）" << endl;
	cout << "" << endl;
	cout << "普通函數為什麼會報錯？" << endl;
	cout << "" << endl;
	cout << "1. 普通函數立即生成機器碼" << endl;
	cout << "2. 多個 .cpp 包含 → 多份相同機器碼" << endl;
	cout << "3. 鏈接時發現重複 → 報錯" << endl;
	cout << "" << endl;
	cout << "解決方法：" << endl;
	cout << "  • 普通函數：實現放 .cpp，聲明放 .h" << endl;
	cout << "  • 模板：實現和聲明都放 .hpp" << endl;
	cout << "  • inline 函數：可以在 .h 中實現" << endl;
	cout << "========================================" << endl;
}

// ============================================================
// 主程序
// ============================================================

int main() {
	cout << "========================================" << endl;
	cout << "  模板為何可以在 .hpp 中實現？" << endl;
	cout << "========================================" << endl;

	explain_mechanism();
	explain_inline();
	explain_why_hpp();
	explain_extern_template();
	summary();

	// 測試模板函數
	cout << "\n【測試】" << endl;
	templateFunction(42);
	templateFunction(3.14);
	inlineFunction(100);

	return 0;
}