#include"myNS.h"

using namespace std;

int MyNamespaceA::ma = 10; // Define and initialize ma
void MyNamespaceA::func()
{
	cout << "hello from mySpaceA" << endl;
 ma = 20;
	cout << "ma in MyNamespaceA: " << ma << endl;
}

void MyNamespaceB::func() {
	cout << "hello from mySpaceB" << endl;
}

void func() {
	cout << "This is a function in the global namespace." << endl;
}

