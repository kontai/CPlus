/*
2018/09/01 22:15:06
1.cpp
*/

#include<iostream>
#include<fstream>

using namespace std;

int main() {
	fstream inFile, outFile;
	inFile.open("e:\\tmp\\0.jpg", ios::in | ios::binary);
	if (!inFile)
	{
		cerr << "file not found!" << endl;
		system("pause");
		exit(1);
	}

	outFile.open("e:\\tmp\\encode.jpg", ios::out | ios::binary);

	int n;
	inFile.seekg(0, ios::end);
	n = inFile.tellg();
	char* s = new char[n];
	inFile.read(s, n);
	int* tmp = NULL;
	tmp = new int[n];
	size_t size = 0;
	char abc[] = "akdjf";
	char def[] = "adjf";
	int aaa = atoi(abc);
	cout << aaa << endl;
	cout << (aaa ^ 2) << endl;

	//	for (int i = 0; i < n; i++)
	//	{
	//		 tmp[size] = (atoi(s+i));
	//		 cout << *tmp;
	//		 size++;
	//	}

	system("pause");
	return 0;
}