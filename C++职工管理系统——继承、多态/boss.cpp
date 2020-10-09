#include"boss.h"
#include<iostream>
using namespace std;

Boss::Boss(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
void Boss::show_Info()
{
	cout << "职工编号：" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责:混吃等死" << endl;
}
string Boss::getDeptName()
{
	return "总裁";
}