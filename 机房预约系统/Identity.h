#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "globalFile.h"
#include"ComputerRoom.h"
#include "OrderFile.h"
using namespace std;
//三个身份的基类
class Identity
{
public:
	//纯虚函数（用于多态） 各个身份的操作界面
	virtual void operMenu() = 0;

	//用户名和密码
	string m_Name, m_password;

	/***************
    * 初始化时加载机房信息
    ***************/
	vector<ComputerRoom>vCom;
	void loadComputerRoom() {
		ifstream ifs;
		ifs.open(COMPUTER_FILE, ios::in);
		ComputerRoom com;
		while (ifs >> com.m_id && ifs >> com.m_Cap) {
			vCom.push_back(com);
		}
		cout << "当前机房数量为：" << vCom.size() << endl;
		ifs.close();
	}
};

