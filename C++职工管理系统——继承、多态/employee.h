#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

//创建员工类
class Employee :public Worker
{
public:
	//构造函数
	Employee(int ID,string name,int did);
	//显示个人信息
	virtual void show_Info();
	//获取岗位名称
	virtual string getDeptName();
};