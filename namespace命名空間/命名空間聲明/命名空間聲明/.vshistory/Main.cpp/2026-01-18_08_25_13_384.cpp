#include"myNS.h"

int main() {
	MyNamespaceA::func();

	// Call the global namespace function
	func();
	return 0;
}