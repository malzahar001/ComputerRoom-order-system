#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
/*******************
*ѧ���ܲ˵��ӿ�
*
*******************/
void studentOperMenu(Identity* student) {
	while (true)
	{
		//ʹ�ö�̬��������Ҫ�ø������
		//����Ա�˵�����
		student->operMenu();
		//������ָ��תΪ����ָ�룬��Ϊ�������������еĺ���
		Student* man = (Student*)student;
		int select = 0;

		cin >> select;
		switch (select) {
		case 1: {//����ԤԼ
			cout << "����ԤԼ" << endl;
			man->applyOrder();
		}
			  break;
		case 2: {//�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			man->showMyOrder();
		}
			  break;
		case 3: {//�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			man->showAllOrder();
		}
			  break;
		case 4: {//ȡ��ԤԼ
			cout << "ȡ��ԤԼ" << endl;
			man->cancelOrder();
		}
			  break;
		case 0: {//ע����¼
			delete student;//ע��ʱ��Ҫȥ���ڶ��еĸ����̬�ڴ�
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