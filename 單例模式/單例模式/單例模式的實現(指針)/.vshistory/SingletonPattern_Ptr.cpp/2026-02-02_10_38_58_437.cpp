class SingletonPtr {
private:
	SingletonPtr() {}	//構造函數私有化,防止外部實例化
public:
	static	SingletonPtr* sptr;
};

SingletonPtr *SingletonPtr::sptr = new SingletonPtr();