#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[])
{
	string s;
	char ch;
	int is_space=0;
	while((ch=getchar())!='\n')
	{
		/* 1
		   if(ch!=' ')
		   s+=ch;
		   */


		if(is_space==0)
		{
			if(ch!=' ')
			{
				s+=ch;
			}
			else
			{
				s+=' ';
				is_space=1;
			}

		}else
		{
			if(ch!=' ')
			{
				s+=ch;
				is_space=0;
			}
		}

	}

	cout<<s<<endl;
	return 0;
}
