#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

//����Ա����
class Boss :public Worker
{
public:
	//���캯��
	Boss(int ID, string name, int did);
	//��ʾ������Ϣ
	virtual void show_Info();
	//��ȡ��λ����
	virtual string getDeptName();
};