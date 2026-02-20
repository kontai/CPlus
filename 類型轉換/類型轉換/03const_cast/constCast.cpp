#include<iostream>
/*const_case
* 只能用來移除（或加上） const 或 volatile 屬性，除此之外它不能改變型別。
* const_cast<type>(expression) 將 expression 轉型為 type，但不會對 expression 做任何修改。
*
*/
using namespace std;

void legacy_c_function(char* str) {
	if (str != NULL)
	{
		str[1] = 'J';
		cout << str << endl;
	}
} // 舊版 API，參數沒有 const

void my_cpp_function(const char* message) {
	// legacy_c_function(message); // 編譯錯誤！丟失了 const
	//message[0] = 'J';	// 編譯錯誤！不允許修改 const 變數

	// 為了通過編譯，強行剝除 const
	char* c = const_cast<char*>(message);
	c[0]='J';
	legacy_c_function(const_cast<char*>(message));
	//legacy_c_function(const_cast<char*>(message));
}

int main() {
char str[] = "Hello, world!";
my_cpp_function(str);
cout<< str << endl; // 輸出 "Jello, world!"
	return 0;
}