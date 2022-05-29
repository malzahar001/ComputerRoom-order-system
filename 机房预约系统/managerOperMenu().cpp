#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
/*******************
*管理员总菜单接口
*
*******************/
void managerOperMenu(Identity* manager) {
	while (true)
	{
		//使用多态函数，需要用父类调用
		//管理员菜单界面
		manager->operMenu();
		//将父类指针转为子类指针，因为以下是子类特有的函数
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		switch (select) {
		case 1: {//添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
			  break;
		case 2: {//查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
			  break;
		case 3: {//查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
			  break;
		case 4: {//清空预约
			cout << "清空预约" << endl;
			man->cleanFile();
		}
			  break;
		case 0: {//注销登录
			delete manager;//注销时需要去除在堆中的父类多态内存
			cout << "注销成功！" << endl;
			return;
		}
			  break;
		default:
			cout<<"输入错误，请重输！" << endl;
			break;
		}
	}
}
