#include <iostream>


int main(int argc, char *argv[])
{
	int i,&ri=i;
	int j=2,&rj=j;
	ri=rj;
	i=5;
	ri=10;

	std::cout << i << " "<<ri<<std::endl;

	return 0;
}
