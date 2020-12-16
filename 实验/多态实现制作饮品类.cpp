#include <iostream>
#include <string>
using namespace std;
//抽象类
class AbstractDrink{  
public:
    virtual void Boil() = 0;    //煮水
    virtual void Brew() = 0;    //冲泡
    virtual void Pour() = 0;    //倒出
    virtual void Add() = 0;     //加佐料
    //制作流程 因为子类继承父类，每个子类都有此函数，
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
        cout<<"煮矿泉水"<<endl;
    }
    virtual void Brew(){
        cout<<"冲泡咖啡"<<endl;
    }   
    virtual void Pour(){
        cout<<"倒入杯中"<<endl;
    }
    virtual void Add(){
        cout<<"加糖"<<endl;
    }
};
class tea:public AbstractDrink{
public:
    virtual void Boil(){
        cout<<"煮矿泉水"<<endl;
    }
    virtual void Brew(){
        cout<<"冲泡茶叶"<<endl;
    }   
    virtual void Pour(){
        cout<<"倒入杯中"<<endl;
    }
    virtual void Add(){
        cout<<"加玫瑰"<<endl;
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
    //父类指针指向子类对象
    dowork1(new tea);
    dowork1(new coffee);
    tea t;
    coffee c;
    dowork2(&t);
    dowork2(&c);
    //父类引用指向子类对象
    dowork3(t);
    dowork3(c);
}
int main(){
    test();
    system("pause");
    return 0;
}
