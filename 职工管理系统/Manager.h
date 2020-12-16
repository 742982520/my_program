#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Manager : public Worker
{
public:  
    //经理对象的构造函数
    Manager(int id, string name, int department_id);

    //显示信息
    virtual void ShowInfo();

    //获取职工岗位名称
    virtual string Get_departmen_name();
};