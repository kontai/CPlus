#include <iostream>
#include<string>
#include <map>
#include <vector>

using namespace std;

typedef  multimap<vector<string>, vector<int> > IMap;
int main()
{
	vector<string>vs;
	vector<int>vin;
	IMap d;
	string ist;
	int in;
	while(cin>>ist>>in)
	{
		vs.push_back(ist);
		vin.push_back(in);
		d.insert( make_pair(vs, vin));
	}

	IMap::iterator im=d.begin();

	while(im!=d.end())
	{
		cout <<  im->first << ' ' << im->second << endl;
		im++;
	}
	
	

	system("pause");
	return 0;
}