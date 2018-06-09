#include<iostream>
#include<list>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
/*
istream_iterator<T> in(strm);創建從輸入流 strm 中讀取 T 類型對象的istream_iterator 對象

istream_iterator<T> in; istream_iterator 對象的超出末端反覆運算器

ostream_iterator<T> in(strm);創建將 T 類型的對象寫到輸出流 strm 的ostream_iterator對象

ostream_iterator<T> in(strm, delim);創建將 T 類型的對象寫到輸出流 strm 的ostream_iterator 物件，在寫入過程中使用 delim 作為元素的分隔符號。delim 是以空字元結束的字元陣列
*/


//int mainIosIter() {
//	istream_iterator<int> cin_it(cin);    // reads ints1 from cin      
//	istream_iterator<int> end_of_stream;  // end iterator value 
//	ostream_iterator<Sales_item> output(outfile, " ");
//	// writes Sales_items from the ofstream named outfile 
//	 // each element is followed by a space	ofstream outfile; 
//
//	//在創建 ostream_iterator 物件時，可提供第二個（可選的）實參，指定將元素寫入輸出流時使用的分隔符號。分隔符號必須是 C 風格字串。因為它是 C 風格字串，所以必須以空字元結束；否則，其行為將是未定義的。
//
//
// /////////////////////////////////////////////////////////////////////////
//	istream_iterator<int> in_iter(cin); // read ints from cin 
//	istream_iterator<int> eof; // istream "end" iterator  
//							   // read until end of file, storing what was read in vec 
//	vector<int>vec;
//	while (in_iter != eof)
//		vec.push_back(*in_iter++);
//	// increment advances the stream to the next value 
//	// dereference reads next value from the istream    
///////////將上例更簡化///////////////////////////////////////////////////////
//	istream_iterator<int> in_iter(cin); // read ints from cin  
//	istream_iterator<int> eof;      // istream "end" iterator     
//	vector<int> vec(in_iter, eof);  // construct vec from an iterator range
//
//
//	/////////////////////////////////////////////////////////////////////////
//						// write one string per line to the standard output
//	ostream_iterator<string> out_iter(cout, "\n");
//	// read strings from standard input and the end iterator  
//	istream_iterator<string> in_iter(cin), eof;
//	// read until eof and write what was read to the standard output    
//	while (in_iter != eof)
//		// write value of in_iter to standard output 
//	 // and then increment the iterator to get the next value from cin
//		*out_iter++ = *in_iter++;
//
//	/////////////////////////////////////////////////////////////////////////
//	istream_iterator<int> cin_it(cin);    // reads ints from cin     
//	istream_iterator<int> end_of_stream;  // end iterator value 
//										  // initialize vec from the standard input:
//	vector<int> vec(cin_it, end_of_stream);
//	sort(vec.begin(), vec.end());
//	// writes ints to cout using " " as the delimiter   
//	ostream_iterator<int> output(cout, " ");
//	// write only the unique elements in vec to the standard output    
//// unique_copy(vec.begin(), vec.end(), output); 
//
// /************************************************************************/
//
// /*
// 如果程式的輸入是：
//	 23 109 45 89 6 34 12 90 34 23 56 23 8 89 23
// 輸出則是：
//	 6 8 12 23 34 45 56 89 90 109
//*/
//
///************************************************************************/
//
//
//	system("pause");
//	return 0;
//}

