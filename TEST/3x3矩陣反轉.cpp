/*************************
[11/7/2018 21:34
pt.cpp
3x3 �����m
*************************/

#include<iostream>

using namespace std;

void swapI(int &i, int &j) {
	int temp = i;
	i = j;
	j = temp;
}

int mainD3() {
	time(&st);  //�����e�ɶ�
	const int row = 4, col = 4;
	int **p = new int *[col];
	for (int i = 0; i < row; i++)
		p[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			p[i][j] = j + i * row;

	for (int i = 0; i < row; i++) {
		cout << '\n';
		for (int j = 0; j < col; j++)
			cout << p[i][j];
	}

	cout << '\n';
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			p[j][i] = j + i * row;

	//for (int i = 0; i < row; i++)
	//	for (int j = 0; j < i; j++)
	//		swapI(p[i][j],p[j][i]);

	for (int i = 0; i < row; i++) {
		cout << '\n';
		for (int j = 0; j < col; j++)
			cout << p[i][j];
	}

	system("pause");
	return 0;
}