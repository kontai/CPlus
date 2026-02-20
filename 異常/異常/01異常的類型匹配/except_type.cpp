#include <iostream>
using namespace std;

int f01() {
		//throw 10;
	//throw 2.3;
	throw 'a';	//char，無法匹配int,double,會報錯,使用"..."匹配所有錯誤;
}


void e01() {
	try {
		f01();
	}
	catch (int e) {
		cout << "catch int except  : "<<e << endl;
	}
	catch (double d) {
		cout << "catch double except : " << d << endl;
	}
	catch (...) {
		cout << "catch all except" << endl;
	}
}



int main() {
	e01();
	return 0;
}