#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
using namespace std;

// ============================================================
// 問題1：binary_function 和 unary_function 已棄用（C++11）
// 解決：使用 lambda 或直接定義函數對象
// ============================================================

// ❌ 舊式寫法（C++98，已棄用）
/*
struct Myfunc : public binary_function<int, int, void> {
	void operator()(int v1, int v2) const {
		cout << v1 + v2 << endl;
	}
};
*/

// ✅ 新式寫法1：直接定義函數對象
struct Myfunc {
	void operator()(int v1, int v2) const {
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;
		cout << "v1 + v2 = " << v1 + v2 << endl;
	}
};

// ✅ 新式寫法2：使用 lambda（推薦）
void test01_lambda() {
	cout << "=== 測試1：Lambda 版本 ===" << endl;
	vector<int> v = { 10, 20, 30, 40, 50 };

	// 使用 lambda，更簡潔
	int add_value = 100;
	for_each(v.begin(), v.end(), [add_value](int val) {
		cout << "val = " << val << endl;
		cout << "val + 100 = " << val + add_value << endl;
		});
}

// ❌ 問題2：bind2nd 已棄用
void test01_old() {
	cout << "\n=== 測試1：舊式 bind2nd（已棄用）===" << endl;
	vector<int> v = { 10, 20, 30, 40, 50 };

	// ⚠️ bind2nd 在 C++11 中已棄用，C++17 中移除
	// for_each(v.begin(), v.end(), bind2nd(Myfunc(), 100));

	cout << "bind2nd 已在 C++17 移除，請使用 lambda 或 std::bind" << endl;
}

// ✅ 修復：使用 std::bind（C++11）
void test01_bind() {
	cout << "\n=== 測試1：std::bind 版本 ===" << endl;
	vector<int> v = { 10, 20, 30, 40, 50 };

	Myfunc func;
	for_each(v.begin(), v.end(), [&func](int val) {
		func(val, 100);  // 手動綁定第二個參數
		});
}

// ============================================================
// 問題3：not1 已棄用
// ============================================================

// ❌ 舊式
/*
struct MyNotfunc : public unary_function<int, bool> {
	bool operator()(int v) const {
		return v >= 20;
	}
};
*/

// ✅ 新式：直接定義
struct MyNotfunc {
	bool operator()(int v) const {
		return v >= 20;
	}
};

void myPrint(int val) {
	cout << val << " ";
}

void test02_old() {
	cout << "\n=== 測試2：舊式 not1（已棄用）===" << endl;
	vector<int> v = { 10, 50, 30, 40, 50 };

	// ⚠️ not1 已棄用
	// auto it = find_if(v.begin(), v.end(), not1(MyNotfunc()));

	cout << "not1 已棄用，請使用 lambda" << endl;
}

// ✅ 修復：使用 lambda
void test02_lambda() {
	cout << "\n=== 測試2：Lambda 版本 ===" << endl;
	vector<int> v = { 10, 50, 30, 40, 50 };

	// 查找 < 20 的元素（not >= 20）
	auto it = find_if(v.begin(), v.end(), [](int v) {
		return !(v >= 20);  // 或直接寫 v < 20
		});

	if (it == v.end()) {
		cout << "查找失敗" << endl;
	}
	else {
		cout << "查找成功 = " << *it << endl;
	}

	// not2 的替代：降序排序
	vector<int> v2 = { 10, 50, 30, 40, 20 };

	// ❌ 舊式：sort(v2.begin(), v2.end(), not2(less<int>()));
	// ✅ 新式：使用 greater 或 lambda
	sort(v2.begin(), v2.end(), greater<int>());  // 降序

	cout << "降序排序結果：";
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}

// ============================================================
// 問題4：ptr_fun 已棄用
// ============================================================

void myprint2(int val, int val2) {
	cout << val + val2 << " ";
}

void test03_old() {
	cout << "\n=== 測試3：舊式 ptr_fun（已棄用）===" << endl;
	// ⚠️ ptr_fun 已棄用
	cout << "ptr_fun 已棄用，請使用 lambda" << endl;
}

// ✅ 修復：使用 lambda
void test03_lambda() {
	cout << "\n=== 測試3：Lambda 版本 ===" << endl;
	vector<int> v = { 10, 20, 30, 40, 50 };

	for_each(v.begin(), v.end(), [](int val) {
		myprint2(val, 100);
		});
	cout << endl;
}

// ============================================================
// 問題5：mem_fun 和 mem_fun_ref 已棄用
// ============================================================

class Maker {
public:
	Maker(string name, int age) : name(name), age(age) {}

	void MyprintMaker() {
		cout << "Name: " << name << " Age: " << age << endl;
	}

	void MyprintMaker() const {  // ✅ 添加 const 版本
		cout << "Name: " << name << " Age: " << age << endl;
	}

	string name;
	int age;
};

void test04_old() {
	cout << "\n=== 測試4：舊式 mem_fun（已棄用）===" << endl;
	cout << "mem_fun 和 mem_fun_ref 已棄用" << endl;
}

// ✅ 修復：使用 lambda 或 std::mem_fn（C++11）
void test04_lambda() {
	cout << "\n=== 測試4：Lambda 版本 ===" << endl;

	// 容器存儲對象
	vector<Maker> v;
	v.push_back(Maker("aaa", 10));
	v.push_back(Maker("bbb", 20));
	v.push_back(Maker("ccc", 30));

	// ✅ 方法1：使用 lambda
	for_each(v.begin(), v.end(), [](Maker& m) {
		m.MyprintMaker();
		});

	cout << "-------------" << endl;

	// 容器存儲指針
	vector<Maker*> vp;
	vp.push_back(new Maker("aaa", 10));
	vp.push_back(new Maker("bbb", 20));
	vp.push_back(new Maker("ccc", 30));

	// ✅ 方法2：使用 lambda
	for_each(vp.begin(), vp.end(), [](Maker* m) {
		m->MyprintMaker();
		});

	// 清理記憶體
	for (auto p : vp) {
		delete p;
	}
}

// ✅ 使用 std::mem_fn（C++11）
void test04_mem_fn() {
	cout << "\n=== 測試4：std::mem_fn 版本 ===" << endl;

	vector<Maker> v = {
		Maker("aaa", 10),
		Maker("bbb", 20),
		Maker("ccc", 30)
	};

	// 使用 lambda 更簡單（推薦）
	for_each(v.begin(), v.end(), [](Maker& m) {
		m.MyprintMaker();
		});
}

// ============================================================
// 完整的現代 C++ 版本
// ============================================================

void test_modern_cpp() {
	cout << "\n========================================" << endl;
	cout << "現代 C++ 版本（推薦）" << endl;
	cout << "========================================" << endl;

	vector<int> v = { 10, 20, 30, 40, 50 };

	// 1. 每個元素加 100 後打印
	cout << "\n1. 每個元素 +100：" << endl;
	for_each(v.begin(), v.end(), [](int val) {
		cout << val + 100 << " ";
		});
	cout << endl;

	// 2. 查找第一個 < 20 的元素
	cout << "\n2. 查找 < 20 的元素：" << endl;
	auto it = find_if(v.begin(), v.end(), [](int val) {
		return val < 20;
		});

	if (it != v.end()) {
		cout << "找到：" << *it << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	// 3. 降序排序
	cout << "\n3. 降序排序：" << endl;
	vector<int> v2 = v;
	sort(v2.begin(), v2.end(), greater<int>());
	for (int val : v2) {  // C++11 range-based for
		cout << val << " ";
	}
	cout << endl;

	// 4. 調用成員函數
	cout << "\n4. 調用成員函數：" << endl;
	vector<Maker> makers = {
		Maker("Alice", 25),
		Maker("Bob", 30),
		Maker("Charlie", 35)
	};

	for_each(makers.begin(), makers.end(), [](Maker& m) {
		m.MyprintMaker();
		});
}

// ============================================================
// 主程序
// ============================================================

int main() {
	cout << "========================================" << endl;
	cout << "C++ 函數適配器修復指南" << endl;
	cout << "========================================" << endl;

	// 舊式寫法（已棄用）
	test01_old();
	test02_old();
	test03_old();
	test04_old();

	cout << "\n========================================" << endl;
	cout << "修復後的版本" << endl;
	cout << "========================================" << endl;

	// 新式寫法
	test01_lambda();
	test02_lambda();
	test03_lambda();
	test04_lambda();
	test04_mem_fn();

	// 現代 C++ 推薦寫法
	test_modern_cpp();

	// 總結
	cout << "\n========================================" << endl;
	cout << "總結：已棄用的函數適配器" << endl;
	cout << "========================================" << endl;
	cout << "\n已棄用（C++11 起）：" << endl;
	cout << "  ❌ binary_function / unary_function" << endl;
	cout << "  ❌ bind1st / bind2nd" << endl;
	cout << "  ❌ not1 / not2" << endl;
	cout << "  ❌ ptr_fun" << endl;
	cout << "  ❌ mem_fun / mem_fun_ref" << endl;

	cout << "\n推薦替代方案：" << endl;
	cout << "  ✅ Lambda 表達式（最推薦）" << endl;
	cout << "  ✅ std::bind（需要時）" << endl;
	cout << "  ✅ std::mem_fn（成員函數）" << endl;
	cout << "  ✅ 直接使用函數對象" << endl;
	cout << "========================================" << endl;

	return 0;
}