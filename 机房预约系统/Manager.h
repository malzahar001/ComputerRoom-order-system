#pragma once
#include "Identity.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;
class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string a,string b);

	/**************
	* 功能函数
	**************/
	//操作界面
	virtual void operMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();


	/***********************
	* 在添加账号时根据学号去重
	************************/
	//学生和教师容器，在添加账号时可以防止重复添加
	vector<Teacher>vTea;
	vector<Student>vStu;
	//加载学生与教师文件中的账号信息到容器中
	void initVector();
	//检查这个学号或职工号是否和容器中的信息重复
	bool checkRepeat(string id, int type);
};

