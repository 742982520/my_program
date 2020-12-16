#include <iostream>
#include <string>
using namespace std;
#define MAX 3
struct person    //人物结构体
{
	string name;
	int sex;
	int age;
	string phone;
	string address;
};

struct addressbook   //通讯录结构体
{
	person person_arry[MAX];
	int num;
};
void add(addressbook* addr)
{
	if (addr->num >= MAX)
	{
		cout << "通讯录已满" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		addr->person_arry[addr->num].name = name;

		int sex;
		cout << "请输入性别 （1为男，0为女）" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 0)
			{
				addr->person_arry[addr->num].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入"<<endl;
		}
		int age;

		cout << "请输入年龄" << endl;
		cin >> age;
		addr->person_arry[addr->num].age = age;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		addr->person_arry[addr->num].phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		addr->person_arry[addr->num].address = address;

		addr->num++;
		cout << "添加联系人成功" << endl;

		system("pause"); 
		system("cls");
	}
}
void change(addressbook* addr)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int flag = 0;
	int i;
	for (i = 0; i < addr->num; i++)
	{
		if (addr->person_arry[i].name == name)
		{
			flag = 1;  //表示找到了
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
		cout << "请输入姓名" << endl;
		cin >> name;
		addr->person_arry[i].name = name;

		int sex;
		cout << "请输入性别 （1为男，0为女）" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 0)
			{
				addr->person_arry[i].sex = sex;
				break;
			}
			cout << "输入错误，请重新输入" << endl;
		}
		int age;

		cout << "请输入年龄" << endl;
		cin >> age;
		addr->person_arry[i].address = age;

		string phone;
		cout << "请输入电话" << endl;
		cin >> phone;
		addr->person_arry[i].phone = phone;

		string address;
		cout << "请输入地址" << endl;
		cin >> address;
		addr->person_arry[i].address = address;

		cout << "修改联系人成功" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void clean(addressbook* addr)
{
	int flag = 0;
	cout << "是否清空通讯录（1）确定（2）取消" << endl;
	cin >> flag;
	if (flag == 1)
	{
		addr->num = 0;
		cout << "通讯录已清空" << endl;
	}
	system("pause");
	system("cls");
}
void delete_person(addressbook* addr)
{
	cout << "请输入要删除的联系人" << endl;
	string name;
	cin >> name;
	int i;
	int j;
	int flag = 0;  //定义一个找到的标志；
	for ( i = 0; i < addr->num; i++)
	{
		if (addr->person_arry[i].name == name)
		{
			flag = 1;  //表示找到了
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void find(addressbook* addr)
{
	cout << "请输入要查找的联系人" << endl;
	string name;
	cin >> name;
	int flag = 0;
	int i;
	for (i = 0; i < addr->num; i++)
	{
		if (addr->person_arry[i].name == name)
		{
			flag = 1;  //表示找到了
			break;
		}
		else
		{
			flag = 0;
		}
	}
	if (flag == 1)
	{
		cout << "姓名:" << addr->person_arry[i].name << "\t";
		cout << "性别:" << (addr->person_arry[i].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄" << addr->person_arry[i].age << "\t";
		cout << "电话" << addr->person_arry[i].phone << "\t";
		cout << "地址" << addr->person_arry[i].address << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void menu_display(void)
{
	cout << "=======================" << endl;
	cout << "==== 1、添加联系人 ====" << endl;
	cout << "==== 2、显示联系人 ====" << endl;
	cout << "==== 3、删除联系人 ====" << endl;
	cout << "==== 4、查找联系人 ====" << endl;
	cout << "==== 5、修改联系人 ====" << endl;
	cout << "==== 6、清空联系人 ====" << endl;
	cout << "==== 0、退出通讯录 ====" << endl;
	cout << "=======================" << endl;
}
void show(addressbook* addr)
{
	if (addr->num == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < addr->num; i++)
		{
			cout << "姓名：" << addr->person_arry[i].name << "\t";
			cout << "性别：" << (addr->person_arry[i].sex == 1 ? "男" : "女" )<< "\t";
			cout << "年龄：" << addr->person_arry[i].age << "\t";
			cout << "电话:" << addr->person_arry[i].phone << "\t";
			cout << "地址：" << addr->person_arry[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
int main()
{   
    addressbook address_book;
    address_book.num = 0;  //第一次使用，先将人数清零
    while (1)
    {
        int select;
        menu_display();
        cin >> select;
        switch (select)
        {
        case 1: //添加联系人
            add(&address_book);
            break;
        case 2:  //显示联系人
            show(&address_book);
            break;
        case 3:  //删除联系人
            delete_person(&address_book);
            break;
        case 4:   //查找联系人
            find(&address_book);
            break;
        case 5:   //修改联系人
            change(&address_book);
            break;
        case 6:   //清空联系人
            clean(&address_book);
            break;
        case 0:   //退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            system("cls");
        }
    }
    system("pause");  //会显示请按任意键继续
    return 0;
}