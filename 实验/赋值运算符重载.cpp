#include <iostream>
#include <string>
using namespace std;

class person
{
    friend ostream& operator<<(ostream &cout, person &p);
public:
    int* m_age;
public:
    person(){};  //定义了有参构造函数，就必须要写一个无参构造函数。
    person(int age)
    {
        m_age = new int(age);
    }
    person& operator=(person &p)
    {
        if(m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
        m_age = new int(*p.m_age);
        return *this;
    }
    ~person()
    {
        if(m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
            cout<<"函数已销毁"<<endl;
        }
    }
};
ostream& operator<<(ostream& cout, person &p)
{
    cout<<*p.m_age;
    return cout;
}
void test()
{   
    person p1(15);
    person p2 = p1;
    cout<<"p1 age is "<<p1<<endl;
    cout<<"p2 age is "<<p2<<endl;
}
int main()
{
    test();
    
    system("pause");
    return 0;
}