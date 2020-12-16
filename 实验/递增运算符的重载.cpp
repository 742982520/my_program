#include <iostream>
#include <string>
using namespace std;

class person
{
    friend ostream& operator<<(ostream &cout, person p);
private:
    int m_a;
    int m_b;
public:
    person(){};  //定义了有参构造函数，就必须要写一个无参构造函数。
    person(int a, int b)
    {
        m_a = a;
        m_b = b;  
    }
    //前置递增
    person& operator++()
    {
        this->m_a++;
        return *this; //返回引用，是因为能够多次调用++运算符，对一个对象进行操作
    }
    //后置递增
    person operator++(int)  //int为占位参数，用于区分前置递增和后置递增，只能用int
    {
        person temp = *this;
        this->m_b++;
        return temp;
    }
};
ostream& operator<<(ostream& cout, person p)
{
    cout<<"p.a = "<<p.m_a<<'\t'<<"p.b = "<<p.m_b;
    return cout;
}
void test()
{
    person p1(10,20);
    person p2(30,40);

    cout<<p1<<endl;
    cout<<++p1<<endl;
    cout<<++(++p1)<<endl;

    cout<<p2++<<endl;
    cout<<p2<<endl;
}
int main()
{
    test();
    
    system("pause");
    return 0;
}