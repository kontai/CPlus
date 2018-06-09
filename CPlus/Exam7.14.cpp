#include<iostream>
#include <random>
#include<vector>
#define N 3

using namespace std;

void add(vector<double> i) {
	vector<double>::iterator s = i.begin();
	double sum = 0.0;
	while (s != i.end()) {
		sum += *s;
		s++;
	}
	cout << "sum=" << sum << endl;
}
int Exam7_14main() {
	vector<double> a;
	srand((unsigned)rand());
	int i = 0;
	cout << "----------------" << endl;
	while (i != N) {
		double ra = (rand() % 100) + (rand() % 100) / 100.0;
		cout << ra << endl;
		a.push_back(ra);
		i++;
	}
	cout << "----------------" << endl;
	add(a);

	system("pause");
	return 0;
}