#include <iostream>
#include <string>
using namespace std;

class Calculate_base{
public:
    int m_num1;
    int m_num2;
public:
    // virtual int get_result(){
    //     return 0;
    // }
    virtual int get_result() = 0;
};
//�ӷ�����������
class AddCalculate:public Calculate_base{
public: 
    int get_result(){
        return m_num1+m_num2;
    }
};
//��������������
class DecreaseCalculate:public Calculate_base{
public:
    int get_result(){
        return m_num1-m_num2;
    }
};
//�˷�����������
class MultipCaculate:public Calculate_base{
public:
    int get_result(){
        return m_num1*m_num2;
    }
};

void test(){
    //����ָ��ָ���������
    Calculate_base *p1 = new AddCalculate;
    p1->m_num1 = 10;
    p1->m_num2 = 20;
    cout<<p1->m_num1<<" + "<<p1->m_num2<<" = "<<p1->get_result()<<endl;
    delete p1;  //�ͷ��ڴ�
    p1 = NULL;  //ָ�븴λ
    DecreaseCalculate dec;
    Calculate_base *p2 = &dec;
    p2->m_num1 = 30;
    p2->m_num2 = 40;
    cout<<p2->m_num1<<" - "<<p2->m_num2<<" = "<<p2->get_result()<<endl;
    //��������ָ���������
    MultipCaculate mul;
    Calculate_base &c = mul;
    c.m_num1 = 10;
    c.m_num2 = 20;
    cout<<c.m_num1<<" * "<<c.m_num2<<" = "<<c.get_result()<<endl;
}
int main(){
    test();
    system("pause");
    return 0;
}
