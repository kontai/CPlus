#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	int i=42,j=22;
	int &r=i;

	// cstdlib 
	int *p1=nullptr;
	int *p2=(int *)0;
	int *p3=NULL;

	int *p;
	p=&i;
	*p=i;
	int &r2=*p;
	r2=20;
	std::cout << i << std::endl;
//error : can't change refer
// 	&r=j;
	return 0;
}
