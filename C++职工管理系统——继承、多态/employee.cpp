#include"employee.h"
//���캯��
Employee::Employee(int ID, string name, int did)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = did;
}
//��ʾ������Ϣ
void Employee::show_Info()
{
	cout << "ְ����ţ�" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:��ɾ��������" << endl;
}
//��ȡ��λ����
string Employee::getDeptName()
{
	return "Ա��";
}