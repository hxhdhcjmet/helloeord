#include"employer.h"
#include"worker.h"
Employer::Employer(int m_id, const string& m_name, int m_deptid, const string& m_sex,int m_age)
{
	this->m_id = m_id;
	this->m_name = m_name;
	this->m_deptid = m_deptid;
	this->m_sex = m_sex;
	this->m_age = m_age;
}
void Employer::show_self_info()
{
	cout << "ְ��������" << this->m_name
		<< "\tְ���Ա�" << this->m_sex
		<< "\tְ�����䣺" << this->m_age
		<< "\tְ����ţ�" << this->m_id
		<< "\tְ����λ��" << this->show_dept_info()
		<< "\tְ��ְ��" << "��ɾ�����������" << endl;
 }
string Employer::show_dept_info()
{
	return string("��ͨԱ��");
 }
