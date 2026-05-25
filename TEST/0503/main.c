// 引用sum.cpp文件里面定义的全局变量以及函数
extern int gdata;
int sum(int, int);

int data = 20;

int main()
{
    int a = gdata;
    int b = data;

    int ret = sum(a, b);
    return 0;
}