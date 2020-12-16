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
    person(){};  //�������вι��캯�����ͱ���Ҫдһ���޲ι��캯����
    person(int a, int b)
    {
        m_a = a;
        m_b = b;  
    }
    //ǰ�õ���
    person& operator++()
    {
        this->m_a++;
        return *this; //�������ã�����Ϊ�ܹ���ε���++���������һ��������в���
    }
    //���õ���
    person operator++(int)  //intΪռλ��������������ǰ�õ����ͺ��õ�����ֻ����int
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