#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(SAVA_PATH,ios::in);

	//����ļ�������
	if(!ifs.is_open())
	{
		cout << "�ļ�������" <<endl; 
		//��ʼ��Ա������
		this->m_worker_num = 0;
		//���ļ���־λ��1
		this->m_file_empty = true;
		//��ʼ������ָ��
		this->m_worker_arry = NULL;
		ifs.close();
		return;
	}

	//����ļ����ڣ������ǿյ�
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		cout << "�ļ��ǿյ�" <<endl; 
		//��ʼ��Ա������
		this->m_worker_num = 0;
		//���ļ���־λ��1
		this->m_file_empty = true;
		//��ʼ������ָ��
		this->m_worker_arry = NULL;
		ifs.close();
		return;	
	}

	//����ļ����ڣ����Ҵ�������ݣ����ȡ�������������Ҹ���Ա������
	int num = this->Get_num();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_worker_num = num;

	//���ݻ�õ�ְ�����������ٿռ䲢�ö���ָ��������
	this->m_worker_arry = new Worker *[this->m_worker_num];
	this->m_file_empty = false;
	//��ʼ��ְ������
	Init_worker();
	
	// for(int i = 0; i < m_worker_num;i++)
	// {
	// 	cout << " ְ���ţ�" << this->m_worker_arry[i]->m_id
	// 		<< " ְ��������"<< this->m_worker_arry[i]->m_name
	// 		<< " ���ű�ţ�"<< this->m_worker_arry[i]->m_department_id<<endl;
	// }
}

WorkerManager::~WorkerManager()
{
	if(this->m_worker_arry != NULL)
	{
		delete[] this->m_worker_arry;
		this->m_worker_arry = NULL;
	}
}

void WorkerManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******* ��ӭʹ��ְ������ϵͳ *******" << endl;
	cout << "********** 0.�˳�������� **********" << endl;
	cout << "********** 1.����ְ����Ϣ **********" << endl;
	cout << "********** 2.��ʾְ����Ϣ **********" << endl;
	cout << "********** 3.ɾ����ְְ�� **********" << endl;
	cout << "********** 4.�޸�ְ����Ϣ **********" << endl;
	cout << "********** 5.����ְ����Ϣ **********" << endl;
	cout << "********** 6.���ձ������ **********" << endl;
	cout << "********** 7.��������ĵ� **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause"); //������밴���������������ֱ������  
	exit(0);
}

void WorkerManager::Add_Worker()
{
	cout << "���������Ա��������"<< endl;

	int add_num = 0;
	cin >> add_num;

	if(add_num > 0)
	{
		//������Ӻ���Ҫ���ٵ��ڴ�ռ�
		int new_size = this->m_worker_num + add_num;

		//����Ա��������������һ���ڴ棬���ָ��Ա�������ָ�룬���ö���ָ��������
		Worker **ptr = new Worker*[new_size];
		
		//��ԭ���ռ�����ݷŵ��µ��ڴ���
		if(this->m_worker_arry != 0) //m_worker_arry��Ϊ�㣬˵��ԭ���д洢�����ݼ�
		{	
			for(int i=0;i<this->m_worker_num;i++)
			{
				ptr[i] = this->m_worker_arry[i];
			}
		}

		//�ͷ�ԭ�����ڴ�ռ�
		delete[] this->m_worker_arry;
		this->m_worker_arry = 0;

		//�����ڴ�ָ���ָ��,ָ���µ��ڴ��ַ
		this->m_worker_arry = ptr;

		//�������,���add_num������
		for(int i; i<add_num;i++)
		{
			int id;
			string name;
			int department_id;
			
			cout << "������� " << i+1 <<" ����Ա���ı��" <<endl;
			cin >> id;

			cout << "������� " << i+1 <<" ����Ա��������" <<endl;
			cin >> name;

			cout << "��ѡ��Ա���ĸ�λ" <<endl;
			cout << "1����ְͨ��" <<endl;
			cout << "2������" <<endl;
			cout << "3���ϰ�" <<endl;
			cin >> department_id;
			//����ְλ�Ĳ�ͬ�����ò�ͬ�ĳ�ʼ������
			Worker * worker = NULL;
			switch(department_id)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;	
			default:
				break;
			}
			//��Ա�����󱣴浽������
			ptr[this->m_worker_num + i] = worker;
 		}
		//����Ա���ĸ���
		this->m_worker_num = new_size;

		//��ʾ��Ϣ
		cout << "�ɹ����" << add_num << " ����Ա��" <<endl;

		//�������ݲ�Ϊ�յı�־
		this->m_file_empty = false;
		//����Ա����Ϣ
		this->Save();
	}
	else
	{
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	//�������������
	ofstream ofs;

	//ָ��д���ļ���·���ʹ򿪵ķ�ʽ
	ofs.open(SAVA_PATH,ios::out);

	//д������
	for(int i = 0; i < this->m_worker_num; i++)
	{
		ofs << this->m_worker_arry[i]->m_id << " "
			<< this->m_worker_arry[i]->m_name << " "
			<< this->m_worker_arry[i]->m_department_id << " "
			<< endl;
	}
	//�ر��ļ�
	ofs.close();
}
int WorkerManager::Get_num()
{
	//��������������
	ifstream ifs;

	ifs.open(SAVA_PATH,ios::in);

	int id;
	string name;
	int department_id;

	int num = 0;
	while(ifs >> id && ifs >> name && ifs >> department_id)
	{
		num++;
	}
	return num;
}
void WorkerManager::Init_worker()
{
	//��������������
	ifstream ifs;

	//���ļ�
	ifs.open(SAVA_PATH, ios::in);

	int id;
	string name;
	int department_id;
	
	int i = 0;
	while(ifs >> id && ifs >> name && ifs >> department_id)
	{
		//����һ��Ա��ָ��
		Worker *worker = NULL;

		//����department_id��������ͬ��Ա��
		if(department_id == 1)	//��ͨԱ��
		{
			worker = new Employee(id, name, department_id);
		}
		if(department_id == 2)	//����
		{
			worker = new Manager(id, name, department_id);
		}
		if(department_id == 3)	//�ϰ�
		{
			worker = new Boss(id, name, department_id);
		}
		this->m_worker_arry[i] = worker;
		i++;
	}
}

void WorkerManager::Show_worker()
{
	if(this->m_file_empty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		for(int i = 0; i<this->m_worker_num; i++)
		{
			this->m_worker_arry[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::Is_exist(int id)
{
	int position = -1;
	for(int i =0;i < this->m_worker_num; i++)
	{
		if(this->m_worker_arry[i]->m_id == id)
		{
			position = i;
			return position;
		}
	}
	return position;
}

void WorkerManager::Del_worker()
{
	if(this->m_file_empty == true)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" <<endl;
	}
	else
	{
		//����ְ�����Ȼ��ɾ��
		cout << "������Ҫɾ����ְ���ı��" <<endl;
		int id = 0;
		cin >> id;
		//�ж�ְ���Ƿ����
		int flag = this->Is_exist(id);
		cout << "Ա�����ڵ�λ��Ϊ" << flag << endl;
		if(flag == -1)
		{
			cout << "��Ա��������" <<endl;
		}
		else
		{
			//i���Ӧ�õ������ڶ���
			for(int i = flag ; i < this->m_worker_num-1;i++)
			{
				this->m_worker_arry[i] = this->m_worker_arry[i+1];
			}
			this->m_worker_num--;
			this->Save();
			cout << "ɾ��Ա���ɹ�" <<endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::Change_worker()
{
	if(this->m_file_empty == true)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ���ı��" << endl;
		int id;
		cin >> id;

		int position = this->Is_exist(id);
		if(position == -1)
		{
			cout << "δ���ҵ����Ϊ " << id << " ��Ա��" << endl;
		}
		else
		{
			//��Ϊ�޸Ĺ���ְλ���ܷ����仯����˶�Ӧ������Ҳ�ᷢ���仯�������Ҫ���¿����ڴ�
			delete this->m_worker_arry[position];

			int new_id;
			string new_name;
			int new_department_id;

			cout << "�Ѳ��ҵ����Ϊ " << id << " ��Ա��" << endl;

			cout << "�������µı��" << endl;
			cin >> new_id;
			cout << "������������" << endl;
			cin >> new_name;
			cout << "��������ְλ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> new_department_id;

			Worker * worker = NULL;
			switch(new_department_id)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_department_id);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_department_id);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_department_id);
				break;
			default:
				break;
			}
			this->m_worker_arry[position] = worker;
			cout << "ְ����Ϣ�޸ĳɹ�" << endl;
			this->Save();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_worker()
{
	if(this->m_file_empty == true)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҵķ�ʽ" << endl;
		cout << "1������Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;
		string name;
		int position;
		switch (select)
		{
		case 1:
			cout << "������Ҫ���ҵ�ְ���ı��" << endl;
			int id;
			cin >> id;
			position = this->Is_exist(id);
			if(position == -1)
			{
				cout << "δ���ҵ����Ϊ " << id << " ��Ա��" << endl;
			}
			else
			{
				cout << "�Ѳ��ҵ����Ϊ " << id << " ��Ա��" << endl;
				this->m_worker_arry[position]->ShowInfo();
			}	
			break;
		case 2:
			cout << "������Ҫ���ҵ�����" << endl;
			cin >> name;
			for(int i = 0;i < this->m_worker_num;i++)
			{
				if(this->m_worker_arry[i]->m_name == name)
				{
					cout << "�Ѳ����ҵ�����Ϊ " << name <<" ��Ա��" <<endl;
					this->m_worker_arry[i]->ShowInfo();
					break;
				}
			}
			cout << "δ�����ҵ�����Ϊ " << name <<" ��Ա��" <<endl;
			break;
		default:
			break;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_worker()
{
	if(this->m_file_empty == true)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ķ�ʽ" << endl;
		cout << "1���������������" << endl;
		cout << "2������Ž�������" << endl;
		int select = 0;
		cin >> select;
		Worker *temp = NULL;
		if(select == 1)
		{
			for(int i = 0; i < this->m_worker_num-1;i++)
			{
				for(int j = 0; j < this->m_worker_num-1-i;j++)
				{
					if(this->m_worker_arry[j]->m_id > this->m_worker_arry[j+1]->m_id)
					{
						temp = this->m_worker_arry[j];
						this->m_worker_arry[j] = this->m_worker_arry[j+1];
						this->m_worker_arry[j+1] = temp;
					}
				}
			}
		}
		else if (select == 2)
		{
			for(int i = 0; i < this->m_worker_num -1;i++)
			{
				for(int j = 0; j < this->m_worker_num-1-i;j++)
				{
					if(this->m_worker_arry[j]->m_id < this->m_worker_arry[j+1]->m_id)
					{
						temp = this->m_worker_arry[j];
						this->m_worker_arry[j] = this->m_worker_arry[j+1];
						this->m_worker_arry[j+1] = temp;
					}
				}
			}
		}
		this->Save();
		cout << "����ɹ����������" << endl;
		this->Show_worker(); 
	}
}

void WorkerManager::Clear_worker()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;
	
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		//����������ļ�������ļ����ڣ���ɾ�����´���
		ofstream ofs(SAVA_PATH,ios::trunc);
		ofs.close();

		if(this->m_worker_arry != NULL)
		{
			for(int i = 0;i < this->m_worker_num;i++)
			{
				if(this->m_worker_arry[i] != NULL)
				{
					delete this->m_worker_arry[i];
				}
			}
			this->m_worker_num = 0;
			delete[] this->m_worker_arry;
			this->m_worker_arry = NULL;
			this->m_file_empty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}