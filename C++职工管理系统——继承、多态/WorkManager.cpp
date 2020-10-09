#include"WorkManager.h"

WorkManager::WorkManager()
{
	//1.文件不存在
	ifstream ifs;
	ifs. open(FILENAME, ios::in);//读文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在但为空
	char ch;
	ifs >> ch;//读出一个字符，若为空，则为结尾字符eof
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，且记录有数据
	int num = this->get_EmpNum();
	cout << "职工人数为:" << num<<endl;
	this->m_EmpNum = num;

	//开辟对应空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//对空间写入保存的数据
	this->init_Emp();
	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_ID << "\t"
			<< "姓名:" << this->m_EmpArray[i]->m_Name << "\t"
			<< "岗位:" << this->m_EmpArray[i]->getDeptName() << endl;
	}*/

	////初始化属性
	//if (this->m_EmpArray!=NULL)
	//{
	//	delete[] this->m_EmpArray;
	//	this->m_EmpArray = NULL;
	//}
	//this->m_EmpNum = 0;
}
WorkManager::~WorkManager()
{

}
void WorkManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "*******欢迎使用职工管理系统！*******" << endl;
	cout << "***********0.退出管理程序***********" << endl;
	cout << "***********1.增加职工信息***********" << endl;
	cout << "***********2.显示职工信息***********" << endl;
	cout << "***********3.删除离职职工***********" << endl;
	cout << "***********4.修改职工信息***********" << endl;
	cout << "***********5.查找职工信息***********" << endl;
	cout << "***********6.按照编号排序***********" << endl;
	cout << "***********7.清空所有文档***********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}
void WorkManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkManager::Add_Emp()
{
	cout << "请输入添加职工人数：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum>0)
	{
		//添加
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker **newSpace=new Worker* [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i=0;i<this->m_EmpNum;i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请输入第 " << i + 1 << "个新职工的岗位：" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
			{
				worker = new Employee(id, name, dSelect);
				break;
			}
			case 2:
			{
				worker = new Manager(id, name, dSelect);
				break;
			}
			case 3:
			{
				worker = new Boss(id, name, dSelect);
				break;
			}
			default:
				cout << "输入有误"<<endl;
				break;
			}
			//将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//成功添加后保存到文件中
		this->save();


		//更新职工不为空标志
		this->m_FileEmpty = false;

		//提示添加成功
		cout << "成功添加" <<addNum<<"名新职工"<< endl;
	}
	else
	{
		cout << "输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件——写文件
	
	//将每个人的数据写入到文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->getDeptName() << endl;
	}

	//关闭文件
	ofs.close();
}

//统计文件中人数
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	string did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数
		num++;
	}
	return num;
}

//初始化员工
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	string did;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == "员工")
		{
			worker = new Employee(id, name, 1);
		}
		else if (did == "经理")
		{
			worker = new Manager(id, name, 2);
		}
		else
		{
			worker = new Boss(id, name, 3);
		}
		this->m_EmpArray[index]=worker;
		index++;
	}
	ifs.close();
}

//显示职工信息
void WorkManager::show_Emp()
{
	//判断文件是否为空
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->show_Info();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void WorkManager::Del_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按照职工编号进行删除
		cout << "请输入需要删除职工编号" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExit(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;
			//同步更新到文件
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在，存在则返回职工位置，否则返回-1
int WorkManager::IsExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_ID)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改职工信息
void WorkManager::Mod_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入需修改员工职工编号：" << endl;
		int ID=0;
		cin >> ID;
		int index = this->IsExit(ID);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			
			int id;
			string name;
			int did;

			cout << "查到："<<ID<<"号职工，"<<"请输入职工新编号：" << endl;
			cin >> id;

			cout << "请输入员工姓名:" << endl;
			cin >> name;

			cout << "请输入员工职位:" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> did;
			Worker* worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, did);
				break;
			case 2:
				worker = new Manager(id, name, did);
				break;
			case 3:
				worker = new Boss(id, name, did);
				break;
			default:
				break;
			}
			//更新到数组中
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，未找到该员工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找员工
void WorkManager::Find_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择查找方式:" << endl;
		int select=0;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按职工姓名查找" << endl;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号:" << endl;
			cin >> id;
			int index = this->IsExit(id);
			if (index != -1)
			{
				cout << "查找成功！该职工信息如下:" << endl;
				this->m_EmpArray[index]->show_Info();
				cout << "其位置为:" << index<<endl;
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名:" << endl;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功！该职工信息如下:" << endl;
					this->m_EmpArray[i]->show_Info();
					cout << "该职工位置:" << i<<endl;
					flag = true;
					//不break，避免同名的人查不完。
				}
			}
			if (!flag)
			{
				cout << "查无此人！" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序
void WorkManager::Sort_Emp()
{
	if (this->m_FileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按职工号升序排序" << endl;
		cout << "2.按职工号降序排序" << endl;

		int select = 0;
		cin >> select;

		//选择排序
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功！" << endl;

		//保存到文件中
		this->save();
		//展示所有职工
		this->show_Emp();
	}
	//由于show_Emp（）中有清屏和暂停，所以不用再写。
	//system("pause");
	//system("cls");
}

//清空文件
void WorkManager::Clean_File()
{
	cout << "是否确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后再重新创建
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileEmpty = true;
		}
		cout << "清空成功!" << endl;
	}
	system("pause");
	system("cls");
}