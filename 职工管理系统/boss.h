#pragma once//�ϰ���
#include<iostream>
#include<string>
#include"worker.h"
class Boss :public Worker
{
public:
	Boss(int m_id, string m_name, int m_deptid, string m_sex, int m_age);
	void show_self_info() override;
	//��ȡ��λ��Ϣ
	string show_dept_info() override ;

};
