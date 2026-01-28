#include<iostream>
#include<string>

using namespace std;

class Mark {
public:
		Mark() {
	}
	explicit Mark(int a) {
		this->a = a;
	}
	~Mark() {
	}
private:
	int a;
};

void func() {
	Mark m1(20);
	//Mark m2 = 30;	// 編譯錯誤, 因為explicit禁止隱式轉換
}

int main() {
	func();
}