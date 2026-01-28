#include"myNS.h"

int main() {
	MyNamespaceA::func();

	// Call the global namespace function
	func();
	MyNamespaceA::ma = 20;
	return 0;
}