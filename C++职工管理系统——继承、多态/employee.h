#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

//����Ա����
class Employee :public Worker
{
public:
	//���캯��
	Employee(int ID,string name,int did);
	//��ʾ������Ϣ
	virtual void show_Info();
	//��ȡ��λ����
	virtual string getDeptName();
};