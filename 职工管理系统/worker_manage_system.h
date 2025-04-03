#pragma once
#include<iostream>
#include"worker.h"
#include"employer.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "emp_file.txt"//定义写入信息的保存文件
using namespace std;
//创建员工管理类
class Worker_manage_system
{
public:
	Worker_manage_system();
	~Worker_manage_system();
	//展示菜单
	void showmenu();
	//退出系统
	void exit_system();
	//记录职工人数
	int m_emp_num;
	//职工数组指针
	Worker** m_emp_array;
	//文件存在判断
	 bool is_file_empty;
	//添加新职工
	void add_emp();
	//保存文件
	void save();
	//统计当文件已经有内容时到底有多少人
	int get_emp_num();
	//初始化职工
	void ini_emp();
	//展示职工信息
	void show_emp();
	//根据id判断职工是否存在
	int is_emp_exist(int id);
	//删除职工
	void del_emp();
	//修改职工信息
	void mod_emp();
	//查找职工
	void find_emp();
	//按id为职工排序
	void sort_emp();
	//清空职工信息
	void clean_emp();
};