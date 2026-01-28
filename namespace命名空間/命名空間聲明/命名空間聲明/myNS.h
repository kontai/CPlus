#ifndef MYNS_H
#define MYNS_H

#include <iostream>

namespace MyNamespaceA {
	//int ma;	//定義在此會造成重複定義錯誤
	extern int ma; 

	void func();
}

namespace MyNamespaceB {
	void func();
}

	void func();

#endif
