#include <iostream>
//#include<fstream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class Sales_ItemA {
public:
  Sales_ItemA() {}
  Sales_ItemA(string str = "") : st(str) {}
  Sales_ItemA(const double m1 = 0.0) : db(m1) {}

  operator string() const { return st; }
  operator double() const { return db; }
  operator const int() { return db; }
  operator int() const { return db; }

private:
  string st;
  double db;
};

int main() {
  Sales_ItemA ss("abc");
  Sales_ItemA d1(2.3);
  string str = ss;
  double db1 = d1; //重載決議,即使double須經過轉換為int,另一個不需要,也不會改變編譯器抉擇
  int in1 = d1;
  double db2 = d1.operator double(); //明確使用double轉換函數
  double db3=Sales_ItemA (3.5);
  cout << str << '\t' << db1 << '\t' << in1 << '\t' << db2 <<'\t'<<db3<< endl;
  return 0;
}
