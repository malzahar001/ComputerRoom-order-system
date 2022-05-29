#pragma once
#include "Identity.h"
using namespace std;
class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(string a, string b, string c);

	//功能函数
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();

	//特性：学号
	string m_id;

};

