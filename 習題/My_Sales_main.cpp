#include<iostream>
#include "My_Sales.h"

using namespace std;

int mainMysales() {
	My_Sales item, total, trans;
	//cout << "ISBN=>" << endl;
	//while (item.input(cin))
	//	item.output(cout);
	if (item.input(cin)) {
		while (trans.input(cin)) {
			if (item.same_isbn(trans)) {
				item.add(trans);
			}
			else {
				item.output(cout);
				item = trans;
			}
			total.output(cout);
		}
	}
	else {
		cout << "No Data!?" << endl;
		return -1;
	}

	system("pause");
	return 0;
}