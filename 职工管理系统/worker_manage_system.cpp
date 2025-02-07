#include"worker_manage_system.h"
Worker_manage_system::Worker_manage_system()
{
	//1.�ļ�������
	ifstream file;
	file.open(FILENAME, ios::in);
	if (!file.is_open())
	{
		//�ļ�������
		//cout << "�ļ�������" << endl;
		//��ʼ������
		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->is_file_empty = true;
		return;

	}
	//�ļ����ڵ�Ϊ��
	char ch;
	file >> ch;
	if (file.eof())
	{
		//cout << "�ļ����ڵ�Ϊ��" << endl;
		//��ʼ������
		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->is_file_empty = true;
		return;

	}
	//�ļ�������������
	int num = this->get_emp_num(); 
	//cout << "ְ������Ϊ:" << num << endl;
	this->m_emp_num = num;
	//���ٿռ�
	this->m_emp_array = new Worker * [this->m_emp_num];
	//���ļ��е����ݴ浽������
	this->ini_emp();
	//for (int i = 0; i < this->m_emp_num; i++)
	//{
	//	cout << "ְ��id:" << this->m_emp_array[i]->m_id << " "
	//		<< "ְ������:" << this->m_emp_array[i]->m_name << " "
	//		<< "ְ������id:" << this->m_emp_array[i]->m_deptid << " "
	//		<< "ְ���Ա�:" << this->m_emp_array[i]->m_sex << " "
	//		<< "ְ������:" << this->m_emp_array[i]->m_age << endl;

	//		
	//}
	

}
Worker_manage_system::~Worker_manage_system()
{

}
//չʾ�˵�
void Worker_manage_system::showmenu()
{
	cout<<"**************************************"<< endl;
	cout<<"*********��ӭʹ��Ա������ϵͳ*********"<<endl;
	cout<<"************0.�˳�����ϵͳ************"<<endl;
	cout<<"************1.����ְ����Ϣ************"<<endl;
	cout<<"************2.��ʾְ����Ϣ************"<<endl;
	cout<<"************3.ɾ����ְְ��************"<<endl;
	cout<<"************4.�޸�ְ����Ϣ************"<<endl;
	cout<<"************5.����ְ����Ϣ************"<<endl;
	cout<<"************6.���ձ������************"<<endl;
	cout<<"************7.��������ĵ�************"<<endl;
	cout<<"**************************************"<<endl;		
}
void Worker_manage_system:: exit_system()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
void Worker_manage_system::add_emp()
{
	cout << "������Ҫ��ӵ�ְ��������" << endl;
	int add_num;
	cin >> add_num;//�����û�����ӵ�ְ������
	if (add_num > 0)
	{
		//�����¿ռ�Ĵ�С
		int new_size = this->m_emp_num + add_num;
		//�����¿ռ�
		Worker** new_space = new Worker * [new_size];
		//ԭ��ְ��Ǩ�Ƶ��¿ռ�ȥ
		if (this->m_emp_array != NULL)
		{
			for (int i = 0; i < this->m_emp_num; i++)
			{
				new_space[i] = this->m_emp_array[i];
			}
		}
		//���������Ա��
		for (int i = 0; i < add_num; i++)
		{
			int id;
			int age;
			string name;
			string sex;
			int dsex;
			int dselect;
			cout << "�������" << i + 1 << "����ְ����id��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ����������" << endl;
			cin >> name;
			
			cout << "��ѡ���" << i + 1 << "����ְ�����Ա�" << endl;
			cout << "1.��" << endl;
			cout << "2.Ů" << endl;
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
				cout << "����ѡ��Ĭ��ѡ��Ϊ����";
				sex = "man";
				break;
			}
			cout << "�������" << i + 1 << "����ְ�������䣺" << endl;
			cin >> age;
			cout << "��ѡ���" << i + 1 << "����ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
		
			
		
			//��������ְ�����浽������
			new_space[this->m_emp_num + i] = worker;
			
			
		}
		//�ͷ�ԭ��ְ������ռ�
		delete[] this->m_emp_array;
		//����ְ������ָ��
		this->m_emp_array = new_space;
		//����ְ������
		this->m_emp_num += add_num;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << add_num << "��Ա��" << endl;
		//�����ļ�����
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	//����
	system("pause");
	system("cls");
	
}
void Worker_manage_system::save()
{
	ofstream file;
	file.open(FILENAME, ios::out);//д��ķ�ʽ���ļ�-->��ְ����Ϣд���ļ�
	for (int i = 0; i < this->m_emp_num; i++)
	{
		file << this->m_emp_array[i]->m_id << " "
			<< this->m_emp_array[i]->m_name << " "
			<< this->m_emp_array[i]->m_deptid << " "
			<< this->m_emp_array[i]->m_sex << " "
			<< this->m_emp_array[i]->m_age << endl;
		//�ر��ļ�
		

	}
	file.close();
}
//Worker_manage_system::~Worker_manage_system()//�������������ٶ����������ֶ��ͷ�
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
	//��ʼԪ�ؽ����ļ��������
	int id;
	string name;
	string sex;
	int age;
	int dept_id;
	
	
	//�����������
	int num = 0;
	while (file >> id &&file&&file>> name&&file >> dept_id&&file >> sex&&file >> age)
	{
		num++;
	}
	file.close();
	return num;
}
//��ʼ��ְ����ʵ��
void Worker_manage_system::ini_emp()
{
	fstream file;
	file.open(FILENAME, ios::in);
	int id;
	string name;
	string sex;
	int age;
	int dept_id;
	int index = 0;//������ְ�����������
	while (file >> id && file && file >> name && file >> dept_id && file >> sex && file >> age)
	{
		Worker* worker = NULL;
		if (dept_id == 1)//��ͨԱ��
		{
			worker = new Employer(id, name, dept_id,sex, age );
		}
		else if (dept_id == 2)//����
		{
			worker = new Manager(id, name, dept_id, sex, age);
		}
		else//�ϰ�
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
		cout << "�ļ������ڻ�Ϊ��" << endl;
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
//����id�ж�ְ���Ƿ����
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
//ɾ��ְ��
void Worker_manage_system::del_emp()
{
	//�ļ������ڣ�ɾ��ʧ��
	if (this->is_file_empty)
	{
		cout << "ɾ��ʧ�ܣ��ļ�������" << endl;
	}
	int id=0;
	cout << "������Ҫɾ����ְ����id�ţ�"<<endl;
	cin >> id;
	int index = this->is_emp_exist(id);
	if (index != -1)
	{
		for (int i = index; i < this->m_emp_num - 1; i++)
		{
			this->m_emp_array[i] = this->m_emp_array[i + 1];//��һ�����ݸ���ǰһ�����ݡ�ʵ��ɾ��Ч��
		}
		//����ְ����Ա����
		this->m_emp_num--;
		//����ͬ�����ļ���
		this->save();
		cout << "ɾ���ɹ���" << endl;
	}
	//ְ��������
	else
	{
		cout << "ɾ��ʧ�ܣ���ְ�������ڣ�" << endl;
	}
	system("pause");
	system("cls");
}
//�޸�ְ����Ϣ
void Worker_manage_system::mod_emp()
{
	//�ļ������ڣ��޸�ʧ��
	if (this->is_file_empty)
	{
		cout << "�ļ������ڣ��޸�ʧ�ܣ�" << endl;
	}
	int id = 0;
	cout << "������Ҫ�޸ĵ�ְ����id:" << endl;
	cin >> id;
	int index = this->is_emp_exist(id);
	if (index != -1)//ְ������
	{
		delete this->m_emp_array[index];
		int new_id;
		int new_age;
		string new_name;
		string new_sex;
		int dsex;
		int dselect;
		cout << "���ҵ�"<<id<<"��ְ��"<<"�������ְ������id��" << endl;
		cin >> new_id;
		cout << "������ְ������������" << endl;
		cin >> new_name;

		cout << "��ѡ��ְ�������Ա�" << endl;
		cout << "1.��" << endl;
		cout << "2.Ů" << endl;
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
			cout << "����ѡ��Ĭ��ѡ��Ϊ����";
			new_sex = "man";
			break;
		}
		cout << "�������ְ���������䣺" << endl;
		cin >> new_age;
		cout << "��ѡ���ְ�����¸�λ��" << endl;
		cout << "1.��ְͨ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
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
		//�������ݵ�������
		this->m_emp_array[index] = worker;
		//ͬ�����ļ���
		this->save();
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "�޸�ʧ�ܣ���ְ��������!" << endl;
	}
	system("pause");
	system("cls");
}
void Worker_manage_system::find_emp()
{
	//�ļ������ڣ�����ʧ��
	if (this->is_file_empty)
	{
		cout << "�ļ������ڣ�����ʧ�ܣ�" << endl;
	}
	else
	{
		cout << "��ѡ����Ҫʹ�õĲ��ҷ�����" << endl;
		cout << "1.����id���ң�"
			 << "2.�����������ң�" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)//����id����
		{
			cout << "������id:" << endl;
			int id = 0;
			cin >> id;
			int index = this->is_emp_exist(id);
			if (index != -1)//���ҳɹ�
			{
				cout << "���ҳɹ�!" << endl;
				this->m_emp_array[index]->show_self_info();//��ʾ���ҵ���ְ����Ϣ
			}
			else
			{
				cout << "����ʧ�ܣ����޴���!" << endl;
			}
		}
		else if (choice == 2)//����������
		{
			string name;
			cout << "����������:" << endl;
			cin >> name;
			//��Ӳ����жϱ�־
			bool flag = false;
			for (int i = 0; i < this->m_emp_num; i++)
			{
				if (this->m_emp_array[i]->m_name == name)
				{
					cout << "���ҳɹ���" << endl;
					this->m_emp_array[i]->show_self_info();//��ʾ���ҵ���ְ����Ϣ
					flag = true;
				}
			}
			if (!flag)
			{
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
//��idΪְ������
void Worker_manage_system::sort_emp()
{
	if (this->is_file_empty)//�ļ������ڻ��¼Ϊ�գ��޷�����
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�����ʧ�ܣ�" << endl;
		system("pause");
		system("cls");
	}
	else 
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.�������� "
			<< "2.��������" << endl;
		int choice = 0;
		cin >> choice;
		for (int i = 0; i < this->m_emp_num; i++)
		{
			int min_max = i;//�ٶ�һ��������Сֵ
			for (int j = i + 1; j < this->m_emp_num; j++)
			{
				if (choice == 1)//����
				{
					if (this->m_emp_array[min_max]->m_id > this->m_emp_array[j]->m_id)
					{
						min_max = j;//�����±�
					}

				}
				else//ѡ��2���������󣬶��϶�����
				{
					if (this->m_emp_array[min_max]->m_id < this->m_emp_array[j]->m_id)
					{
						min_max = j;//�����±�
					}
				}
			}
			//�ж�min_max�Ƿ����޸ģ�������޸ģ��ͽ������ݸ���
			if (i != min_max)
			{
				Worker* temp = this->m_emp_array[i];
				this->m_emp_array[i] = this->m_emp_array[min_max];
				this->m_emp_array[min_max] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		//������ͬ�����ļ���
		this->save();
		this->show_emp();
	}
}
void Worker_manage_system::clean_emp()
{
	cout << "ȷ��Ҫ����𣿣���" << endl;
	cout << "1.ȷ����� "
		<< "�������ȡ����� " << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		//����ļ�
		ofstream file(FILENAME, ios::trunc);//ɾ���ļ�
		file.close();
		if (this->m_emp_array != NULL)
		{//ɾ����������
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
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
