#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>  // 引入標準字串庫
#include <cstdlib> // 為了 EXIT_SUCCESS

using namespace std;

void test01()
{
	// 優化 1：使用 RAII，宣告的同時自動打開檔案
	ofstream ofs("test.txt", ios::out | ios::trunc);

	// 優化 2：更簡潔的狀態檢查。重載了 operator bool，等同於 is_open() 且沒出錯
	if (!ofs)
	{
		cerr << "寫入：打開文件失敗" << endl;
		return; // 優化 3：防呆，失敗必須立刻退出函數
	}

	// 優化 4：使用 \n 替代 endl，避免頻繁無意義地清空緩衝區 (Flush)，提升效能
	ofs << "姓名:悟空\n"
		<< "年龄:18\n"
		<< "身高:180cm\n";

	// 優化 5：不需要手動 ofs.close()
	// 因為 ofs 是一個區域物件，當函數結束 (離開 scope) 時，
	// 它的解構子 (Destructor) 會自動幫你把緩衝區推出去並安全關閉檔案。
}

void test02()
{
	// RAII 開檔
	ifstream ifs("test.txt", ios::in);
	if (!ifs)
	{
		cerr << "讀取：打開文件失败" << endl;
		return;
	}

	// 優化 6：現代 C++ 最標準的讀檔寫法
	string line;
	// getline 會一行一行讀進 std::string，不用擔心 1024 bytes 夠不夠裝
	// 當讀到檔案尾部 (EOF) 導致讀取失敗時，getline 會回傳 false，完美結束迴圈
	while (getline(ifs, line))
	{
		cout << line << endl;
	}

	// 同樣不需要手動 ifs.close()
}

int main()
{
	test01(); // 建議先寫入，確保檔案存在
	test02(); // 再讀取

	system("pause");
	return EXIT_SUCCESS;
}