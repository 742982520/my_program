#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Manager : public Worker
{
public:  
    //�������Ĺ��캯��
    Manager(int id, string name, int department_id);

    //��ʾ��Ϣ
    virtual void ShowInfo();

    //��ȡְ����λ����
    virtual string Get_departmen_name();
};