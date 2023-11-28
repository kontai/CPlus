#include <iostream>

int j=22;
constexpr int *q=nullptr;
// q=&j;


int main(int argc, char *argv[])
{
	constexpr const int cj=10;
// 	constexpr const *p2=&cj;
	int i=10;
	const int *p=&i;
// 	*p=2;
//
//
	int null=0,*p=(void*)null;
	return 0;
}
