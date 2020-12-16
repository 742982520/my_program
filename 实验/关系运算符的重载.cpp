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
    person(){};  //�������вι��캯�����ͱ���Ҫдһ���޲ι��캯����
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
    person p1("����",15);
    person p2("����",15);
    if(p1 == p2)
    {
        cout<<"p1��p2����ȵ�"<<endl;
    }
    else
    {
        cout<<"p1��p2�ǲ���ȵ�"<<endl;
    }
    
    if(p1 != p2)
    {
       cout<<"p1��p2�ǲ���ȵ�"<<endl; 
    }
    else
    {
        cout<<"p1��p2����ȵ�"<<endl;
    }
}
int main()
{
    test();
    
    system("pause");
    return 0;
}