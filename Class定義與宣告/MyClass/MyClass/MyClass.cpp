/*
設計計算立方體體積的類別 MyClass。
*/

#include<iostream>

using namespace std;

class Cube {
public:
	explicit	Cube(double l, double w, double h) : length(l), width(w), height(h) {}
	Cube() : length(1.0), width(1.0), height(1.0) {}
	void setValue(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}

	// 計算立方體體積
	double calcVolume() const {
		//length = 10;	// 錯誤示範: const 成員函式內不可修改成員變數
		return length * width * height;
	}

	// 計算立方體周長
	double calcPerimeter() const {
		return 2 * (length + width + height);
	}

	//比較兩個立方體的體積
	bool cubeCompare(const Cube& cb)const {
		if (this->calcVolume() == cb.calcPerimeter() && this->calcPerimeter() == cb.calcPerimeter())
		{
			return true;

		}
		else
		{
			return false;
		}
	}
private:
	double length;
	double width;
	double height;
};

int main() {
	Cube cube = Cube(2.3, 3.4, 4.5);
	cout << "立方體面積: " << cube.calcVolume() << endl;
	cout << "立方體周長: " << cube.calcPerimeter() << endl;

	Cube cube2 = Cube(2.3, 3.4, 4.5);
	cout << "兩立方體是否相等: " << (cube.cubeCompare(cube2) == 0 ? "相等" : "不相等") << endl;



	return 0;
}