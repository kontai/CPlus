/*************************
[23/7/2018 7:01
Source.cpp
*************************/

#include<iostream>

using namespace std;



class Shape{
public:
	Shape(){}
	~Shape() {};
	 virtual float GetArea() { return -1; };
	 virtual void show() = 0;
private:
	int height, width;

};

class Circle :  public Shape {
public:
	Circle(float raius):isRadius(raius){}
	float GetArea() {
		return 3.14*isRadius*isRadius;
	}

	virtual void show() {
		cout << "In Circle class" << endl;
	}
	~Circle() {};
private:
	float isRadius;

};

class Rectangle :  public Shape{
public:
	Rectangle(float x, float y) :height(x), width(y) {};
	float GetArea() {
		return height * width;
	};
	virtual void show() {
		cout << "In Rectangle class" << endl;
	}
	~Rectangle() {};
	protected:
	float height, width;
};

class Square :public Rectangle {
public:
	Square(float len): Rectangle(len, len)  {}
	~Square() {};
	float GetArea() {
		return Rectangle::height* Rectangle::width;
}
	virtual void show() {
		cout << "In Rectangle class" << endl;
	}
};

int mainShape(){
	Shape *p;
	p = new Circle(23.4);
	p->show();
	cout<<p->GetArea()<<endl;

	delete p;
	p = new Rectangle(23, 44);
	cout << p->GetArea() << endl;
	delete p;

	p = new Square(2.3);
	cout << p->GetArea() << endl;
	

	system("pause");
	return 0;
}
