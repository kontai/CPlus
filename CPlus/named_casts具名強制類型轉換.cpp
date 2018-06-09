#include <iostream>
#include<vector>
#include <string>

using namespace std;

//static_cast	一般的類型強轉 exp: int to double , float to char ...etc.
//const_cast	常數指標互轉
//reinterpret_cast
//強制轉換能不用就不要使用,一旦發生錯誤,不易找(強轉等於關閉編譯器類型轉換的提醒)

int mainCast() {
	//	int ival;
	//	double dval;
	//	const string *ps;
	//	char *pc;
	//	void *pv;
	//	pv = static_cast<void*>(const_cast<string*>(ps));	   			//pv = (void*)ps;
	//	ival = static_cast<int>(*pc);														 //ival=int(*pc)
	//	pv = static_cast<void*>(&dval);												//pv=&dval;
	//	pc = static_cast<char*>(pv);														//pc=(char*) pv;
	system("pause");

	return 0;
}