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
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:��Ե���" << endl;
}
string Boss::getDeptName()
{
	return "�ܲ�";
}