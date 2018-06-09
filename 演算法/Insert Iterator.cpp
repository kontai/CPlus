#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

/************************************************************************/
/*                                                                      */
/*back_inserter(con) :於內部使用push_back();
/*front_inserter(con) :於內部使用push_front();
/*inserter(con,where)使用 insert 實現插入操作。除了所關聯的容器外，inserter 還帶有第二實參：指向插入起始位置。
/************************************************************************/
int mainInsert_front_back() {
	// position an iterator into ilst
	vector<int>ivec;
	list<int>ilstA;
	list<int>::iterator it = find(ilstA.begin(), ilstA.end(), 42);
	// insert replaced copies of ivec at that point in ilst
	replace_copy(ivec.begin(), ivec.end(), inserter(ilstA, it), 100, 0);
	//調用 replace_copy 的效果是從 ivec 中複製元素，並將其中值為 100 的元素替換為 0 值。ilst 的新元素在 it 所標明的元素前面插入。
	list<int> ilst, ilst2, ilst3;    // empty lists
	// after this loop ilst contains: 3 2 1 0
	for (list<int>::size_type i = 0; i != 4; ++i)
		ilst.push_front(i);
	// after copy ilst2 contains: 0 1 2 3
	copy(ilst.begin(), ilst.end(), front_inserter(ilst2));
	// after copy, ilst3 contains: 3 2 1 0
	copy(ilst.begin(), ilst.end(), inserter(ilst3, ilst3.begin()));

	system("pause");
	return 0;
}