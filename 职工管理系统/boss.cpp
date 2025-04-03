#include"boss.h"
#include"worker.h"
Boss::Boss(int m_id, string m_name, int m_deptid, string m_sex, int m_age)
{
	this->m_id = m_id;
	this->m_name = m_name;
	this->m_deptid = m_deptid;
	this->m_sex = m_sex;
	this->m_age = m_age;
}
void Boss::show_self_info()
{
	cout << "职工姓名：" << this->m_name
		<< "\t职工性别：" << this->m_sex
		<< "\t职工年龄：" << this->m_age
		<< "\t职工编号：" << this->m_id
		<< "\t职工岗位：" << this->show_dept_info()
		<< "\t职工职责：" << "管理公司各项事务" << endl;
}
string Boss::show_dept_info()
{
	return string("总裁");
}