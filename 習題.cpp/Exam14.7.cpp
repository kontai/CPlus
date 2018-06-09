/****************************************
[6/3/2017  18:11]
Exam14.7.cpp
****************************************/

#include<iostream>
#include <vector>

using namespace std;

class CheckedPtr
{
public:
	CheckedPtr(int *a,int *b):beg(a),end(b),cur(a){ }
	CheckedPtr& operator++(){
		if (cur == end)
			throw out_of_range ("increment past the end of CheckedPtr");
			++cur;
		return *this;
	}

	CheckedPtr& operator--() {
		if (cur == beg)
			throw out_of_range("increment past the end of CheckedPtr");
		--cur;
		return *this;
	}
	CheckedPtr operator++(int){
		CheckedPtr ori(*this);
		++*this;
		return ori;
	}
	CheckedPtr operator--(int){
		CheckedPtr ori(*this);
		--*this;
		return ori;
	}
	////////////////////////////////

	CheckedPtr( int* a)
	{
		size_t size = sizeof(a) / sizeof(int);
		if (a)
				cur = a;
	}

	int& operator*(){
		if (cur == end)
			throw out_of_range("¶V¬É");
		return *cur;
	}

	int operator=(CheckedPtr const& num){
		return *cur;
	}

	int* operator[](size_t index)
	{
		if (beg + index > end)
			throw out_of_range("invalid index");
		return beg + index;
	}

int* operator[](const size_t index)const
	{
		if (beg + index > end)
			throw out_of_range("invalid index");
		return beg + index;
	}
	

private:
	int *beg, *end,*cur;
	int ss;
};

int mainExam14_7(){
	int a[20] = { 5 };
	CheckedPtr pi(a);

	int *s = pi[5];
	cout << *s;
	



system("pause");
return 0;
}