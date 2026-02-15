#include<iostream>

using namespace std;

// 父類指向子類對象
class Parent {
public:
	virtual void show() {
		cout << "Parent show" << endl;
	}
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
	Parent  p = Child();	 // 父類對象切割，實際上是創建了一個 Parent 對象，Child 的部分被切掉了
	p.show();
}

int main() {
	//func2();
	func3();
	return 0;
}