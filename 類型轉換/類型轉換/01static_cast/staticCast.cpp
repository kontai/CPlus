#include<iostream>

using namespace std;

//C++的顯示類型轉換,
// 1. static_cast: 靜態類型轉換, 強制轉換, 安全性較高, 但不會造成類別的隱式轉換,開發者必須確定轉換後的類別是否有必要的成員
//	用途：
//		1)數值轉換
//		2)向下轉型（你保證安全,對自己負責）
//		3)void* 轉型
//		4)enum 轉 int
// 2. dynamic_cast: 動態類型轉換, 強制轉換, 安全性較低, 可能造成類別的隱式轉換
// 3. const_cast: 常數類型轉換, 移除常數性, 安全性較高, 但不會造成類別的隱式轉換
// 4. reinterpret_cast:  reinterpret_cast: 重新對齊, 安全性較低, 可能造成類別的隱式轉換
//靜態類型轉換
class B {
public:
	int a;
};

class D : public B {
public:
	int b;

};

void f(B* pb, D* pd) {
	D* pd2 = static_cast<D*>(pb);   // Not safe, D can have fields
	// and methods that are not in B.
	pd2->b;

	B* pb2 = static_cast<B*>(pd);   // Safe conversion, D always
	pb2->a;
	// contains all of B.
}

//動態類型轉換
void f01() {
	B* b = new B();
	D* d = new D();
	f(b, d);
	delete b;
	delete d;
}


void f02() {
	int i = static_cast<int>(3.14);
	cout << "i: " << i << endl;
}

void f03() {
	D* dp = new D();
	B* bp = static_cast<B*>(dp);
	bp->a = 10;
	cout << "bp->a:  " << bp->a << endl;

	B* bp2=new B();
	D* dp2 = static_cast<D*>(bp2);	//static_cast 不做執行期檢查;向上轉型,自已要確保安全。
}
int main() {
	//f01();
	//f02();
	f03();

	return 0;
}