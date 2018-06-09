#include<iostream>
#include<vector>
#include<string>
#include <iterator>


using namespace std;

int mainExam11_3_3()
{
	vector<string> vst;
	string str;
	while (getline(cin,str))
	{
		vst.push_back(str);
	}
	/*vector<string>::reverse_iterator ristr=vst.rbegin();
	while(ristr!=vst.rend())
	{
		cout << *ristr << endl;
		ristr++;
	}
*/
	vector<string>::iterator ivst = vst.end() ;
		ivst--;
	while(ivst>=vst.begin())
	{
		cout << *ivst << endl;
		ivst--;
	}


	system("pause");
	return 0;
}