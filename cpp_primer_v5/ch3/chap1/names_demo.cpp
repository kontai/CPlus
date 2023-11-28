#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::string;
	string s="aha:";
	cout<<s;
	getline(cin,s);
	if(!s.empty()){
		cout<<s<<'\n';
		cout<<s.size()<<'\n';
	}

	cout<<"a lo ha"<<endl;
	cout<<"a lo ha"<<endl;
	return 0;
}
