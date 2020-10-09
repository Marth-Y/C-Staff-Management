#include"manager.h"
#include<iostream>
using namespace std;

Manager::Manager(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
void Manager::show_Info()  
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成老板的任务" << endl;
}
string Manager::getDeptName()
{
	return "经理";
}