#pragma once//����ְ����
#include<iostream>
#include<string>
using namespace std;
class Worker
{
public:
	//չʾ������Ϣ
	virtual void show_self_info() = 0;
	//��ȡ��λ��Ϣ
	virtual string show_dept_info() = 0;


	//����������Ϣ
	int m_id;
	string m_name;
	int m_deptid;
	string m_sex;
	int m_age;
};