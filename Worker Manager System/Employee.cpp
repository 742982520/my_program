#include "Employee.h"

Employee::Employee(int id, string name, int department_id)
{
    this->m_id = id;
    this->m_name = name ;
    this->m_department_id = department_id;
}

void Employee::ShowInfo()
{
    cout<< "职工编号：" << this->m_id
        << "\t职工姓名：" << this->m_name
        << "\t岗位：" << this->Get_departmen_name() 
        << "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::Get_departmen_name()
{
    return string("员工");
}

