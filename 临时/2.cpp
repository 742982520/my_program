#include <iostream>
#include <string>
using namespace std;

class person
{
public:
    person(){
        cout<<"����Ĺ��캯��"<<endl;
    }
    ~person(){
        cout<<"�������������"<<endl;
    }
};
class man : public person{
public:
    man(){
        cout<<"����Ĺ��캯��"<<endl;
    }
    ~man(){
        cout<<"�������������"<<endl;
    }
};

void test()
{
    man *m = new man;
    delete m;
    m = NULL;
}
int main()
{
    test();
    system("pause");
    return 0;
}
