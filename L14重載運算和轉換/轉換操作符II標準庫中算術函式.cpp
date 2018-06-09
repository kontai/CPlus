#include <functional> //標準庫所提供的函式庫
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

int main() {
  std::plus<int> fplus;  //加法運算
  std::minus<int> fmins; //減法運算
  std::negate<int> fneg; //取負值
  int sum;
  sum = fplus(12, 24);
  std::cout << sum << std::endl;
  std::cout << fmins(2, 4) << std::endl;
  std::cout << fplus(2, fneg(-3));

std::fstream fin;
fin.open("/home/tai/workspace/cproj/CPlus/L14重載運算和轉換/123");
if(fin)
std::cout<<"done!"<<std::endl;
else
std::cout<<"file open fail!"<<std::endl;

std::ofstream fout("/home/tai/workspace/cproj/CPlus/L14重載運算和轉換/456");
if(!fout)
std::cout<<"file not avaliable"<<std::endl;

std::string *str;
while(!fin.eof()){
    fin>>*str;
fout<<str<<'\n';
str++;
}
if(fin.eof()) ShowMessage("end of file..");
fin.close();

//std::vector<std::string> vstr;
//std::sort(vstr.begin(),vstr.end(),std::greater<std::string>());



  




  return 0;
}