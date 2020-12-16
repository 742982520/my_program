#include "Manager.h"

Manager::Manager(int id, string name, int department_id)
{
    this->m_id = id;
    this->m_name = name;
    this->m_department_id = department_id;
}

void Manager::ShowInfo()
{
    cout<< "职工编号：" << this->m_id
        << "\t职工姓名：" << this->m_name
        << "\t岗位：" << this->Get_departmen_name() 
        << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::Get_departmen_name()
{
    return string("员工");
}