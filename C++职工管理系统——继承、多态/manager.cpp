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
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:����ϰ������" << endl;
}
string Manager::getDeptName()
{
	return "����";
}