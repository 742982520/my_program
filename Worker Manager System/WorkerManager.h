#pragma once  //��ֹͷ�ļ��ظ����� 
#include <iostream>
#include <string>

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
using namespace std;  //ʹ�ñ�׼�����ռ�

#define	SAVA_PATH "data.txt"
class WorkerManager
{
public:
    //��ǰ�����Ա��������
    int m_worker_num;
    Worker **m_worker_arry;
	bool m_file_empty;
public:
	//���캯��
	WorkerManager();

	//��������
	~WorkerManager();

	//չʾ�˵�
	void Show_Menu();
	
	//�˳�ϵͳ
	void Exit_System();

    //����ְ��
    void Add_Worker();

	//��������
	void Save();

	//ͳ���ļ��е�����
	int Get_num();

	//���ݶ�ȡ������ ��ʼ��Ա������
	void Init_worker();

	//��ʾְ��
	void Show_worker();

	//�ж�ְ���Ƿ����
	int Is_exist(int id);

	//ɾ��ְ��
	void Del_worker();

	//�޸�ְ��
	void Change_worker();

	//����
	void Find_worker();

	//����
	void Sort_worker();

	//���Ա��
	void Clear_worker();
};



