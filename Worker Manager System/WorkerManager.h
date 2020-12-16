#pragma once  //防止头文件重复包含 
#include <iostream>
#include <string>

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#include <fstream>
using namespace std;  //使用标准命名空间

#define	SAVA_PATH "data.txt"
class WorkerManager
{
public:
    //当前储存的员工的人数
    int m_worker_num;
    Worker **m_worker_arry;
	bool m_file_empty;
public:
	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	//展示菜单
	void Show_Menu();
	
	//退出系统
	void Exit_System();

    //增加职工
    void Add_Worker();

	//保存数据
	void Save();

	//统计文件中的人数
	int Get_num();

	//根据读取的数据 初始化员工数组
	void Init_worker();

	//显示职工
	void Show_worker();

	//判断职工是否存在
	int Is_exist(int id);

	//删除职工
	void Del_worker();

	//修改职工
	void Change_worker();

	//查找
	void Find_worker();

	//排序
	void Sort_worker();

	//清空员工
	void Clear_worker();
};



