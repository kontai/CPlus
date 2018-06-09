#include<iostream>
#include <fstream>

//std::ofstream print(std::ofstream );ERROR!	 傳遞 以及 返回  stream , 只能透過 point 和 reference
std::ofstream& print(std::ofstream &);

int mainIOStream() {
	std::ofstream out1, out2;
	//	 out1 = out2;  //ERROR!	 stream物件無法賦值

	/*	while(print(out1))
		{
		}
	*/

	system("pause");
	return 0;
}