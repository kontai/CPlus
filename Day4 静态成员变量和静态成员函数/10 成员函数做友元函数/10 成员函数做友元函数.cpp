#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//只讓 visit可以作Building的好朋友  visit2 不可以訪問私有屬性
class Building;
class goodGay
{
public:
	goodGay();

	void visit();
	void visit2();
private:
	Building * building;
};

class Building
{
	//讓成員函數 visit作為友元函數
	friend void goodGay::visit();
	
public:
	Building();
public:
	string m_SittingRoom; //客廳
private:
	string m_BedRoom; //臥室
};

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "好基友正在訪問： " << this->building->m_SittingRoom << endl;
	cout << "好基友正在訪問： " << this->building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "好基友正在訪問： " << this->building->m_SittingRoom << endl;
	//cout << "好基友正在訪問： " << this->building->m_BedRoom << endl;
}

Building::Building()
{
	this->m_SittingRoom = "客廳";
	this->m_BedRoom = "臥室";
}

void test01()
{
	goodGay gg;
	gg.visit();
	gg.visit2();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}