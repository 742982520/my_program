#include <iostream>
#include <string>
#include "WorkerManager.h"
#include "Manager.h"
#include "Employee.h"
#include "Boss.h"
using namespace std;

int main() 
{
	//����ְ���������
	WorkerManager wm;
	int value = 0;
	while (true)
	{
		//��ʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> value;
		switch (value)
		{
		case 0:	//�˳�ϵͳ
			wm.Exit_System();
			break;
		case 1:	//���ְ��
			wm.Add_Worker();
			break;
		case 2: //��ʾְ��
			wm.Show_worker();
			break;
		case 3:	//ɾ��ְ��
			wm.Del_worker();
			break;
		case 4:	//�޸�ְ��
			wm.Change_worker();
			break;
		case 5:	//����ְ��
			wm.Find_worker();
			break;
		case 6:	//����ְ��
			wm.Sort_worker();
			break;
		case 7:	//����ļ�
			wm.Clear_worker();
			break;
		default: //�����Ļ
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
	
}