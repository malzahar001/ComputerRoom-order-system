#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
/*******************
*����Ա�ܲ˵��ӿ�
*
*******************/
void managerOperMenu(Identity* manager) {
	while (true)
	{
		//ʹ�ö�̬��������Ҫ�ø������
		//����Ա�˵�����
		manager->operMenu();
		//������ָ��תΪ����ָ�룬��Ϊ�������������еĺ���
		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		switch (select) {
		case 1: {//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
			  break;
		case 2: {//�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
			  break;
		case 3: {//�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
			  break;
		case 4: {//���ԤԼ
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
			  break;
		case 0: {//ע����¼
			delete manager;//ע��ʱ��Ҫȥ���ڶ��еĸ����̬�ڴ�
			cout << "ע���ɹ���" << endl;
			return;
		}
			  break;
		default:
			cout<<"������������䣡" << endl;
			break;
		}
	}
}
