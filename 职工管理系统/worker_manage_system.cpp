#include"worker_manage_system.h"
Worker_manage_system::Worker_manage_system()
{
	//1.文件不存在
	ifstream file;
	file.open(FILENAME, ios::in);
	if (!file.is_open())
	{
		//文件不存在
		//cout << "文件不存在" << endl;
		//初始化数据
		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->is_file_empty = true;
		return;

	}
	//文件存在但为空
	char ch;
	file >> ch;
	if (file.eof())
	{
		//cout << "文件存在但为空" << endl;
		//初始化数据
		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->is_file_empty = true;
		return;

	}
	//文件存在且有数据
	int num = this->get_emp_num(); 
	//cout << "职工人数为:" << num << endl;
	this->m_emp_num = num;
	//开辟空间
	this->m_emp_array = new Worker * [this->m_emp_num];
	//将文件中的数据存到数组中
	this->ini_emp();
	//for (int i = 0; i < this->m_emp_num; i++)
	//{
	//	cout << "职工id:" << this->m_emp_array[i]->m_id << " "
	//		<< "职工姓名:" << this->m_emp_array[i]->m_name << " "
	//		<< "职工部门id:" << this->m_emp_array[i]->m_deptid << " "
	//		<< "职工性别:" << this->m_emp_array[i]->m_sex << " "
	//		<< "职工年龄:" << this->m_emp_array[i]->m_age << endl;

	//		
	//}
	

}
Worker_manage_system::~Worker_manage_system()
{

}
//展示菜单
void Worker_manage_system::showmenu()
{
	cout<<"**************************************"<< endl;
	cout<<"*********欢迎使用员工管理系统*********"<<endl;
	cout<<"************0.退出管理系统************"<<endl;
	cout<<"************1.增加职工信息************"<<endl;
	cout<<"************2.显示职工信息************"<<endl;
	cout<<"************3.删除离职职工************"<<endl;
	cout<<"************4.修改职工信息************"<<endl;
	cout<<"************5.查找职工信息************"<<endl;
	cout<<"************6.按照编号排序************"<<endl;
	cout<<"************7.清空所有文档************"<<endl;
	cout<<"**************************************"<<endl;		
}
void Worker_manage_system:: exit_system()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
void Worker_manage_system::add_emp()
{
	cout << "请输入要添加的职工人数：" << endl;
	int add_num;
	cin >> add_num;//保存用户新添加的职工人数
	if (add_num > 0)
	{
		//计算新空间的大小
		int new_size = this->m_emp_num + add_num;
		//开辟新空间
		Worker** new_space = new Worker * [new_size];
		//原来职工迁移到新空间去
		if (this->m_emp_array != NULL)
		{
			for (int i = 0; i < this->m_emp_num; i++)
			{
				new_space[i] = this->m_emp_array[i];
			}
		}
		//批量添加新员工
		for (int i = 0; i < add_num; i++)
		{
			int id;
			int age;
			string name;
			string sex;
			int dsex;
			int dselect;
			cout << "请输入第" << i + 1 << "个新职工的id：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			
			cout << "请选择第" << i + 1 << "个新职工的性别：" << endl;
			cout << "1.男" << endl;
			cout << "2.女" << endl;
			cin >> dsex;
			switch (dsex)
			{
			case 1:
				sex = "man";
				break;
			case 2:
				sex = "woman";
				break;
			deault:
				cout << "错误选择，默认选择为男性";
				sex = "man";
				break;
			}
			cout << "请输入第" << i + 1 << "个新职工的年龄：" << endl;
			cin >> age;
			cout << "请选择第" << i + 1 << "个新职工的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dselect;
			Worker* worker = NULL;
			switch (dselect)
			{
			case 1:
				worker = new Employer(id, name, 1, sex, age);
				break;
			case 2:
				worker = new Manager(id, name, 2, sex, age);
				break;
			case 3:
				worker = new Boss(id, name, 3, sex, age);
				break;
			default:
				break;
			}
		
			
		
			//将创建的职工保存到数组中
			new_space[this->m_emp_num + i] = worker;
			
			
		}
		//释放原有职工数组空间
		delete[] this->m_emp_array;
		//更新职工数组指向
		this->m_emp_array = new_space;
		//更新职工人数
		this->m_emp_num += add_num;
		//提示添加成功
		cout << "成功添加" << add_num << "名员工" << endl;
		//保存文件函数
		this->save();
	}
	else
	{
		cout << "输入有误！" << endl;
	}
	//清屏
	system("pause");
	system("cls");
	
}
void Worker_manage_system::save()
{
	ofstream file;
	file.open(FILENAME, ios::out);//写入的方式打开文件-->将职工信息写入文件
	for (int i = 0; i < this->m_emp_num; i++)
	{
		file << this->m_emp_array[i]->m_id << " "
			<< this->m_emp_array[i]->m_name << " "
			<< this->m_emp_array[i]->m_deptid << " "
			<< this->m_emp_array[i]->m_sex << " "
			<< this->m_emp_array[i]->m_age << endl;
		//关闭文件
		

	}
	file.close();
}
//Worker_manage_system::~Worker_manage_system()//析构函数将开辟堆区的数据手动释放
//{
//	if (this->m_emp_array != NULL)
//	{
//		for (int i = 0; i < this->m_emp_num; i++)
//		{
//			this->m_emp_array[i] = NULL;
//			delete this->m_emp_array[i];
//		}
//		delete[] this->m_emp_array;
//		this->m_emp_array = NULL;
//		
//	}
//}
int Worker_manage_system::get_emp_num()
{
	fstream file;
	file.open(FILENAME, ios::in);
	//初始元素接受文件里的内容
	int id;
	string name;
	string sex;
	int age;
	int dept_id;
	
	
	//定义计数变量
	int num = 0;
	while (file >> id &&file&&file>> name&&file >> dept_id&&file >> sex&&file >> age)
	{
		num++;
	}
	file.close();
	return num;
}
//初始化职工的实现
void Worker_manage_system::ini_emp()
{
	fstream file;
	file.open(FILENAME, ios::in);
	int id;
	string name;
	string sex;
	int age;
	int dept_id;
	int index = 0;//计数，职工数组的索引
	while (file >> id && file && file >> name && file >> dept_id && file >> sex && file >> age)
	{
		Worker* worker = NULL;
		if (dept_id == 1)//普通员工
		{
			worker = new Employer(id, name, dept_id,sex, age );
		}
		else if (dept_id == 2)//经理
		{
			worker = new Manager(id, name, dept_id, sex, age);
		}
		else//老板
		{
			worker = new Boss(id, name, dept_id, sex, age);
		}
		this->m_emp_array[index] = worker;
		index++;
	}
	file.close();
}
void Worker_manage_system::show_emp()
{
	if (this->is_file_empty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_emp_num; i++)
		{
			this->m_emp_array[i]->show_self_info();

		}
	}
	system("pause");
	system("cls");
}
//根据id判断职工是否存在
int Worker_manage_system::is_emp_exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_emp_num; i++)
	{
		if (this->m_emp_array[i]->m_id== id)
		{
			index = i;
			break;
		}

	}
	return index;
}
//删除职工
void Worker_manage_system::del_emp()
{
	//文件不存在，删除失败
	if (this->is_file_empty)
	{
		cout << "删除失败，文件不存在" << endl;
	}
	int id=0;
	cout << "请输入要删除的职工的id号："<<endl;
	cin >> id;
	int index = this->is_emp_exist(id);
	if (index != -1)
	{
		for (int i = index; i < this->m_emp_num - 1; i++)
		{
			this->m_emp_array[i] = this->m_emp_array[i + 1];//后一个数据覆盖前一个数据。实现删除效果
		}
		//更新职工人员个数
		this->m_emp_num--;
		//数据同步到文件中
		this->save();
		cout << "删除成功！" << endl;
	}
	//职工不存在
	else
	{
		cout << "删除失败，该职工不存在！" << endl;
	}
	system("pause");
	system("cls");
}
//修改职工信息
void Worker_manage_system::mod_emp()
{
	//文件不存在，修改失败
	if (this->is_file_empty)
	{
		cout << "文件不存在，修改失败！" << endl;
	}
	int id = 0;
	cout << "请输入要修改的职工的id:" << endl;
	cin >> id;
	int index = this->is_emp_exist(id);
	if (index != -1)//职工存在
	{
		delete this->m_emp_array[index];
		int new_id;
		int new_age;
		string new_name;
		string new_sex;
		int dsex;
		int dselect;
		cout << "查找到"<<id<<"号职工"<<"请输入该职工的新id：" << endl;
		cin >> new_id;
		cout << "请输入职工的新姓名：" << endl;
		cin >> new_name;

		cout << "请选择职工的新性别：" << endl;
		cout << "1.男" << endl;
		cout << "2.女" << endl;
		cin >> dsex;
		switch (dsex)
		{
		case 1:
			new_sex = "man";
			break;
		case 2:
			new_sex = "woman";
			break;
		deault:
			cout << "错误选择，默认选择为男性";
			new_sex = "man";
			break;
		}
		cout << "请输入该职工的新年龄：" << endl;
		cin >> new_age;
		cout << "请选择该职工的新岗位：" << endl;
		cout << "1.普通职工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> dselect;
		Worker* worker = NULL;
		switch (dselect)
		{
		case 1:
			worker = new Employer(new_id, new_name, 1, new_sex, new_age);
			break;
		case 2:
			worker = new Manager(new_id, new_name, 2, new_sex, new_age);
			break;
		case 3:
			worker = new Boss(new_id, new_name, 3, new_sex, new_age);
			break;
		default:
			break;
		}
		//更新数据到数组中
		this->m_emp_array[index] = worker;
		//同步到文件中
		this->save();
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "修改失败，该职工不存在!" << endl;
	}
	system("pause");
	system("cls");
}
void Worker_manage_system::find_emp()
{
	//文件不存在，查找失败
	if (this->is_file_empty)
	{
		cout << "文件不存在，查找失败！" << endl;
	}
	else
	{
		cout << "请选择您要使用的查找方法：" << endl;
		cout << "1.按照id查找："
			 << "2.按照姓名查找：" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)//按照id查找
		{
			cout << "请输入id:" << endl;
			int id = 0;
			cin >> id;
			int index = this->is_emp_exist(id);
			if (index != -1)//查找成功
			{
				cout << "查找成功!" << endl;
				this->m_emp_array[index]->show_self_info();//显示查找到的职工信息
			}
			else
			{
				cout << "查找失败，查无此人!" << endl;
			}
		}
		else if (choice == 2)//按姓名查找
		{
			string name;
			cout << "请输入姓名:" << endl;
			cin >> name;
			//添加查找判断标志
			bool flag = false;
			for (int i = 0; i < this->m_emp_num; i++)
			{
				if (this->m_emp_array[i]->m_name == name)
				{
					cout << "查找成功！" << endl;
					this->m_emp_array[i]->show_self_info();//显示查找到的职工信息
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
//按id为职工排序
void Worker_manage_system::sort_emp()
{
	if (this->is_file_empty)//文件不存在或记录为空，无法排序
	{
		cout << "文件不存在或记录为空，排序失败！" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.升序排序 "
			<< "2.降序排序" << endl;
		int choice = 0;
		cin >> choice;
		for (int i = 0; i < this->m_emp_num; i++)
		{
			int min_max = i;//假定一个最大或最小值
			for (int j = i + 1; j < this->m_emp_num; j++)
			{
				if (choice == 1)//升序
				{
					if (this->m_emp_array[min_max]->m_id > this->m_emp_array[j]->m_id)
					{
						min_max = j;//更新下标
					}

				}
				else//选择2或输入有误，都认定降序
				{
					if (this->m_emp_array[min_max]->m_id < this->m_emp_array[j]->m_id)
					{
						min_max = j;//更新下标
					}
				}
			}
			//判断min_max是否有修改，如果有修改，就进行数据更新
			if (i != min_max)
			{
				Worker* temp = this->m_emp_array[i];
				this->m_emp_array[i] = this->m_emp_array[min_max];
				this->m_emp_array[min_max] = temp;
			}
		}
		cout << "排序成功！排序后结果为：" << endl;
		//排序结果同步到文件中
		this->save();
		this->show_emp();
	}
}
void Worker_manage_system::clean_emp()
{
	cout << "确定要清空吗？？？" << endl;
	cout << "1.确定清空 "
		<< "按任意键取消清空 " << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		//清空文件
		ofstream file(FILENAME, ios::trunc);//删除文件
		file.close();
		if (this->m_emp_array != NULL)
		{//删除堆区数据
			for (int i = 0; i < this->m_emp_num; i++)
			{
				delete this->m_emp_array[i];
				this->m_emp_array[i] = NULL;
			}
			delete[] this->m_emp_array;
			this->m_emp_array = NULL;
			this->m_emp_num = 0;
			this->is_file_empty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}
