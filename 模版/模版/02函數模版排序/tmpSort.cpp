#include<iostream>
#include<random>
using namespace std;

template<typename T>
void mySort(T* arr, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
		{
			//swap
			if (arr[j] < arr[i]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void testFunc() {
	//產生20個隨機數字陣列
	random_device rd;

	  /* 亂數產生器 */
	mt19937_64 generator(rd());

	/* 亂數的機率分布 */
	uniform_real_distribution<float> unif(0.0, 100);

	const int len = 10;
	/* 產生亂數 */
	float x;
	float arr[20] = { 0 };
	for (int i = 0; i < len; i++) {
		arr[i] = unif(generator);
	}
	mySort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	testFunc();

	return 0;
}