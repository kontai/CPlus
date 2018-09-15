/*************************
[12/8/2018 17:31
Âà´«¹Bºâ¤l.cpp
*************************/

#include<iostream>

using namespace std;

class Source {
public:
	Source(int i = 0) :val(i) {
		if (i < 0||i>255)
			throw out_of_range("Bas Source Initializer");
	}

	operator int() { return val; }

private:
	size_t val;

};

void take(Source it) {
	cout << it << endl;
}

int main(){
	Source a(2);
	cout << a << endl;

	int i = 22;
	take(i);

	system("pause");
	return 0;
}