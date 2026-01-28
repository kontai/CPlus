#include"myNS.h"

using namespace std;

void MyNamespaceA::func()
{
	cout << "hello from mySpaceA" << endl;
	MyNamespaceA:: ma = 20;
	cout << "ma in MyNamespaceA: " << ma << endl;
}

void MyNamespaceB::func() {
	cout << "hello from mySpaceB" << endl;
}

void func() {
	cout << "This is a function in the global namespace." << endl;
}

