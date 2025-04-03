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
	//设置用户选择
	int choice = 0;
	while (true)
	{
		//调用展示菜单函数
		wms.showmenu();
		authorinfo();
		cout << "请输入您的选择" << endl; 
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wms.exit_system();
			break;
		case 1://增加职工
			wms.add_emp();
			break;
		case 2://显示职工
			wms.show_emp();
			break;
		case 3://删除职工
			wms.del_emp();
			break;
		case 4://修改职工
			wms.mod_emp();
			break;
		case 5://查找职工
			wms.find_emp();
			break;
		case 6://排序职工
			wms.sort_emp();
			break;
		case 7://清空职工
			wms.clean_emp();
			break;
		default:
			system("cls");//清屏


		}
	}
	


	system("pause");
	return 0;
}