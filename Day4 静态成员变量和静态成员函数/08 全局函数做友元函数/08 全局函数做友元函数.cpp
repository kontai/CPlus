#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

class Building
{
	//讓全局的好基友函數 變為我的好朋友  友元函數
	friend void  goodGay(Building * building);
public:
	Building()
	{
		this->m_SittingRoom = "客廳";
		this->m_BedRoom = "臥室";
	}

	//客廳  臥室
public:
	string m_SittingRoom; //客廳

private:
	string m_BedRoom; //臥室
};

//全局函數  好基友
void  goodGay( Building * building )
{
	cout << "好基友正在訪問 " << building->m_SittingRoom << endl;
	cout << "好基友正在訪問 " << building->m_BedRoom << endl;
}
//友元函數 目的訪問類中的私有成員屬性
void test01()
{
	Building * building = new Building;
	goodGay(building);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}