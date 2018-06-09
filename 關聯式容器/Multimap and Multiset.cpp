#include<iostream>
#include <map>
#include<string>

using namespace std;


int main()
{
	multimap<string, string>author;
	author.insert(multimap<string,string>::value_type("Barth John", "Sot-Weed"));
	author.insert(make_pair("Barth John", "Lost in the Fun house"));
	
	
	//int erase_count = 0;
	//erase_count = author.erase("Barth John");   //erase()返回刪除key中所含元素個數
	//cout << erase_count << endl;

	//如何找出key裡所有值??
	//方式一 利用count() , find()
	typedef multimap<string, string>::size_type author_count;
	author_count ac = author.count("Barth John");
	multimap<string, string>::iterator ai = author.find("Barth John");
	for(author_count i=0;i!=ac;i++,ai++)
		cout << ai->second << endl;

	//方式二   利用multimap & multiset 專屬區間控制 lower_bound,upper_bound 
	//如果key不存在,lower_bound會指向比指定key大的第一個元素,所以此時lower_bound與upper_bound相同
	typedef multimap<string, string>::iterator author_it;
	author_it beg = author.lower_bound("Barth John");  
	author_it end = author.upper_bound("Barth John");
	while(beg!=end)
	{
		cout << beg->second << endl;
		beg++;
	}

	//方式三 利用equal():lower_bound與upper_bound結合體;返回值為key第一個元素及key最後一個元素
	pair<author_it, author_it>eq_search = author.equal_range("Barth John");
	while(eq_search.first!=eq_search.second)
	{
		cout << eq_search.first->second << endl;
		++eq_search.first;
	}

	system("pause");
	return 0;
}