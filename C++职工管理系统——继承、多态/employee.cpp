#include"employee.h"
//构造函数
Employee::Employee(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
//显示个人信息
void Employee::show_Info()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:完成经理的任务" << endl;
}
//获取岗位名称
string Employee::getDeptName()
{
	return "员工";
}