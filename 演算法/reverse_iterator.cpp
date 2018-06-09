#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int mainReverse_iterator()
{
	vector<int>vec;
	for (vector<int>::size_type i = 0;i != 10;++i)
		vec.push_back(i);
	
	// reverse iterator of vector from back to front  
	vector<int>::reverse_iterator r_iter;     
	for (r_iter = vec.rbegin();r_iter != vec.rend();  ++r_iter)
// binds r_iter to last element  ;  vec.rbegin()=vec最後一個元素
//rend refers 1 before 1st element  vec.rend()=vec第一個元素的前一個位置
// decrements iterator one element   reverse_iterator+1 
//指標就會往前一個位置,直到rbegin   

		cout << *r_iter << endl;  
	// prints 9,8,7,...0 

///////////////////////////////////////////////////////////////////////////////////

	//find   first word before the comma
	string str = "abc,def,ghi";
	string::iterator comma = find(str.begin(), str.end(), ',');
	cout << string(str.begin(), comma) << endl;

	string::reverse_iterator rcomma = find(str.rbegin(), str.rend(), ',');
	cout << string(str.rbegin(), rcomma)<<endl; 
	cout << string(rcomma.base(),str.end() )<<endl; 
	//base()是每個reverse_iterator型別都具備的成員函式
	// [str.rbegin,rcomma] 和 [rcomma.base(),str.end()]為相同區間
	//但rcomma.base 與 rcomma 所指位置不同(就如str.end()與str.end())


	system("pause");
	return 0;
}