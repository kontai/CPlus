#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//創建主席類
//需求 單例模式  為了創建類中的對象，並且保證只有一個對像實例
class ChairMan
{
	//1構造函數 進行私有化
private:
	ChairMan()
	{
		//cout << "創建國家主席" << endl;
	}
	//拷貝構造 私有化
	ChairMan(const ChairMan&c)
	{}

public:
	//提供 get方法 訪問 主席
	static ChairMan* getInstance()
	{
		return singleMan;
	}

private:
	static ChairMan * singleMan;

};
ChairMan * ChairMan::singleMan = new ChairMan;

void test01()
{
	/*ChairMan c1;
	ChairMan * c2 = new ChairMan;
	ChairMan * c3 = new ChairMan;*/

	/*ChairMan * cm = ChairMan::singleMan;
	ChairMan * cm2 = ChairMan::singleMan;
*/
	//ChairMan::singleMan = NULL;


	ChairMan * cm1 = ChairMan::getInstance();
	ChairMan * cm2 = ChairMan::getInstance();
	if (cm1 == cm2)
	{
		cout << "cm1 與 cm2相同" << endl;
	}
	else
	{
		cout << "cm1 與 cm2不相同" << endl;
	}

	/*ChairMan * cm3 = new ChairMan(*cm2);
	if (cm3 == cm2)
	{
	cout << "cm3 與 cm2相同" << endl;
	}
	else
	{
	cout << "cm3 與 cm2不相同" << endl;
	}*/


}

int main(){

	//cout << "main調用" << endl; 主席創建先於main調用
	test01();

	system("pause");
	return EXIT_SUCCESS;
}