#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
/*******************
*学生总菜单接口
*
*******************/
void teacherOperMenu(Identity* teacher) {
	while (true)
	{
		//使用多态函数，需要用父类调用
		//管理员菜单界面
		teacher->operMenu();
		//将父类指针转为子类指针，因为以下是子类特有的函数
		Teacher* man = (Teacher*)teacher;
		int select = 0;

		cin >> select;
		switch (select) {
		case 1: {//查看所有预约
			cout << "查看所有预约" << endl;
			man->showAllOrder();
		}
			  break;
		case 2: {//审核预约
			cout << "审核预约" << endl;
			man->checkOrder();
		}
			  break;
		case 0: {//注销登录
			delete teacher;//注销时需要去除在堆中的父类多态内存
			cout << "注销成功！" << endl;
			return;
		}
			  break;
		default:
			cout << "输入错误，请重输！" << endl;
			break;
		}
	}
}