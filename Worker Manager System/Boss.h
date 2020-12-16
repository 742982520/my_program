#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Boss : public Worker
{
public:
    //老板对象的构造函数
    Boss(int id, string name, int department_id);

    //显示信息
    virtual void ShowInfo();

    //获取员工岗位名称
    virtual string Get_departmen_name();
};