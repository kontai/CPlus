#include <iostream>  // 包含输入输出流库

using namespace std;  // 使用标准命名空间

/**
 * @brief 自定义异常类，继承自标准异常类exception
 */
class MyError :public exception {
public:
	/**
	 * @brief 构造函数，初始化错误信息
	 * @param msg 错误信息字符串
	 */
	MyError(const char* msg) {
		//this->msg = const_cast<char*>(msg);  // 注释掉的代码，直接赋值
		// 动态分配内存并复制错误信息
		this->msg = new char[strlen(msg) + 1];
		memcpy(this->msg, msg, strlen(msg) + 1);
	}

	/**
	 * @brief 获取错误信息的虚函数
	 * @return 错误信息字符串
	 */
	virtual const char* what() const {
		return msg;
	}

	/**
	 * @brief 拷贝构造函数
	 * @param e 要拷贝的MyError对象
	 */
	MyError(const MyError& e) {
		// 动态分配内存并复制错误信息
		this->msg = new char[strlen(e.msg) + 1];
		memcpy(this->msg, e.msg, strlen(e.msg) + 1);
	}

	/**
	 * @brief 赋值运算符重载
	 * @param e 要赋值的MyError对象
	 * @return 当前对象的引用
	 */
	MyError& operator=(const MyError& e) {
		// 释放原有内存
		if (this->msg != nullptr)
		{
			delete this->msg;
			this->msg = nullptr;
		}
		// 动态分配内存并复制错误信息
		this->msg = new char[strlen(e.msg) + 1];
		memcpy(this->msg, e.msg, strlen(e.msg) + 1);
		return *this;
	}

	/**
	 * @brief 析构函数，释放动态分配的内存
	 */
	~MyError()
	{
		if (this->msg != nullptr)
		{
			delete this->msg;
			this->msg = nullptr;
		}
	}

private:
	char* msg;  // 错误信息字符串指针
};

/**
 * @brief 抛出标准异常的函数
 */
void fun1() {
	throw out_of_range("error: out of range");  // 抛出越界范围异常
}

/**
 * @brief 抛出自定义异常的函数
 */
void func2() {
	throw MyError("error: my error");  // 抛出自定义异常
}

/**
 * @brief 测试异常处理的函数
 */
void test() {
	try {
		//fun1();  // 注释掉的调用标准异常的函数
		func2();  // 调用抛出自定义异常的函数
	}
	catch (out_of_range& e)  // 捕获越界范围异常
	{
		cout << e.what() << endl;
	}
	catch (MyError& e) {  // 捕获自定义异常
		cout << e.what() << endl;
	}
	catch (...) {  // 捕获所有其他异常
		cout << "nothing happen." << endl;
	}
}


/**
 * @brief 主函数，程序入口点
 * @return 程序执行状态码
 */
int main()
{
	test();  // 调用测试函数
	return 0;  // 返回成功状态码
}