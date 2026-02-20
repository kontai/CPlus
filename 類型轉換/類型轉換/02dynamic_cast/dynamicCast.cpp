#include <iostream>
#include <string>
using namespace std;;
/*dunamic_cast
* 在執行期 (Run-time) 運作的。它專門用於具備多型 (Polymorphism
*即含有虛擬函數 virtual 的類別) 的繼承體系中，進行安全的「向下轉型 (Downcasting)」。
* 如果失敗：
*		指標會變成 nullptr
*		參考型別會丟出 bad_cast
*/

class Base { virtual void dummy() {} }; // 必須有虛擬函數
class Derived : public Base { public: void doSomething() {} };

void process(Base* b) {
	// 在執行期檢查 b 到底是不是 Derived 的實體
	if (Derived* d = dynamic_cast<Derived*>(b)) {
		d->doSomething(); // 轉換成功，安全呼叫
		cout << "process. ok" << endl;
	}
	else {
		// 轉換失敗，b 其實是指向別的子類別
		cout << "process. abort" << endl;
	}
}
int main() {
	Base* base = new Base();
	process(base);

	Base* base2 = new Derived();
	process(base2);

	return 0;
}