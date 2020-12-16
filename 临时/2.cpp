#include <iostream>
#include <string>
using namespace std;

class person
{
public:
    person(){
        cout<<"父类的构造函数"<<endl;
    }
    ~person(){
        cout<<"父类的析构函数"<<endl;
    }
};
class man : public person{
public:
    man(){
        cout<<"子类的构造函数"<<endl;
    }
    ~man(){
        cout<<"子类的析构函数"<<endl;
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
