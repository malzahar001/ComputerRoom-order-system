#include<iostream>
#include "Identity.h"
#include "globalFile.h"
using namespace std;

void loginIn(string fileName, int type);


int main() {
	
	int select = 0;
	while (true) {
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << "\t\t--------------------------------" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          1.ѧ������          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          2.��    ʦ          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          3.�� �� Ա          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          0.��    ��          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t--------------------------------" << endl;
		cout << "������������ݣ�" << endl;
		cin >> select;
		switch (select) {
		case 1:
			//ѧ�����
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//��ʦ
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			//����Ա
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			//�˳�
		{
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		}
		default:
			cout << "������������䣡" << endl;
			break;
		}
		system("pause");
		system("cls");
	};
	system("pause");
	return 0;
}