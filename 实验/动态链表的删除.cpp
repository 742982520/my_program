#include <iostream>
#include <string>
using namespace std;
int n=1;
struct student
{
    string name;
    int num;
    int socre;
    int flag;  //链表结束输入的标志
    struct student *next;  //指向另一个结构体的指针
};
student *creat_link(void)
{
    student *head ; //链表的头指针
    student *p1;
    student *p2;

    head = new student;  //head 作为来链表的头，指向第一个开辟的结构体空间
    p1 = head;  //p1指向第一个链表
    p2 = head;  //p2指向第一个链表
    //初始化第一个节点
    cout<<"正在创建第1个节点"<<endl;
    cout<<"请输入姓名"<<endl;
    cin>>p1->name;
    cout<<"请输入学号"<<endl;
    cin>>p1->num;
    cout<<"请输入成绩"<<endl;
    cin>>p1->socre;
    cout<<"是否继续输入，1、继续，2、结束"<<endl;
    cin>>p1->flag;

    while(p1->flag == 1)
    {
        n++;
        p1 = new student;
        cout<<"正在创建第 "<<n<<" 个节点"<<endl;
        cout<<"请输入姓名"<<endl;
        cin>>p1->name;
        cout<<"请输入学号"<<endl;
        cin>>p1->num;
        cout<<"请输入成绩"<<endl;
        cin>>p1->socre;
        cout<<"是否继续输入，1、继续，2、结束"<<endl;
        cin>>p1->flag;
        p2->next =p1;
        p2=p1;
    }
    p2->next=NULL;
    return head;
}
int main()
{
    student *p;
    student *head;
    student *p1;
    p =creat_link();
    head=p;
    p1=p;
    for(int i =0;i<n;i++)
    {
        cout<<"姓名："<<p->name<<"\t";
        cout<<"学号："<<p->num<<"\t";
        cout<<"成绩："<<p->socre<<endl;
        p=p->next;
    }
    while(p1!=0)
    {
        head = head->next;
        delete p1;
        p1 = head;
    }
    cout<<"链表删除完毕"<<endl;
    system("pause");
    return 0;
}