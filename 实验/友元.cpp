#include <iostream>
#include <string>
using namespace std;
class room;
class goodgay
{
public:
    room* p;
    goodgay();
    void gay1();
    void gay2();
};
class room
{
    friend void goodgay::gay1();   //ǰ�����û��goodgdy�Ķ�������
public:
    string m_sittingroom;
private:
    string m_bedroom;
public:
    room();
};


goodgay::goodgay()
{
    p = new room;
}
void goodgay::gay1()
{
    cout << "�û������ڷ���" << p->m_sittingroom << endl;
    cout<<"�û������ڷ���"<<p->m_bedroom<<endl;   
}
void goodgay::gay2()
{
    cout << "�û������ڷ���" << p->m_sittingroom << endl;
    //cout << "�û������ڷ���" << p->m_bedroom << endl; //gay2���ܷ���˽�г�Ա
}
room::room()
{
    m_sittingroom = "����";
    m_bedroom = "����";
}
void test()
{
    goodgay gay;
    gay.gay1();
    gay.gay2();
}

int main()
{
    test();
    system("pause");
}