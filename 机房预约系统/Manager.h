#pragma once
#include "Identity.h"
#include "Teacher.h"
#include "Student.h"
using namespace std;
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string a,string b);

	/**************
	* ���ܺ���
	**************/
	//��������
	virtual void operMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();


	/***********************
	* ������˺�ʱ����ѧ��ȥ��
	************************/
	//ѧ���ͽ�ʦ������������˺�ʱ���Է�ֹ�ظ����
	vector<Teacher>vTea;
	vector<Student>vStu;
	//����ѧ�����ʦ�ļ��е��˺���Ϣ��������
	void initVector();
	//������ѧ�Ż�ְ�����Ƿ�������е���Ϣ�ظ�
	bool checkRepeat(string id, int type);
};

