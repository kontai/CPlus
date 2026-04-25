#include<iostream>
#include<vector>

using namespace std;

//定義一個名為NoDefault的類，它有一個接受int的構造函數，但是沒有默認構造函數
//定義一個類C，C有一個NoDefault類型的成員，定義c的默認構造函數

class NoDefault {
public:
	NoDefault(int a):val(a) {
		cout << "NoDefault(int) is called." << endl;
	};
	int val;
};

class C {
public:
	C(int val=0) :nd(val) {};
	int get() {
		return nd.val;
	}
private:
	NoDefault nd;
};

int main() {
	C c1;
	cout << c1.get() << endl;

	//exercise 7.44
	//vector<NoDefault> vec(10);	//無默認構造函數 

	//exercise 7.44
	vector<C> vecC(10);


	
}