#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

class Printer
{
private:
	Printer(){ m_Count = 0; };
	Printer(const Printer& p);

public:
	static Printer* getInstance()
	{
		return singlePrinter;
	}

	void printText(string text)
	{
		cout << text << endl;
		m_Count++;
		cout << "打印機使用了次數為： " << m_Count << endl;
	}




private:
	static Printer* singlePrinter;
	int m_Count;
};
Printer* Printer::singlePrinter = new Printer;

void test01()
{
	//拿到打印機
	Printer * printer =  Printer::getInstance();

	printer->printText("離職報告");
	printer->printText("入職報告");
	printer->printText("加薪申請");
	printer->printText("升級申請");
	printer->printText("退休申請");
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}