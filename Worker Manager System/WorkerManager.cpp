#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(SAVA_PATH,ios::in);

	//如果文件不存在
	if(!ifs.is_open())
	{
		cout << "文件不存在" <<endl; 
		//初始化员工人数
		this->m_worker_num = 0;
		//空文件标志位置1
		this->m_file_empty = true;
		//初始化数组指针
		this->m_worker_arry = NULL;
		ifs.close();
		return;
	}

	//如果文件存在，但是是空的
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		cout << "文件是空的" <<endl; 
		//初始化员工人数
		this->m_worker_num = 0;
		//空文件标志位置1
		this->m_file_empty = true;
		//初始化数组指针
		this->m_worker_arry = NULL;
		ifs.close();
		return;	
	}

	//如果文件存在，并且存放了数据，则获取数据条数，并且更新员工数量
	int num = this->Get_num();
	cout << "职工个数为：" << num << endl;
	this->m_worker_num = num;

	//根据获得的职工数，来开辟空间并用二级指针来管理
	this->m_worker_arry = new Worker *[this->m_worker_num];
	this->m_file_empty = false;
	//初始化职工数组
	Init_worker();
	
	// for(int i = 0; i < m_worker_num;i++)
	// {
	// 	cout << " 职工号：" << this->m_worker_arry[i]->m_id
	// 		<< " 职工姓名："<< this->m_worker_arry[i]->m_name
	// 		<< " 部门编号："<< this->m_worker_arry[i]->m_department_id<<endl;
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
	cout << "******* 欢迎使用职工管理系统 *******" << endl;
	cout << "********** 0.退出管理程序 **********" << endl;
	cout << "********** 1.增加职工信息 **********" << endl;
	cout << "********** 2.显示职工信息 **********" << endl;
	cout << "********** 3.删除离职职工 **********" << endl;
	cout << "********** 4.修改职工信息 **********" << endl;
	cout << "********** 5.查找职工信息 **********" << endl;
	cout << "********** 6.按照编号排序 **********" << endl;
	cout << "********** 7.清空所有文档 **********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

void WorkerManager::Exit_System()
{
	cout << "欢迎下次使用" << endl;
	system("pause"); //会出现请按任意键继续，不会直接闪退  
	exit(0);
}

void WorkerManager::Add_Worker()
{
	cout << "请输入添加员工的数量"<< endl;

	int add_num = 0;
	cin >> add_num;

	if(add_num > 0)
	{
		//计算添加后需要开辟的内存空间
		int new_size = this->m_worker_num + add_num;

		//根据员工的数据来开辟一段内存，存放指向员工对象的指针，并用二级指针来管理
		Worker **ptr = new Worker*[new_size];
		
		//将原本空间的内容放到新的内存中
		if(this->m_worker_arry != 0) //m_worker_arry不为零，说明原本有存储的数据见
		{	
			for(int i=0;i<this->m_worker_num;i++)
			{
				ptr[i] = this->m_worker_arry[i];
			}
		}

		//释放原本的内存空间
		delete[] this->m_worker_arry;
		this->m_worker_arry = 0;

		//更新内存指针的指向,指向新的内存地址
		this->m_worker_arry = ptr;

		//添加数据,添加add_num个数据
		for(int i; i<add_num;i++)
		{
			int id;
			string name;
			int department_id;
			
			cout << "请输入第 " << i+1 <<" 个新员工的编号" <<endl;
			cin >> id;

			cout << "请输入第 " << i+1 <<" 个新员工的姓名" <<endl;
			cin >> name;

			cout << "请选择员工的岗位" <<endl;
			cout << "1、普通职工" <<endl;
			cout << "2、经理" <<endl;
			cout << "3、老板" <<endl;
			cin >> department_id;
			//根据职位的不同，调用不同的初始化函数
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
			//将员工对象保存到数组中
			ptr[this->m_worker_num + i] = worker;
 		}
		//更新员工的个数
		this->m_worker_num = new_size;

		//提示信息
		cout << "成功添加" << add_num << " 名新员工" <<endl;

		//更新内容不为空的标志
		this->m_file_empty = false;
		//保存员工信息
		this->Save();
	}
	else
	{
		cout << "输入错误" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::Save()
{
	//创建输出流对象
	ofstream ofs;

	//指定写入文件的路径和打开的方式
	ofs.open(SAVA_PATH,ios::out);

	//写入数据
	for(int i = 0; i < this->m_worker_num; i++)
	{
		ofs << this->m_worker_arry[i]->m_id << " "
			<< this->m_worker_arry[i]->m_name << " "
			<< this->m_worker_arry[i]->m_department_id << " "
			<< endl;
	}
	//关闭文件
	ofs.close();
}
int WorkerManager::Get_num()
{
	//创建输入流对象
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
	//创建输入流对象
	ifstream ifs;

	//打开文件
	ifs.open(SAVA_PATH, ios::in);

	int id;
	string name;
	int department_id;
	
	int i = 0;
	while(ifs >> id && ifs >> name && ifs >> department_id)
	{
		//创建一个员工指针
		Worker *worker = NULL;

		//根据department_id来创建不同的员工
		if(department_id == 1)	//普通员工
		{
			worker = new Employee(id, name, department_id);
		}
		if(department_id == 2)	//经理
		{
			worker = new Manager(id, name, department_id);
		}
		if(department_id == 3)	//老板
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
		cout << "文件不存在或者记录为空" << endl;
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
		cout << "文件不存在或者记录为空" <<endl;
	}
	else
	{
		//输入职工编号然后删除
		cout << "请输入要删除的职工的编号" <<endl;
		int id = 0;
		cin >> id;
		//判断职工是否存在
		int flag = this->Is_exist(id);
		cout << "员工所在的位置为" << flag << endl;
		if(flag == -1)
		{
			cout << "该员工不存在" <<endl;
		}
		else
		{
			//i最大应该到倒数第二个
			for(int i = flag ; i < this->m_worker_num-1;i++)
			{
				this->m_worker_arry[i] = this->m_worker_arry[i+1];
			}
			this->m_worker_num--;
			this->Save();
			cout << "删除员工成功" <<endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::Change_worker()
{
	if(this->m_file_empty == true)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工的编号" << endl;
		int id;
		cin >> id;

		int position = this->Is_exist(id);
		if(position == -1)
		{
			cout << "未查找到编号为 " << id << " 的员工" << endl;
		}
		else
		{
			//因为修改过后职位可能发生变化，因此对应的类型也会发生变化，因此需要重新开辟内存
			delete this->m_worker_arry[position];

			int new_id;
			string new_name;
			int new_department_id;

			cout << "已查找到编号为 " << id << " 的员工" << endl;

			cout << "请输入新的编号" << endl;
			cin >> new_id;
			cout << "请输入新姓名" << endl;
			cin >> new_name;
			cout << "请输入新职位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			cout << "职工信息修改成功" << endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择查找的方式" << endl;
		cout << "1、按编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >> select;
		string name;
		int position;
		switch (select)
		{
		case 1:
			cout << "请输入要查找的职工的编号" << endl;
			int id;
			cin >> id;
			position = this->Is_exist(id);
			if(position == -1)
			{
				cout << "未查找到编号为 " << id << " 的员工" << endl;
			}
			else
			{
				cout << "已查找到编号为 " << id << " 的员工" << endl;
				this->m_worker_arry[position]->ShowInfo();
			}	
			break;
		case 2:
			cout << "请输入要查找的姓名" << endl;
			cin >> name;
			for(int i = 0;i < this->m_worker_num;i++)
			{
				if(this->m_worker_arry[i]->m_name == name)
				{
					cout << "已查找找到姓名为 " << name <<" 的员工" <<endl;
					this->m_worker_arry[i]->ShowInfo();
					break;
				}
			}
			cout << "未查找找到姓名为 " << name <<" 的员工" <<endl;
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序的方式" << endl;
		cout << "1、按编号升序排序" << endl;
		cout << "2、按编号降序排序" << endl;
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
		cout << "排序成功，结果如下" << endl;
		this->Show_worker(); 
	}
}

void WorkerManager::Clear_worker()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;
	
	int select = 0;
	cin >> select;
	if(select == 1)
	{
		//创建输出流文件，如果文件存在，则删除重新创建
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
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}