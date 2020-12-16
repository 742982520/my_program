#include <iostream>
#include <string>
using namespace std;

class person
{
    friend ostream& operator<<(ostream &cout, person &p);
public:
    string m_name;
    int m_age;
public:
    person(){};  //定义了有参构造函数，就必须要写一个无参构造函数。
    person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    bool operator==(person &p)
    {
        if(m_name == p.m_name && m_age == p.m_age)
        {
            return true;
        }
        return false;
    }
    bool operator!=(person &p)
    {
        if(m_name == p.m_name && m_age == p.m_age)
        {
            return false;
        }
        return true;
    }
};

void test()
{
    person p1("张三",15);
    person p2("张三",15);
    if(p1 == p2)
    {
        cout<<"p1和p2是相等的"<<endl;
    }
    else
    {
        cout<<"p1和p2是不相等的"<<endl;
    }
    
    if(p1 != p2)
    {
       cout<<"p1和p2是不相等的"<<endl; 
    }
    else
    {
        cout<<"p1和p2是相等的"<<endl;
    }
}
int main()
{
    test();
    
    system("pause");
    return 0;
}