#include "Employee.h"

Employee::Employee(int id, string name, int department_id)
{
    this->m_id = id;
    this->m_name = name ;
    this->m_department_id = department_id;
}

void Employee::ShowInfo()
{
    cout<< "ְ����ţ�" << this->m_id
        << "\tְ��������" << this->m_name
        << "\t��λ��" << this->Get_departmen_name() 
        << "\t��λְ����ɾ�����������" << endl;
}

string Employee::Get_departmen_name()
{
    return string("Ա��");
}

