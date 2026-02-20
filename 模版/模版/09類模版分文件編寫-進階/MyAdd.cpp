#include "MyAdd.hpp"
#include <iostream>

// 1. 先寫出「通用的」模版實作
template<typename T>
void const MyAdd<T>::func(T a)
{
    std::cout << "General template: " << a << std::endl;
}

// 2. 顯式實例化 (Explicit Instantiation)
// 告訴編譯器：請幫我把 int 版本的代碼生成出來，放在這個 obj 檔裡
template void const MyAdd<int>::func(int a);

// 如果你想支援 double，就在這裡加一行，不用改 code
template void const MyAdd<double>::func(double a);