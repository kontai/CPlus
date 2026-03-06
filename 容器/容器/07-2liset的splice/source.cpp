#include<iostream>
#include<list>
using namespace std;
void func1() {
	list list1 = { 1, 2, 3, 4, 5 };
	list list2 = { 11, 12, 13, 14, 15 };
	list<int>::iterator iter = list1.begin();
	iter++; //把list2全部剪贴到list1的iter位置
	list1.splice(iter, list2);
	cout << "list1: ";
	for (auto& num : list1)
	{
		cout << num << " ";
	}
	cout << endl;
	cout << "list2: ";
	for (auto& num : list2)
	{
		cout << num << " ";
	}
	cout << endl;
}
void func2() {
	list list3 = { 1, 2, 3, 4, 5 };
	list list4 = { 11, 12, 13, 14, 15 };
	list<int>::iterator iter1 = list4.begin();
	iter1++; //把list4中iter1位置处的值剪贴到list3的list3.begin()位置
	list3.splice(list3.begin(), list4, iter1);
	cout << "list3: ";
	for (auto& num : list3) { cout << num << " "; }
	cout << endl; cout << "list4: ";
	for (auto& num : list4) { cout << num << " "; }
	cout << endl;

}
void func3() {
	list list5 = { 1, 2, 3, 4, 5 };
	list list6 = { 11, 12, 13, 14, 15 };
	list<int>::iterator iter2 = list6.begin();
	list<int>::iterator iter3 = iter2;
	iter3++; iter3++; iter3++; //把list6中从iter2到iter3的元素剪贴到list5中的list5.begin()处
	list5.splice(list5.begin(), list6, iter2, iter3);
	cout << "list5: ";
	for (auto& num : list5) { cout << num << " "; }
	cout << endl; cout << "list6: ";
	for (auto& num : list6) { cout << num << " "; }
	cout << endl;
}
int main() {
	//func1();
	//cout << "---------------------" << endl;
	//func2();
	//cout << "-----------------------" << endl;
	func3();
	return 0;
}