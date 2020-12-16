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
};
ostream& operator<<(ostream& cout, person p)
{
    cout<<"p.m_a = "<<p.m_a<<"p.m_b = "<<p.m_b;
    return cout;
}
void test()
{
    person p(13,14);
    cout<<p<<endl;
    operator<<(cout,p);
}
int main()
{
    test();
    system("pause");
    return 0;
}
