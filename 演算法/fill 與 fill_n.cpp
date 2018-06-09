#include <iostream>
#include<numeric>
#include <vector>
#include <iterator>

using namespace std;

int mainFill_Fill_n() {
	vector<int>ivec={12,3234 ,54546 ,76,2,23,4};

//將指定區間填滿0
	fill(ivec.begin(), ivec.end(), 0); 

//從ivec.begin開始2個元素,填滿0
	fill_n(ivec.begin(), 2, 0); 

	vector<int>fill_test;   //空的vector
	//fill_n(fill_test.begin(), 10, 0);  //執行時會產生錯誤(空的vector無法塗寫)

	//back_inserter將生成insert iterator , 並對fill_test呼叫push_back,將10個0添加到尾端
	//使用back_inserter需加入頭檔<iterator>
	fill_n(back_inserter(fill_test), 10, 0);

	system("pause");
	return 0;
}
