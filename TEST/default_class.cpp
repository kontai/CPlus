/*************************
[10/6/2018 22:44
default_class.cpp
*************************/

#include<iostream>

using namespace std;

class Clock {
public:
	Clock(int newH, int newM, int newS) :
		hour(newH), mintute(newH), second(newS) {}
	Clock() {};
	Clock(const Clock &call) {

		hour = call.hour;
		mintute = call.mintute;
		second = call.second;

		cout << "call the copy construct" << endl;
	}
	Clock show(Clock &call2) {
		Clock a;
		a.hour = call2.hour;
		a.mintute = call2.mintute;
		a.second = call2.second;
		cout << call2.hour << ":" << call2.mintute << ":" << call2.second << endl;
	return a;
	}
private:
	int hour, mintute, second;


};

int mainDF() {
	Clock a(22, 10, 40);
	Clock b(a);
	Clock c;

	c=a.show(b);


	system("pause");
	return 0;
}