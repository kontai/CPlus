#include<iostream>
#include<vector>
#include <list>
#include <deque>

using namespace std;

int main容器() {
	vector<int>vec(10, 2);
	vector<int>::iterator iter = vec.begin() + vec.size() / 2;
	vector<int>::reverse_iterator	riter = vec.rbegin();  //riter 指向vec最後一個元素

	list<int>ilist(vec.begin(), vec.end());
	//區間表示(first,last)
	//ilist元素為[vec.begin()] first 開始,直到[vec.end()] lastt 結束	(不包括vec.end())
	 //有效區間條件:必須為同一容器 , first一定要在last之前

	//ilist.begin() + ilist.size() / 2;	//錯誤,list iterator不允許作加減法(+ , - )及關係運算(>= , < , <= , >)
														//只支援前,後置++ , -- ,以及== , !=
	system("pause");
	return 0;
}