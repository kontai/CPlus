/****************************************
[6/3/2017  08:46]
重載函數調用操作符-2.cpp
****************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename elementMulti>
class IsMulitple
{
public:
	IsMulitple(const elementMulti& add)
	{
		ele_Number = add;
	}
	bool operator()(const elementMulti& get_num){
		return ((get_num%ele_Number) == 0);
	}
private:
	elementMulti ele_Number;

};

int main_一元(){
	vector<int> ivec;
	for (vector<int>::size_type i = 1;i <= 100;i++)
		ivec.push_back(i);
	IsMulitple<int> a(3);

	vector<int>::iterator itv=find_if(ivec.begin(), ivec.end(), a);
	cout << "被3整除的第一個數字" << *itv << endl;



	



system("pause");
return 0;
}