#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#include<fstream>
#define FILENAME "empFile.txt"

class WorkManager
{
public:
	//���캯��
	WorkManager();
	//��������
	~WorkManager();


	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��  ��־
	bool m_FileEmpty;
	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾְ����Ϣ
	void show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ���ڣ������򷵻�ְ��λ�ã����򷵻�-1
	int IsExit(int id);
	//�޸�ְ����Ϣ
	void Mod_Emp();
	//����Ա��
	void Find_Emp();
	//����
	void Sort_Emp();
	//����ļ�
	void Clean_File();
	
	//��¼Ա������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;
};