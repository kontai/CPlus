#include <iostream>

std::string global_str;
int global_int;

int main(int argc, char *argv[])
{
	int local_int;
	std::string local_str;
	extern int jj;

	std::cout<<local_int<<'\n';
	std::cout<<local_str<<'\n';
	int 1_or_2=1; 	//unqualiried-id
			
	double Double = 3.14;
	return 0;
}
