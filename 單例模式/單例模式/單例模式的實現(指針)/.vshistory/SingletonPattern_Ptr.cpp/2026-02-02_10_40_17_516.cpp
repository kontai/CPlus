class SingletonPtr {
private:
	SingletonPtr() {}	//構造函數私有化,防止外部實例化
public:
	static	SingletonPtr* sptr;
};

SingletonPtr* SingletonPtr::sptr = new SingletonPtr();	//類外初始化靜態成員變量

void funcPtr() {
	SingletonPtr* p1 = SingletonPtr::sptr;
	SingletonPtr* p2 = SingletonPtr::sptr;

	//比較兩個指針是否指向同一個實例
	cout << "p1 address: " << p1 << endl;
	cout << "p2 address: " << p2 << endl;
}