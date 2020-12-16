#include <iostream>
#include <string>
#include "WorkerManager.h"
#include "Manager.h"
#include "Employee.h"
#include "Boss.h"
using namespace std;

int main() 
{
	//创建职工管理对象
	WorkerManager wm;
	int value = 0;
	while (true)
	{
		//显示菜单
		wm.Show_Menu();
		cout << "请输入您的选择" << endl;
		cin >> value;
		switch (value)
		{
		case 0:	//退出系统
			wm.Exit_System();
			break;
		case 1:	//添加职工
			wm.Add_Worker();
			break;
		case 2: //显示职工
			wm.Show_worker();
			break;
		case 3:	//删除职工
			wm.Del_worker();
			break;
		case 4:	//修改职工
			wm.Change_worker();
			break;
		case 5:	//查找职工
			wm.Find_worker();
			break;
		case 6:	//排序职工
			wm.Sort_worker();
			break;
		case 7:	//清空文件
			wm.Clear_worker();
			break;
		default: //清空屏幕
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
	
}