#include<iostream>
#include<string>

using namespace std;

void init_demo() {
	string s1;                  // 預設建構：空字串 ""
	string s2 = "Hello";        // 從 C-style 字串建構
	string s3("C++");           // 另一種常見寫法
	string s4(5, 'A');          // 填充建構："AAAAA" (常用於初始化特定長度的緩衝區)
	string s5 = s2;             // 拷貝建構 (深拷貝)
}

void fun1() {
	string s = "Hello World!";
	s.size(); // 12
	s.length(); // 12
	s.capacity(); // 15
	cout << s.capacity() << endl;
	s.reserve(32);	// 調整容量
	cout << s.capacity() << endl;
}

void fun2() {
	string s = "Hello World!";
	//s[200];
	//s.at(200);	// at() 比 [] 更安全，會檢查索引是否合法
	cout << s.front() << endl;	// 取得字串第一個字元
	cout << s.back() << endl;	// 取得字串最後一個字元
	s.back() = 'X';	// 修改字串
	cout << s << endl;
	s.clear();	// 清空字串
}

void fun3() {
	string s = "Hello";
	s += " World";         // "Hello World"
	s.insert(5, " C++");   // "Hello C++ World"
	s.erase(0, 6);         // "C++ World" (從 index 0 刪除 6 個字元)
	s.replace(2, 4, "Java"); // "C+Javarld" (從 index 2 開始替換 4 個字元)
	cout << s << endl;
}

void fun4() {
	string str = "user@domain.com";
	size_t pos = str.find("@");

	if (pos != string::npos) {
		// 找到了！切出使用者名稱
		string user = str.substr(0, pos);
	}
}

int main()
{
	//init_demo();
	//fun1();
	//fun2();
	fun3();
	//fun4();
	return 0;
}