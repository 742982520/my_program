#include <iostream>
#include <string>
using namespace std;

class person
{
public:
     static int a;
    void fun()
    {
        a+=1;
    }
};
int person:: a=100;
void test()
{
    person p1;
    person p2;
    p1.fun();
    cout<<p1.a<<endl;
    cout<<p2.a<<endl;
    p2.fun();
    cout<<p1.a<<endl;
    cout<<p2.a<<endl;
}
int main()
{
    test();
    system("pause");
    return 0;
}