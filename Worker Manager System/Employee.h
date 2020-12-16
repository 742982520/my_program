#pragma once
#include <iostream>
#include <string>
#include "Worker.h"
using namespace std;

class Employee : public Worker
{
public:
    //员工对象的构造函数，用于传入参数
    Employee(int id, string name, int department_id);

    //显示个人信息
    virtual void ShowInfo();

    //获取职工岗位名称
    virtual string Get_departmen_name();

};