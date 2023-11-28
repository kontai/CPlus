#include <iostream>

int main(int argc, char *argv[])
{
	int i=42,*p=&i,&r=i;	
	decltype(r+0)b;
	decltype(p)c;
	auto d=p;
	std::cout <<*d  << std::endl;

	// 加括號,變量是一種可以作為賦值語句左值的特殊表達式
	decltype((i))d;
	return 0;
}
