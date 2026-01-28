#include"myNS.h"

int main() {
	MyNamespaceB::func();
	MyNamespaceA::func();

	// Call the global namespace function
	func();
	return 0;
}