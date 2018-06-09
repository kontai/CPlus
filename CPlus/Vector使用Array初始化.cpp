#include<iostream>
#include <vector>

using namespace std;

int mainVectorInit() {
	const size_t Bit_size = 6;
	int arr[Bit_size] = { 0,1,2,3,4,5 };
	//vector可以使用array元素範圍作初始化
	//第一個參數,傳入陣列位址作為啟始範圍
	//第二個參數,從啟始範圍開始到要複製的"最後一個元素的下一個位置"
	vector<int>vin(arr, arr + Bit_size);	 //arr[0] ~ arr[4]
	vector<int>vin2(arr + 1, arr + 5);		//arr[1],arr[2],arr[3],arr[4]; 四個元素,4+1(最後一個元素的下一個位置)
	cout << vin[0] << endl;
	cout << vin2[0] << ' ' << vin2[3] << endl;
	char *sp = "abcdefg";
	vector<char>vin3(sp + 2, sp + 4);		//使用sp[2],sp[3]初始化vin3
	cout << vin3[0] << ' ' << vin3[1] << endl;

	system("pause");

	return 0;
}