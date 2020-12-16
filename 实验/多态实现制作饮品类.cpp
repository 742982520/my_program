#include <iostream>
#include <string>
using namespace std;
//������
class AbstractDrink{  
public:
    virtual void Boil() = 0;    //��ˮ
    virtual void Brew() = 0;    //����
    virtual void Pour() = 0;    //����
    virtual void Add() = 0;     //������
    //�������� ��Ϊ����̳и��࣬ÿ�����඼�д˺�����
    void Makedrink(){
        Boil();
        Brew();
        Pour();
        Add();
    }
};
class coffee:public AbstractDrink{
public:
    virtual void Boil(){
        cout<<"���Ȫˮ"<<endl;
    }
    virtual void Brew(){
        cout<<"���ݿ���"<<endl;
    }   
    virtual void Pour(){
        cout<<"���뱭��"<<endl;
    }
    virtual void Add(){
        cout<<"����"<<endl;
    }
};
class tea:public AbstractDrink{
public:
    virtual void Boil(){
        cout<<"���Ȫˮ"<<endl;
    }
    virtual void Brew(){
        cout<<"���ݲ�Ҷ"<<endl;
    }   
    virtual void Pour(){
        cout<<"���뱭��"<<endl;
    }
    virtual void Add(){
        cout<<"��õ��"<<endl;
    }
};
void dowork1(AbstractDrink *abs){
    abs->Makedrink();
    delete abs;
    abs = NULL;
    cout<<"========================"<<endl;
    cout<<endl;
}
void dowork2(AbstractDrink *abs){
    abs->Makedrink();
    cout<<"========================"<<endl;
    cout<<endl;
}
void dowork3(AbstractDrink &abs){
    abs.Makedrink();
    cout<<"========================"<<endl;
    cout<<endl;
}
void test(){
    //����ָ��ָ���������
    dowork1(new tea);
    dowork1(new coffee);
    tea t;
    coffee c;
    dowork2(&t);
    dowork2(&c);
    //��������ָ���������
    dowork3(t);
    dowork3(c);
}
int main(){
    test();
    system("pause");
    return 0;
}
