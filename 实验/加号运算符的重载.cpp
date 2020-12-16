#include <iostream>
#include <string>
using namespace std;

class person
{
public:
    int m_a;
    int m_b;
public:
    person(){};  //定义了有参构造函数，就必须要写一个无参构造函数。
    person(int a, int b)
    {
        m_a = a;
        m_b = b;
    }
    //成员函数实现+号运算符重载
    person operator+(const person &p)
    {
        person temp;
        temp.m_a = this->m_a+p.m_a;
        temp.m_b = this->m_b+p.m_b;
        return  temp;
    }
};
//全局函数实现+号运算符重载
person operator+(const person &p1, const person &p2)
{
    person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p2.m_b + p2.m_b;
    return temp;
}
//运算符重载也可以发生函数重载
person operator+(const person &p1, int a)
{   
    person temp;
    temp.m_a = p1.m_a + a;
    temp.m_b = p1.m_b + a;
    return temp;
}
void test()
{
    person p1(10,20);
    person p2(30,40);
    person p3(50,60);
    //成员函数的方式
    person p4 = p2+p1;
    cout<<"p4.ma = "<<p4.m_a<<'\t'<<"p4.b = "<<p4.m_b<<endl;
    person p5 = p2.operator+(p3);
    cout<<"p5.ma = "<<p5.m_a<<'\t'<<"p4.b = "<<p5.m_b<<endl;
    //全局函数的方式
    person p6 = p1+10;
    cout<<"p6.ma = "<<p6.m_a<<'\t'<<"p6.b = "<<p6.m_b<<endl;
    person p7 = operator+(p1, 50);
    cout<<"p7.ma = "<<p7.m_a<<'\t'<<"p7.b = "<<p7.m_b<<endl;

}
int main()
{
    test();
    system("pause");
    return 0;
}
