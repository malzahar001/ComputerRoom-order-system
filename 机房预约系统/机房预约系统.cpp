#include<iostream>
#include "Identity.h"
#include "globalFile.h"
using namespace std;

void loginIn(string fileName, int type);


int main() {
	
	int select = 0;
	while (true) {
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << "\t\t--------------------------------" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          1.学生代表          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          2.老    师          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          3.管 理 员          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t|          0.退    出          |" << endl
			<< "\t\t|                              |" << endl
			<< "\t\t--------------------------------" << endl;
		cout << "请输入您的身份：" << endl;
		cin >> select;
		switch (select) {
		case 1:
			//学生身份
			loginIn(STUDENT_FILE, 1);
			break;
		case 2:
			//老师
			loginIn(TEACHER_FILE, 2);
			break;
		case 3:
			//管理员
			loginIn(ADMIN_FILE, 3);
			break;
		case 0:
			//退出
		{
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		}
		default:
			cout << "输入错误，请重输！" << endl;
			break;
		}
		system("pause");
		system("cls");
	};
	system("pause");
	return 0;
}