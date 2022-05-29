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
//������ݵĻ���
class Identity
{
public:
	//���麯�������ڶ�̬�� ������ݵĲ�������
	virtual void operMenu() = 0;

	//�û���������
	string m_Name, m_password;

	/***************
    * ��ʼ��ʱ���ػ�����Ϣ
    ***************/
	vector<ComputerRoom>vCom;
	void loadComputerRoom() {
		ifstream ifs;
		ifs.open(COMPUTER_FILE, ios::in);
		ComputerRoom com;
		while (ifs >> com.m_id && ifs >> com.m_Cap) {
			vCom.push_back(com);
		}
		cout << "��ǰ��������Ϊ��" << vCom.size() << endl;
		ifs.close();
	}
};

