#include<iostream>
#include"worker_manage_system.h"
#include"author.h"
#include"worker.h"
#include"employer.h"
#include"manager.h"
#include"boss.h"
using namespace std;
int main()
{
	
	Worker_manage_system wms;
	//�����û�ѡ��
	int choice = 0;
	while (true)
	{
		//����չʾ�˵�����
		wms.showmenu();
		authorinfo();
		cout << "����������ѡ��" << endl; 
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wms.exit_system();
			break;
		case 1://����ְ��
			wms.add_emp();
			break;
		case 2://��ʾְ��
			wms.show_emp();
			break;
		case 3://ɾ��ְ��
			wms.del_emp();
			break;
		case 4://�޸�ְ��
			wms.mod_emp();
			break;
		case 5://����ְ��
			wms.find_emp();
			break;
		case 6://����ְ��
			wms.sort_emp();
			break;
		case 7://���ְ��
			wms.clean_emp();
			break;
		default:
			system("cls");//����


		}
	}
	


	system("pause");
	return 0;
}