#include <iostream>


int main(int argc, char *argv[])
{
	int i=0;
	int *const p1=&i;
	const int c1=42;
	const int *p2=&c1;
	const int *const p3=p2;
	const int &r=c1;

	i=c1;
	p2=p3;

// 	int *p= p3;
	
	constexpr int mf=23;
	constexpr int jj=i*2;

	return 0;
}
