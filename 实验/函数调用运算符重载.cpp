#include <iostream>
#include <string>
using namespace std;

class Myprintf  //输出类
{
public:
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

void my_printf(string test)
{
    cout<<test<<endl;
}

class Myadd  //加法类
{
public:
    int operator()(int num1, int num2)
    {
        return num1+num2; 
    }
};

void test02()
{
    Myadd myadd;
    int ret = myadd(100, 100);
    cout<<"ret = "<<ret<<endl;

    //匿名函数调用
    int reg = Myadd()(100, 10);
    cout<<"reg = "<<reg<<endl;
}
void test01()
{
    Myprintf myprintf;
    myprintf("山东科技大学");       //仿函数，形式上非常像函数调用。
    my_printf("电子信息工程学院");  //正常函数调用
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}