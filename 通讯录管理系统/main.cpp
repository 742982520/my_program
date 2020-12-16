#include <iostream>
#include <string>
using namespace std;
#define MAX 3
struct person    //����ṹ��
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct addressbook   //ͨѶ¼�ṹ��
{
	person person_arry[MAX];
	int num;
};
void add(addressbook* addr)
{
	if (addr->num >= MAX)
	{
		cout << "ͨѶ¼����" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		addr->person_arry[addr->num].name = name;

		int sex;
		cout << "�������Ա� ��1Ϊ�У�0ΪŮ��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 0)
			{
				addr->person_arry[addr->num].sex = sex;
				break;
			}
			cout << "�����������������"<<endl;
		}
		int age;

		cout << "����������" << endl;
		cin >> age;
		addr->person_arry[addr->num].age = age;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		addr->person_arry[addr->num].phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		addr->person_arry[addr->num].address = address;

		addr->num++;
		cout << "�����ϵ�˳ɹ�" << endl;

		system("pause"); 
		system("cls");
	}
}
void change(addressbook* addr)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int flag = 0;
	int i;
	for (i = 0; i < addr->num; i++)
	{
		if (addr->person_arry[i].name == name)
		{
			flag = 1;  //��ʾ�ҵ���
			break;
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		addr->person_arry[i].name = name;

		int sex;
		cout << "�������Ա� ��1Ϊ�У�0ΪŮ��" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 0)
			{
				addr->person_arry[i].sex = sex;
				break;
			}
			cout << "�����������������" << endl;
		}
		int age;

		cout << "����������" << endl;
		cin >> age;
		addr->person_arry[i].address = age;

		string phone;
		cout << "������绰" << endl;
		cin >> phone;
		addr->person_arry[i].phone = phone;

		string address;
		cout << "�������ַ" << endl;
		cin >> address;
		addr->person_arry[i].address = address;

		cout << "�޸���ϵ�˳ɹ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void clean(addressbook* addr)
{
	int flag = 0;
	cout << "�Ƿ����ͨѶ¼��1��ȷ����2��ȡ��" << endl;
	cin >> flag;
	if (flag == 1)
	{
		addr->num = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}
void delete_person(addressbook* addr)
{
	cout << "������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int i;
	int j;
	int flag = 0;  //����һ���ҵ��ı�־��
	for ( i = 0; i < addr->num; i++)
	{
		if (addr->person_arry[i].name == name)
		{
			flag = 1;  //��ʾ�ҵ���
			break;
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		for (j = i; j < addr->num; j++)
		{
			addr->person_arry[j] = addr->person_arry[j + 1];
		}
		addr->num--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void find(addressbook* addr)
{
	cout << "������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int flag = 0;
	int i;
	for (i = 0; i < addr->num; i++)
	{
		if (addr->person_arry[i].name == name)
		{
			flag = 1;  //��ʾ�ҵ���
			break;
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "����:" << addr->person_arry[i].name << "\t";
		cout << "�Ա�:" << (addr->person_arry[i].sex == 1 ? "��" : "Ů") << "\t";
		cout << "����" << addr->person_arry[i].age << "\t";
		cout << "�绰" << addr->person_arry[i].phone << "\t";
		cout << "��ַ" << addr->person_arry[i].address << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void menu_display(void)
{
	cout << "=======================" << endl;
	cout << "==== 1�������ϵ�� ====" << endl;
	cout << "==== 2����ʾ��ϵ�� ====" << endl;
	cout << "==== 3��ɾ����ϵ�� ====" << endl;
	cout << "==== 4��������ϵ�� ====" << endl;
	cout << "==== 5���޸���ϵ�� ====" << endl;
	cout << "==== 6�������ϵ�� ====" << endl;
	cout << "==== 0���˳�ͨѶ¼ ====" << endl;
	cout << "=======================" << endl;
}
void show(addressbook* addr)
{
	if (addr->num == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < addr->num; i++)
		{
			cout << "������" << addr->person_arry[i].name << "\t";
			cout << "�Ա�" << (addr->person_arry[i].sex == 1 ? "��" : "Ů" )<< "\t";
			cout << "���䣺" << addr->person_arry[i].age << "\t";
			cout << "�绰:" << addr->person_arry[i].phone << "\t";
			cout << "��ַ��" << addr->person_arry[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
int main()
{   
    addressbook address_book;
    address_book.num = 0;  //��һ��ʹ�ã��Ƚ���������
    while (1)
    {
        int select;
        menu_display();
        cin >> select;
        switch (select)
        {
        case 1: //�����ϵ��
            add(&address_book);
            break;
        case 2:  //��ʾ��ϵ��
            show(&address_book);
            break;
        case 3:  //ɾ����ϵ��
            delete_person(&address_book);
            break;
        case 4:   //������ϵ��
            find(&address_book);
            break;
        case 5:   //�޸���ϵ��
            change(&address_book);
            break;
        case 6:   //�����ϵ��
            clean(&address_book);
            break;
        case 0:   //�˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            system("cls");
        }
    }
    system("pause");  //����ʾ�밴���������
    return 0;
}