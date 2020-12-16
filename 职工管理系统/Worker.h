#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
    int m_id;
    string m_name;
    int m_department_id;
public:
    virtual void ShowInfo() = 0;
    virtual string Get_departmen_name() = 0;
};