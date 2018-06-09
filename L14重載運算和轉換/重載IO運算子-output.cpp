/****************************************
[5/22/2017  21:15]
重載IO運算子.cpp
****************************************/

#include<iostream>
#include <vector>
#include<string>

using namespace std;
/*
 *格式: ostream& operator<<(ostream& , const class-member&)
 * 通常不會列印換行字元,為了讓用戶可以在同一行列印其他描述文字
 * 
 * IO重載運算子須為non-member函式
 * //如果operator<<為Mem的一個成員
 *	 Mem item;
 *	 Mem<<cout; (用法太奇怪,而且和output運算子正規用法相反)
 * 
 * 而因為常常需要尋訪class private物件.所以必須為IO運算子設為友元(friend)
 */
class CheckoutRecord
{
public:
	friend ostream& operator<<(ostream&, const CheckoutRecord&);
	friend class Date;
	
	//.....
private:
	double book_id;
	string title;
	pair<string, string>borrower;
	vector< pair<string, string >*>wait_list;
};


ostream& operator<<(ostream& out,const CheckoutRecord& ck){
	out << ck.book_id << "\t" << ck.title << endl;

	//vector 和 pair 容器無output運算子,所以要自已設計,以迴圈逐個輸出
	for(vector< pair<string,string> * >::const_iterator iter=ck.wait_list.begin();
		iter!=ck.wait_list.end();iter++)
	{
		out << (*iter)->first << "\t" << (*iter)->second << endl;
	}
	return out;
}
int mainIO_Output(){



system("pause");
return 0;
}