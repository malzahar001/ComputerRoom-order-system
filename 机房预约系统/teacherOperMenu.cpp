#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
/*******************
*ѧ���ܲ˵��ӿ�
*
*******************/
void teacherOperMenu(Identity* teacher) {
	while (true)
	{
		//ʹ�ö�̬��������Ҫ�ø������
		//����Ա�˵�����
		teacher->operMenu();
		//������ָ��תΪ����ָ�룬��Ϊ�������������еĺ���
		Teacher* man = (Teacher*)teacher;
		int select = 0;

		cin >> select;
		switch (select) {
		case 1: {//�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			man->showAllOrder();
		}
			  break;
		case 2: {//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->checkOrder();
		}
			  break;
		case 0: {//ע����¼
			delete teacher;//ע��ʱ��Ҫȥ���ڶ��еĸ����̬�ڴ�
			cout << "ע���ɹ���" << endl;
			return;
		}
			  break;
		default:
			cout << "������������䣡" << endl;
			break;
		}
	}
}