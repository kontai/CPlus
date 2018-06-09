/****************************************
[3/29/2017  21:11]
inline內嵌函數.cpp
****************************************/

#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

//內嵌函數是在一般的函數前面，加上inline這個關鍵字，例如以下的例子
//內嵌函數是用來加速C++的執行速度，在程式碼的語法上不會有什麼太大的差異，但是在Compiler編譯時，卻會有不一樣的效果
// 一般而言，當我們撰寫函數，並呼叫使用，電腦的機器語言指令會紀錄目前工作階段的記憶體位址，然後跳至函數的記憶體位置處理完程序後，並回到原先的位址上，而這樣來回會造成時間上的額外負擔。

//C++於是提供這種內嵌函數，當我們加入關鍵字時，在編譯時便會把函數中的程式直接展開

//即便加入inline想要使用內嵌函數，編譯時也不一定就會實作，編譯器會選擇，如果你執行的函數中程式碼所需時間大於處理呼叫函數的時間，則能節省的時間比較少，反之若是你的函數中程式碼執行的時間很短，則使用內前函數可以省去較多的呼叫函數的時間，並且如果常常會使用到此函數，使用內嵌的效率也會比較好
//
//inline int sqa(int x)
//{
//	return x*x;
//}
//
//int mainInline(){
//	int val = 2;
//	sqa(val);  //inline:此處直接展開成2*2
//
//
//
//system("pause");
//return 0;
//}

class Mala {
public:
	char text1();
	inline char text1(size_t r, size_t t2);
	Mala(string &str);
private:
	string content;
	size_t r, t2;
};