#include <iostream>
#include <string>
using namespace std;

class Myprintf  //�����
{
public:
    void operator()(string test)
    {
        cout<<test<<endl;
    }
};

void my_printf(string test)
{
    cout<<test<<endl;
}

class Myadd  //�ӷ���
{
public:
    int operator()(int num1, int num2)
    {
        return num1+num2; 
    }
};

void test02()
{
    Myadd myadd;
    int ret = myadd(100, 100);
    cout<<"ret = "<<ret<<endl;

    //������������
    int reg = Myadd()(100, 10);
    cout<<"reg = "<<reg<<endl;
}
void test01()
{
    Myprintf myprintf;
    myprintf("ɽ���Ƽ���ѧ");       //�º�������ʽ�Ϸǳ��������á�
    my_printf("������Ϣ����ѧԺ");  //������������
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}