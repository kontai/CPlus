#include<iostream>
#include<string>
#include <list>
#include <vector>

using namespace std;

/*
  c.push_bask(t)		添加t值到容器c的尾端,返回void
  c.push_front(t)		添加t值到容器c的尾端,返回void
  c.insert(p,t)			在iterator p所指位置之前端插入t值元素,返回一個iterator指向新添加的元素
  c.insert(p,n,t)			在iterator p所指位置之前端插入n個t值元素,返回void
  c.insert(p,b,e)			在iterator p所指位置之前端插入iterator b 和 e所表示的區間元素,返回void

//push_front()=>vector不支援
 */
int mainInsertErase() {
	string word;
	vector<string> ivec;
	vector<string>::iterator first = ivec.begin(), last = ivec.end();
	while (cin >> word)					//利用insert()持續在容器前端添加元素
	{
		first = ivec.insert(first, word);		//效果等同push_front()   利用insert()取代vector不支援的push_front()
		cout << *first << "  " << &first << endl;
	}
	/*
		while(first!=last)
		{
			first = ivec.insert(first, "abc");  //insert新元素,會使原本保存的end位置失效,造成無窮迴圈
			first++;
		}
	*/
	int i = 0;
	while (first != ivec.end())			//每次回圈刷新容器末尾,避免保存固定的末尾位置,造成死循環
	{
		cout << ivec.front() << '\t' << ivec.size() << endl;
		first = ivec.insert(first, "abc");
		first += 2;
	}
	system("pause");
	return 0;
}