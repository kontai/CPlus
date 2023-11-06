#include <iostream>

int main(int argc, char *argv[])
{
	int i=0 , &r1=i;
	double d=0 , &r2=d;

	// (a)
	r2=3.14159;

	//(b)
	r2=r1;

	//(c)
	i=r2;

	//(d)
	r1=d;
	std::cout << "i = "<< i << std::endl;
	std::cout << "r1 = "<< r1 << std::endl;

	return 0;

}
