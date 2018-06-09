#include<iostream>

using namespace std;
//當程式崩潰時,緩衝區不會自動清空
//常常利用<最後一個輸出>來判斷錯誤產生位置
//要確認輸出任何訊息都已清掃出緩衝區,有助於抓蟲
int mainClearnBuff() {
	cout << "test" << flush;		//清空緩衝區,不加任何資料
	cout << "test2" << ends;	//清空緩衝區,末尾加上null字元
	cout << "test3" << endl;		//清空緩衝區,末尾加上'\n'換行符

	cout << unitbuf << "hello!" << "set1" << "set2" << nounitbuf;
	/*上式等同
	cout <<   "hello!" << flush<< "set1" <<flush<< "set2"<<flush ;
*/
	system("pause");
	return 0;
}