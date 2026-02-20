#pragma once

template<typename T>
class MyAdd
{
public:

/*
 *為了優化編譯時間，可以把func定義在MyAdd.cpp中，編譯器會自動把它與MyAdd.hpp產生連結，
 *
 *
 */
	const void func (T a);
};


/* //或者, 也可以把func定義在MyAdd.hpp中，並且使用extern template來阻止編譯器隱式實例化
 * 並且在MyAdd.cpp中包含extern template宣告，如下
template<typename T>
class MyAdd
{
public:

	const void func (T a);
};
extern template class MyAdd<int>;
extern template class MyAdd<double>;
*/
