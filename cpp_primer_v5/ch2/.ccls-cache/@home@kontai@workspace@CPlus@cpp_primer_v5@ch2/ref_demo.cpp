#include <iostream>

int main(int argc, char *argv[])
{
	double  d1=3.14;
	// 	int d=2;
	// 	int &j=23;
	const int &i=d1;
	int i2=23;
	const int *p=&i2;
	// 	*p=10;
	const int *i3=&i2;
	int *const i4=&i2;
	const int *const i5=&i2;
// 	*i5=1;
	return 0;
}
