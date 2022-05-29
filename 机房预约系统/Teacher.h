#pragma once
#include "Identity.h"
using namespace std;
class Teacher:public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(string a, string b, string c);

	//功能函数
	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void checkOrder();

	//特性：职工编号
	string m_EmpId;
};

