#include<iostream>


int main_demo_1_12() {

	int sum = 0;
	int j = 0;
	for (int i = -100; i <= 100; i++) {
		sum += i;
		if (j % 10 == 0)
			std::cout << "i= " << i << "sum= " << sum << std::endl;
		j++;
	}

	return 0;
}