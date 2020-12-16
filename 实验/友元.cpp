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
    friend void goodgay::gay1();   //前面如果没有goodgdy的定义会出错。
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
    cout << "好基友正在访问" << p->m_sittingroom << endl;
    cout<<"好基友正在访问"<<p->m_bedroom<<endl;   
}
void goodgay::gay2()
{
    cout << "好基友正在访问" << p->m_sittingroom << endl;
    //cout << "好基友正在访问" << p->m_bedroom << endl; //gay2不能访问私有成员
}
room::room()
{
    m_sittingroom = "客厅";
    m_bedroom = "卧室";
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