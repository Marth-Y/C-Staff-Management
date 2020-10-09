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
	//构造函数
	WorkManager();
	//析构函数
	~WorkManager();


	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空  标志
	bool m_FileEmpty;
	//统计文件中人数
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示职工信息
	void show_Emp();
	//删除职工
	void Del_Emp();
	//判断职工是否存在，存在则返回职工位置，否则返回-1
	int IsExit(int id);
	//修改职工信息
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//排序
	void Sort_Emp();
	//清空文件
	void Clean_File();
	
	//记录员工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;
};