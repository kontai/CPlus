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
	cout << "��ƼҪO�ե�" << endl;
	//return a + b;
}

//�禡����
void Plusfunc(int a, int b) {
	cout << "�����禡�Q�ե�" << endl;
}

void Plusfunc2(int a, int b) {
	cout << "���q��ƽե�" << endl;
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

	//����ƭ���,�|���δ��q���
	Plusfunc(a, b);

	//�j��եΨ�ƼҪO
	Plusfunc<>(a, b);

	//�sĶ���|�u�ƽե�(���q��ƶ������ഫ)
	Plusfunc(c, d);
	//Plusfunc2(a, b);

	//�����L�k�ǰt
	//Plusfunc(a, c);

	system("pause");
	return EXIT_SUCCESS;
}

#endif