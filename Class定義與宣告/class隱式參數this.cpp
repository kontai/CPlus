/****************************************
[4/4/2017  20:49]
class隱式參數this.cpp
****************************************/

#include<iostream>

using namespace std;

//*this : 指向CLASS物件的point , 綁定於成員函式呼叫者上

//當呼叫成員函式,希望返回是物件參考(*this)
class Screen {
public:
	typedef string::size_type index;
	Screen get();
	void get(char);
	Screen move(index, index, char);

	//nonconst成員函式,this為const指標(p.126),可改變this所指物件,但不可改變this所指位址
	//Rback& bi(char);
	//const成員函式,this所指物件以及位址都不可改變

private:
	string contenes;
	index cursor;
	index width, lenth;
};

void Screen::get(char ch) {
	cout << ch << endl;
}

int mainvis() {
	Screen myscreen;
	myscreen.get('a');
	system("pause");
	return 0;
}