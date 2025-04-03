#pragma once//抽象职工类
#include<iostream>
#include<string>
using namespace std;
class Worker
{
public:
	//展示个人信息
	virtual void show_self_info() = 0;
	//获取岗位信息
	virtual string show_dept_info() = 0;


	//个人属性信息
	int m_id;
	string m_name;
	int m_deptid;
	string m_sex;
	int m_age;
};