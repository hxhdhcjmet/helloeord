#pragma once
#include<iostream>
#include"worker.h"
#include"employer.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "emp_file.txt"//����д����Ϣ�ı����ļ�
using namespace std;
//����Ա��������
class Worker_manage_system
{
public:
	Worker_manage_system(const Worker_manage_system&)=delete;
	void operator=(const Worker_manage_system&)=delete; 
	Worker_manage_system();
	~Worker_manage_system();
	//չʾ�˵�
	void showmenu();
	//�˳�ϵͳ
	void exit_system();
	//��¼ְ������
	int m_emp_num;
	//ְ������ָ��
	Worker** m_emp_array;
	//�ļ������ж�
	 bool is_file_empty;
	//�����ְ��
	void add_emp();
	//�����ļ�
	void save();
	//ͳ�Ƶ��ļ��Ѿ�������ʱ�����ж�����
	int get_emp_num();
	//��ʼ��ְ��
	void ini_emp();
	//չʾְ����Ϣ
	void show_emp();
	//����id�ж�ְ���Ƿ����
	int is_emp_exist(int id);
	//ɾ��ְ��
	void del_emp();
	//�޸�ְ����Ϣ
	void mod_emp();
	//����ְ��
	void find_emp();
	//��idΪְ������
	void sort_emp();
	//���ְ����Ϣ
	void clean_emp();
};
