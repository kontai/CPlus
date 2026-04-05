#include<iostream>

using namespace std;

// 父類指向子類對象
class Parent {
public:
	virtual void show() {
		cout << "Parent show" << endl;
	}
	virtual ~Parent() = default;
};
class Child : public Parent {
public:
	virtual 	void show() override {
		cout << "Child show" << endl;
	}
};

//void func() {
//	const Parent& p = Child(); // 父類引用指向子類對象
//	p.show();
//}

void func2() {
	Parent* p = new Child();
	Parent*& rp = p;
	rp->show();
	delete rp;
}

void func3() {
	/*
	1. 創建 Child 臨時對象（完整）
	2. 調用 Parent 的拷貝構造函數
	3. 只複製 Parent 部分
	4. Child 部分被「切掉」
	5. p 是純粹的 Parent 對象
	*/
	Parent  p = Child();	 // 父類對象切割，實際上是創建了一個 Parent 對象，Child 的部分被切掉了
	p.show();
}

int main() {
	func2();
	func3();
	return 0;
}