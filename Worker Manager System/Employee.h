#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Employee : public Worker
{
public:
    //Ա������Ĺ��캯�������ڴ������
    Employee(int id, string name, int department_id);

    //��ʾ������Ϣ
    virtual void ShowInfo();

    //��ȡְ����λ����
    virtual string Get_departmen_name();

};