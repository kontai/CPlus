/****************************************
[4/16/2017  16:20]
class1.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Screen
{
	typedef string::size_type index;
public:
	char get()const;
	const char get(index , index)const ;

	inline Screen& set(char);
	inline Screen& move(index, index);
	 Screen& display(ostream &os)
	 {
		 do_display(os); return *this;
	 }
	 const Screen& display(ostream &os)const
	 {
		 do_display(os);return *this;
	 }

Screen(index wd,index ht,const string& str):content(str),cursor(0),width(wd),height(ht){ }

private:
	string content;
	index cursor;
	index width, height;
	void do_display(ostream &os)const {
		os << content << endl;
	}
};

inline char Screen::get()const
{
	return content[0];
}

	inline const char Screen::get(index x, index y)const
{
		index width = x*this->width;
		return content[width];
}

	Screen& Screen::set(char ch)
{
		content[cursor] = ch;
		return *this;
}

	Screen& Screen::move(index x,index y)
{
		index wid = y*height;
		cursor = x + wid;
		return *this;
}




int mainExam12_13(){
	Screen myscreen(7, 7, "abcdef\nghijkl\nmnopqr\n");
	cout << myscreen.get() << endl;
	cout << myscreen.get(1,2) << endl;
	myscreen.display(cout);
	myscreen.move(1,1).set('#').move(1,2).set('%').display(cout);


system("pause");
return 0;
}