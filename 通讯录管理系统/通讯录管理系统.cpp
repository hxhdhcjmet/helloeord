#include<iostream>
#include<string>
#define max 2000
using namespace std;
void showmenu(); 
void addperson( struct addresstext*p);
void showaddresstext(struct addresstext*p);
int isexist(addresstext*p,string name);
void deleteperson(addresstext*p);
void findperson(addresstext*p);
void modifyperson(addresstext*N1);
void clearaddresstext(addresstext*N1);
struct person//������ϵ�˽ṹ�� 
{
	//����
	string name;
	//�Ա� 1 �� 2 Ů 
	int sex;
	//����
	int age;
	//�绰
	string phone;
	//��ͥסַ
	string address; 
};
struct addresstext
{
	struct person parray[max];
	int size;
	
} ;
int main()
{
	//����ͨѶ¼���� 
	struct addresstext N1;
	N1.size=0;//��ʼ��ͨѶ¼���� 
	int select = 0;
	while(1)
	{
		showmenu();
		cin>>select;
	switch(select)
	{
		
		case 1://�����ϵ��
		addperson(&N1);//�õ�ַ���ݿ��Ըı��βε�ֵ 
			break;
		case 2://��ʾ��ϵ��
		showaddresstext(&N1);
			break;
		case 3://ɾ����ϵ��
		deleteperson(&N1);
			break;
		case 4://������ϵ��
		/*{
			if(N1.size==0)
		{
		cout<<"��ǰ��¼Ϊ�գ�"<<endl;
		system("pause");
		return 0;
		};
			string name;
			cout<<"������Ҫ���ҵ��˵�������"<<endl;
			cin>>name;
			if(isexist(&N1,name)==-1)
			{
				cout<<"���޴��ˣ�"<<endl;
			}
			else
			{
				cout<<"���д��ˣ�"<<endl;
				findeperson(N1,name);
			}
			system("pause");
			system("cls");
		}
			break;*/
		case 5://�޸���ϵ��
		modifyperson(&N1);
			break;
		case 6://�����ϵ��
		clearaddresstext(&N1);
			break;
		case 0://�˳�ͨѶ¼
		cout<<"��ӭ�´μ���ʹ�ã�"<<endl;
		system("pause") ;
		return 0;
		findperson(&N1);
			break;
	}
	
	}
	
	
	return 0;
 } 
 void showmenu()
{
	cout<<"************************"<<endl;
	cout<<"*****1�������ϵ��*****" <<endl;
	cout<<"*****2����ʾ��ϵ��*****" <<endl;
	cout<<"*****3��ɾ����ϵ��*****" <<endl;
	cout<<"*****4��������ϵ��*****" <<endl; 
	cout<<"*****5���޸���ϵ��*****" <<endl; 
	cout<<"*****6�������ϵ��*****" <<endl; 
	cout<<"*****0���˳�ͨѶ¼*****" <<endl; 
	cout<<"auther:Hxhdhcjmet"<<"  "<<"verson:1.0"<<endl;
	cout<<"************************"<<endl;
};
void addperson(addresstext*N1) 
{
	if(N1->size==max)
	{
		cout<<"ͨѶ¼����ϵ����Ŀ����,�޷���ӣ�"<<endl;
		return;
	}
	else//��Ӿ�����ϵ�� 
	{
		//������� 
	cout<<"������������"<<endl;
	string name;
	cin>>name;
	N1->parray[N1->size].name=name;
	//����Ա� 
	cout<<"�������Ա�"<<endl;
	cout<<"1---��"<<endl;
	cout<<"2---Ů"<<endl;
	int sex=0;
	while(1)
	{
		cin>>sex;
		if(sex==1||sex==2)
		{
			N1-> parray[N1->size].sex=sex;
			break;
		}
		else
		{
			cout<<"���������Ҫ�������"<<endl;
		}
	}
	//�������
	int age = 0; 
	cout<<"���������䣺"<<endl;
	while(1)
	{
	cin>>age;
	if(age>=0)
	{
		N1->parray[N1->size].age=age;
		break;
	}
	cout<<"���������Ҫ�󣨷Ǹ�����������"<<endl;
	}
	
	//��Ӻ���
	cout<<"��������룺"<<endl;
	string phone;
	cin>>phone;
	N1->parray[N1->size].phone =phone;
	//���סַ
	cout<<"������סַ��"<<endl;
	string address;
	cin>>address;
	N1->parray[N1->size].address=address;
	cout<<"��ӳɹ���"<<endl;
	N1->size++;
	system("pause"); //���������ͣ
	system("cls") ;//�������� 
}
};
void showaddresstext(addresstext*N1)
{
	if(N1->size==0)
	{
		cout<<"��ǰ��¼Ϊ�գ�"<<endl;
	}
	else
	{
		for(int i=0;i<N1->size;i++)
		{
			cout<<"������"<<N1->parray[i].name<<"\t";
			cout<<"�Ա�"<<(N1->parray[i].sex==1?"��":"Ů")<<"\t";
			cout<<"���䣺"<<N1->parray[i].age<<"\t";
			cout<<"���룺"<<N1->parray[i].phone<<"\t";
			cout<<"סַ��"<<N1->parray[i].address<<endl;
			
		}
	}
	system("pause");
	system("cls");
};
int isexist(addresstext*N1,string name)
{
	
	for(int i=0;i<N1->size;i++)
	{
		if(N1->parray[i].name==name)
		{
			return i;//�����ṹ����������Ƿ��д��� 
		}
	}
	return -1;
	system("pause");
	system("cls");
};
void deleteperson(addresstext*N1)//ɾ����ϵ�� 
{
	cout<<"��������Ҫɾ�����˵����֣�"<<endl;
	string name;
	cin>>name;
	int ret =isexist(N1,name);
	//ret==-1,����޴���
	//ret!=-1,���д��ˣ����Խ�����һ��ɾ������
	if(ret!=-1)
	{
		//���ҵ����ˣ�����ɾ������
		for(int i=ret;i<N1->size;i++) 
		{
			N1->parray[i]=N1->parray[i+1];//����ǰ�Ʋ��� 
			N1->size--;//��ϵ�˸�����һ		
		 } 
	}
	 else
	 {
	 	cout<<"���޴��ˣ�"<<endl;
	 }
	
};
void findperson(addresstext*N1 )//������ϵ��
{
	cout<<"��������Ҫ���ҵ���ϵ��������"<<endl;
	string name;
	cin>>name;
	int ret=isexist(N1,name);
	if(ret!=-1)
	{
		cout<<"������"<<N1->parray[ret].name<<"\t";
		cout<<"�Ա�"<<(N1->parray[ret].sex==1?"��":"Ů")<<"\t";
		cout<<"���䣺"<<N1->parray[ret].age<<"\t";
		cout<<"���룺"<<N1->parray[ret].phone<<"\t";
		cout<<"סַ��"<<N1->parray[ret].address<<endl;
	}
	else
	{
		cout<<"���޴��ˣ�"<<endl;
	}
	system("pause");
	system("cls");
	
 } ;
 void modifyperson(addresstext*N1)
 {//�󲿷������ϵ�˲��ֳ������� 
 	string name;
 	cout<<"������Ҫ�޸ĵ���ϵ�˵�������"<<endl;
 	cin>>name;
 	int ret=isexist(N1,name);
 	if(ret!=-1)
 	{
 	cout<<"������������"<<endl;
	string name;
	cin>>name;
	N1->parray[ret].name=name;
	//�޸��Ա� 
	cout<<"�������Ա�"<<endl;
	cout<<"1---��"<<endl;
	cout<<"2---Ů"<<endl;
	int sex=0;
	while(1)
	{
		cin>>sex;
		if(sex==1||sex==2)
		{
			N1-> parray[ret].sex=sex;
			break;
		}
		else
		{
			cout<<"���������Ҫ�������"<<endl;
		}
	}
	//�޸�����
	int age = 0; 
	cout<<"���������䣺"<<endl;
	while(1)
	{
	cin>>age;
	if(age>=0)
	{
		N1->parray[ret].age=age;
		break;
	}
	cout<<"���������Ҫ�󣨷Ǹ�����������"<<endl;
	}
	
	//�޸ĺ���
	cout<<"��������룺"<<endl;
	string phone;
	cin>>phone;
	N1->parray[ret].phone =phone;
	//�޸�סַ
	cout<<"������סַ��"<<endl;
	string address;
	cin>>address;
	N1->parray[ret].address=address;
	cout<<"�޸ĳɹ���"<<endl;
	}
	 else
	 {
	 	cout<<"���޴��ˣ�"<<endl;
		  
	 }
 	system("pause");
 	system("cls");
 };
 void clearaddresstext(addresstext*N1)
 {
 	cout<<"���Ƿ�ȷ��Ҫ�����ϵ�ˣ�"<<endl;
 	cout<<"����1ȷ����գ�����2���ء�"<<endl;
 	int a=0;
 	cin>>a;
 	if(a==1)
 	{
 		N1->size=0;
 		cout<<"�����ϵ�˳ɹ���"<<endl;
 		system("pause");
		system("cls");
 		
	}
	else
	{
		system("pause");
		system("cls");
	}
  } 
