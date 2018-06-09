/****************************************
[4/4/2017  09:20]
class重載.cpp
****************************************/
/*
 * class重載的作用只對同一class內的成員函式有效;與外部的非成員函式或一般函式彼此不相干
 *
 */
#include<iostream>
#include<string>

using namespace std;
class Screen {
public:
	typedef string::size_type index;
	char get()const {
		return content[cursor];
	}
	char get(index wd, index ht)const {
		cout << wd << '\t' << ht << endl;
		return 'a';
	}
private:
	string content;
	index cursor;
	index width, hight;
};

int mainClassOverload() {
	Screen myscreen;
	char ch;
	ch = myscreen.get(0, 0);

	system("pause");
	return 0;
}