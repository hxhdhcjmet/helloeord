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
struct person//设置联系人结构体 
{
	//姓名
	string name;
	//性别 1 男 2 女 
	int sex;
	//年龄
	int age;
	//电话
	string phone;
	//家庭住址
	string address; 
};
struct addresstext
{
	struct person parray[max];
	int size;
	
} ;
int main()
{
	//创建通讯录变量 
	struct addresstext N1;
	N1.size=0;//初始化通讯录数据 
	int select = 0;
	while(1)
	{
		showmenu();
		cin>>select;
	switch(select)
	{
		
		case 1://添加联系人
		addperson(&N1);//用地址传递可以改变形参的值 
			break;
		case 2://显示联系人
		showaddresstext(&N1);
			break;
		case 3://删除联系人
		deleteperson(&N1);
			break;
		case 4://查找联系人
		/*{
			if(N1.size==0)
		{
		cout<<"当前记录为空！"<<endl;
		system("pause");
		return 0;
		};
			string name;
			cout<<"请输入要查找的人的姓名："<<endl;
			cin>>name;
			if(isexist(&N1,name)==-1)
			{
				cout<<"查无此人！"<<endl;
			}
			else
			{
				cout<<"查有此人！"<<endl;
				findeperson(N1,name);
			}
			system("pause");
			system("cls");
		}
			break;*/
		case 5://修改联系人
		modifyperson(&N1);
			break;
		case 6://清空联系人
		clearaddresstext(&N1);
			break;
		case 0://退出通讯录
		cout<<"欢迎下次继续使用！"<<endl;
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
	cout<<"*****1、添加联系人*****" <<endl;
	cout<<"*****2、显示联系人*****" <<endl;
	cout<<"*****3、删除联系人*****" <<endl;
	cout<<"*****4、查找联系人*****" <<endl; 
	cout<<"*****5、修改联系人*****" <<endl; 
	cout<<"*****6、清空联系人*****" <<endl; 
	cout<<"*****0、退出通讯录*****" <<endl; 
	cout<<"auther:Hxhdhcjmet"<<"  "<<"verson:1.0"<<endl;
	cout<<"************************"<<endl;
};
void addperson(addresstext*N1) 
{
	if(N1->size==max)
	{
		cout<<"通讯录中联系人数目已满,无法添加！"<<endl;
		return;
	}
	else//添加具体联系人 
	{
		//添加姓名 
	cout<<"请输入姓名："<<endl;
	string name;
	cin>>name;
	N1->parray[N1->size].name=name;
	//添加性别 
	cout<<"请输入性别："<<endl;
	cout<<"1---男"<<endl;
	cout<<"2---女"<<endl;
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
			cout<<"请输入符合要求的数！"<<endl;
		}
	}
	//添加年龄
	int age = 0; 
	cout<<"请输入年龄："<<endl;
	while(1)
	{
	cin>>age;
	if(age>=0)
	{
		N1->parray[N1->size].age=age;
		break;
	}
	cout<<"请输入符合要求（非负数）的数！"<<endl;
	}
	
	//添加号码
	cout<<"请输入号码："<<endl;
	string phone;
	cin>>phone;
	N1->parray[N1->size].phone =phone;
	//添加住址
	cout<<"请输入住址："<<endl;
	string address;
	cin>>address;
	N1->parray[N1->size].address=address;
	cout<<"添加成功！"<<endl;
	N1->size++;
	system("pause"); //按任意键暂停
	system("cls") ;//清屏操作 
}
};
void showaddresstext(addresstext*N1)
{
	if(N1->size==0)
	{
		cout<<"当前记录为空！"<<endl;
	}
	else
	{
		for(int i=0;i<N1->size;i++)
		{
			cout<<"姓名："<<N1->parray[i].name<<"\t";
			cout<<"性别："<<(N1->parray[i].sex==1?"男":"女")<<"\t";
			cout<<"年龄："<<N1->parray[i].age<<"\t";
			cout<<"号码："<<N1->parray[i].phone<<"\t";
			cout<<"住址："<<N1->parray[i].address<<endl;
			
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
			return i;//遍历结构体数组查找是否有此人 
		}
	}
	return -1;
	system("pause");
	system("cls");
};
void deleteperson(addresstext*N1)//删除联系人 
{
	cout<<"请输入您要删除的人的名字："<<endl;
	string name;
	cin>>name;
	int ret =isexist(N1,name);
	//ret==-1,则查无此人
	//ret!=-1,则有此人，可以进行下一步删除操作
	if(ret!=-1)
	{
		//查找到此人，进行删除操作
		for(int i=ret;i<N1->size;i++) 
		{
			N1->parray[i]=N1->parray[i+1];//数据前移操作 
			N1->size--;//联系人个数减一		
		 } 
	}
	 else
	 {
	 	cout<<"查无此人！"<<endl;
	 }
	
};
void findperson(addresstext*N1 )//查找联系人
{
	cout<<"请输入你要查找的联系人姓名："<<endl;
	string name;
	cin>>name;
	int ret=isexist(N1,name);
	if(ret!=-1)
	{
		cout<<"姓名："<<N1->parray[ret].name<<"\t";
		cout<<"性别："<<(N1->parray[ret].sex==1?"男":"女")<<"\t";
		cout<<"年龄："<<N1->parray[ret].age<<"\t";
		cout<<"号码："<<N1->parray[ret].phone<<"\t";
		cout<<"住址："<<N1->parray[ret].address<<endl;
	}
	else
	{
		cout<<"查无此人！"<<endl;
	}
	system("pause");
	system("cls");
	
 } ;
 void modifyperson(addresstext*N1)
 {//大部分添加联系人部分抄过来的 
 	string name;
 	cout<<"请输入要修改的联系人的姓名："<<endl;
 	cin>>name;
 	int ret=isexist(N1,name);
 	if(ret!=-1)
 	{
 	cout<<"请输入姓名："<<endl;
	string name;
	cin>>name;
	N1->parray[ret].name=name;
	//修改性别 
	cout<<"请输入性别："<<endl;
	cout<<"1---男"<<endl;
	cout<<"2---女"<<endl;
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
			cout<<"请输入符合要求的数！"<<endl;
		}
	}
	//修改年龄
	int age = 0; 
	cout<<"请输入年龄："<<endl;
	while(1)
	{
	cin>>age;
	if(age>=0)
	{
		N1->parray[ret].age=age;
		break;
	}
	cout<<"请输入符合要求（非负数）的数！"<<endl;
	}
	
	//修改号码
	cout<<"请输入号码："<<endl;
	string phone;
	cin>>phone;
	N1->parray[ret].phone =phone;
	//修改住址
	cout<<"请输入住址："<<endl;
	string address;
	cin>>address;
	N1->parray[ret].address=address;
	cout<<"修改成功！"<<endl;
	}
	 else
	 {
	 	cout<<"查无此人！"<<endl;
		  
	 }
 	system("pause");
 	system("cls");
 };
 void clearaddresstext(addresstext*N1)
 {
 	cout<<"你是否确定要清空联系人？"<<endl;
 	cout<<"输入1确定清空，输入2返回。"<<endl;
 	int a=0;
 	cin>>a;
 	if(a==1)
 	{
 		N1->size=0;
 		cout<<"清空联系人成功！"<<endl;
 		system("pause");
		system("cls");
 		
	}
	else
	{
		system("pause");
		system("cls");
	}
  } 
