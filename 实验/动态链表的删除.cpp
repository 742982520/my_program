#include <iostream>
#include <string>
using namespace std;
int n=1;
struct student
{
    string name;
    int num;
    int socre;
    int flag;  //�����������ı�־
    struct student *next;  //ָ����һ���ṹ���ָ��
};
student *creat_link(void)
{
    student *head ; //�����ͷָ��
    student *p1;
    student *p2;

    head = new student;  //head ��Ϊ�������ͷ��ָ���һ�����ٵĽṹ��ռ�
    p1 = head;  //p1ָ���һ������
    p2 = head;  //p2ָ���һ������
    //��ʼ����һ���ڵ�
    cout<<"���ڴ�����1���ڵ�"<<endl;
    cout<<"����������"<<endl;
    cin>>p1->name;
    cout<<"������ѧ��"<<endl;
    cin>>p1->num;
    cout<<"������ɼ�"<<endl;
    cin>>p1->socre;
    cout<<"�Ƿ�������룬1��������2������"<<endl;
    cin>>p1->flag;

    while(p1->flag == 1)
    {
        n++;
        p1 = new student;
        cout<<"���ڴ����� "<<n<<" ���ڵ�"<<endl;
        cout<<"����������"<<endl;
        cin>>p1->name;
        cout<<"������ѧ��"<<endl;
        cin>>p1->num;
        cout<<"������ɼ�"<<endl;
        cin>>p1->socre;
        cout<<"�Ƿ�������룬1��������2������"<<endl;
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
        cout<<"������"<<p->name<<"\t";
        cout<<"ѧ�ţ�"<<p->num<<"\t";
        cout<<"�ɼ���"<<p->socre<<endl;
        p=p->next;
    }
    while(p1!=0)
    {
        head = head->next;
        delete p1;
        p1 = head;
    }
    cout<<"����ɾ�����"<<endl;
    system("pause");
    return 0;
}