/*************************
[15/7/2018 10:47
cr.cpp
*************************/

#include<iostream>
#include<string>
#include<bitset>
#include<Windows.h>
#include<MemoryBuffer.h>

using namespace std;

string get(const string &ss){ 
	string::size_type len = sizeof(ss);
	string *p = new string(ss);
	return *p;
}
class Line {
public:
	Line() {}
	Line(Line &a) {
		int i = 1;
		/*while (i<100) {
			Sleep(3000);
			int *p = (int*) malloc(1024*1024);
			i++;
			cout << 100-i << endl;
		}*/
		str = ::get(a.str);
		cout << "calling class point constructor" << endl;
	}
	Line(int a, const string &s) :code(a), str(s) {}
	~Line() {
		cout << "Deleting" << endl;;
	}


	void get() {
		cout << str << endl;
	}

private:
	int code;
	string str;
};

int main123() {
	Line a(2, "new");
	Line b(a);
	b.get();
	Line *pt=new Line(a) ;
	pt = &a;
	pt->get();

	system("pause");
	return 0;
}