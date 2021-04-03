/*
*	01
*	2021/03/27
*
*/

#if 0

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
template<class T>
void Plusfunc(T a, T b) {
	cout << "函數模板調用" << endl;
	//return a + b;
}

//函式重載
void Plusfunc(int a, int b) {
	cout << "重載函式被調用" << endl;
}

void Plusfunc2(int a, int b) {
	cout << "普通函數調用" << endl;
	//return a + b;
}

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns></returns>
int main() {
	int a = 3;
	int b = 4;
	char c = 5;
	char d = 6;

	//當有函數重載,會掉用普通函數
	Plusfunc(a, b);

	//強制調用函數模板
	Plusfunc<>(a, b);

	//編譯器會優化調用(普通函數須類型轉換)
	Plusfunc(c, d);
	//Plusfunc2(a, b);

	//類型無法匹配
	//Plusfunc(a, c);

	system("pause");
	return EXIT_SUCCESS;
}

#endif