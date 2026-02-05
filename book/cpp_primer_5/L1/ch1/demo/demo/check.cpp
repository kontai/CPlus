#include<iostream>


int main_check() {
	char a = 0;
	if (std::cin >> a)
		a = 't';
	else
		a = 'f';
	std::cout << "a = " << a;
	if (std::cin >> a)
		a = 't';
	else
		a = 'f';
	std::cout << "a = " << a;

	return 0;
}