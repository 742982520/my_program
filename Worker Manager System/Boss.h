#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Boss : public Worker
{
public:
    //�ϰ����Ĺ��캯��
    Boss(int id, string name, int department_id);

    //��ʾ��Ϣ
    virtual void ShowInfo();

    //��ȡԱ����λ����
    virtual string Get_departmen_name();
};