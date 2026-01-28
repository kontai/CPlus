#include<iostream>
#include<string>

using namespace std;


void func() {

	// Dynamic memory allocation
	auto iarr = new int[20];

	// Initialize the array
	for (int i = 0; i < 20; ++i) {
		iarr[i] = i;
	}

	// Print the array
	for (int i = 0; i < 20; i++)
	{
		cout << iarr[i] << " ";
	}
	cout << endl;
	delete[] iarr; // Free the allocated memory

}


int main() {
	func();
}
