#pragma once
#include "Identity.h"
using namespace std;
class Teacher:public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(string a, string b, string c);

	//���ܺ���
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void checkOrder();

	//���ԣ�ְ�����
	string m_EmpId;
};

