#include<iostream>
using namespace std;
#include"WorkManager.h"
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
int main()
{
	//ʵ����һ�������߶���
	WorkManager wm;
	int choice = 0;
	while (true)
	{
		//����չʾ�˵��ĳ�Ա����
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}