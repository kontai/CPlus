#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

class Phone
{
public:
	Phone()
	{
		cout << "手機的默認構造函數調用" << endl;
	}
	Phone(string name)
	{
		cout << "手機的有參構造調用" << endl;
		m_PhoneName = name;
	}
	
	~Phone()
	{
		cout << "手機的析構函數調用" << endl;
	}

	string m_PhoneName;

};

class Game
{
public:
	Game()
	{
		cout << "Game的默認構造函數調用" << endl;
	}
	Game(string name)
	{
		cout << "Game的有參構造調用" << endl;
		m_GameName = name;
	}
	~Game()
	{
		cout << "Game的析構函數調用" << endl;
	}

	string m_GameName;

};

class Person
{
public:
	Person()
	{
		cout << "Person的默認構造函數調用" << endl;
	}

	Person(string name, string phoneName, string gameName) : m_Name(name), m_Phone(phoneName), m_Game(gameName)
	{
		cout << "Person的有參構造調用" << endl;
		//m_Name = name;
	}

	void playGame()
	{
		cout << m_Name << " 拿著《" << m_Phone.m_PhoneName << "》牌手機 ，玩著《" << m_Game.m_GameName << "》遊戲" << endl;
	}

	~Person()
	{
		cout << "Person的析構函數調用" << endl;
	}

	string m_Name; //姓名
	Phone m_Phone; //手機
	Game m_Game; //遊戲
};

//類對像作為類成員時候，構造順序先將類對像一一構造，然後構造自己， 析構的順序是相反的
void test01()
{
	Person p("狗蛋","蘋果","切水果");
	p.playGame();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}