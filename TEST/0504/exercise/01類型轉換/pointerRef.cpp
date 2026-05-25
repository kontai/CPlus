#include <iostream>

using namespace std;

void f01() {
	int a = 10;
	int* p = &a;
	int*& q = p;
}

void f02() {
	int a = 10;
	int* const p = &a;
	int*& q = p;
}
void f03() {
	int a = 10;
	const int* p = &a;
	int*& q = p;
}

void main() {
	f01();



}