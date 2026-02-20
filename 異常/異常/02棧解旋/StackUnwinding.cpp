#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

/*
棧解旋的運作流程
想像以下的呼叫順序：main() 呼叫了 FuncA()，FuncA() 呼叫了 FuncB()。

正常執行：FuncB() 裡面建立了一些 Stack 上的變數（例如 std::string 或自定義的物件）。

引發例外：FuncB() 執行到一半，發生了錯誤，執行了 throw std::runtime_error("Error!");。

開始尋找 Catch：

FuncB() 內部沒有 catch 可以處理這個錯誤。

程式被迫要提早離開 FuncB()，退回到 FuncA()。

【棧解旋發生】：在離開 FuncB() 之前，C++ 編譯器會介入，把 FuncB() 裡面所有活著的 Stack 物件，全部呼叫一次解構子。

繼續向外退：退回到 FuncA() 後，發現 FuncA() 也沒有 catch。於是再次發生棧解旋，把 FuncA() 裡的 Stack 物件也全部解構。

停止解旋：直到退回 main()，發現了一個 catch 區塊把這個錯誤接住了。解旋停止，程式繼續執行 catch 區塊內的代碼。
*/

// 建立一個測試類別，用來觀察生命週期
class TestObj {
public:
	TestObj(string n) : name(n) {
		cout << "[建構] " << name << " 已經建立。" << endl;
	}

	~TestObj() {
		cout << "[解構] " << name << " 已經銷毀！(棧解旋發威)" << endl;
	}
private:
	string name;
};

// 一個會引發錯誤的危險函數
void dangerFunction() {
	TestObj obj1("區域物件 1");
	TestObj obj2("區域物件 2");

	cout << "  -> 準備拋出例外 (Throw Exception)..." << endl;

	// 模擬發生錯誤，拋出例外。此時函數將被迫強制中斷。
	throw runtime_error("系統崩潰啦！");

	// 注意：下面這幾行代碼「永遠不會」被執行到
	TestObj obj3("區域物件 3");
	cout << "  -> dangerFunction 順利結束。" << endl;
}

int main() {
	cout << "--- 進入 try 區塊 ---" << endl;

	try {
		dangerFunction();
		// 如果 dangerFunction 拋出例外，這行也不會被執行
		cout << "--- 準備離開 try 區塊 ---" << endl;
	}
	catch (const exception& e) {
		// 程式執行流程會直接跳躍到這裡
		cout << "--- 進入 catch 區塊 ---" << endl;
		cout << "捕獲例外原因: " << e.what() << endl;
	}

	cout << "--- 程式安全復原，繼續執行 ---" << endl;

	return 0;
}