#include <iostream>
#include <string>
using namespace std;

class person
{
public:
    int m_a;
    int m_b;
public:
    person(){};  //�������вι��캯�����ͱ���Ҫдһ���޲ι��캯����
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
