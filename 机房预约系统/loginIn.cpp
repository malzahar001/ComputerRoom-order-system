#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include "globalFile.h"

//������ݵ��ܲ˵��ӿ�


void managerOperMenu(Identity* manager);
void studentOperMenu(Identity* student);
void teacherOperMenu(Identity* teacher);
/******************************************
*��¼ģ�飺�����û���ѡ�񣬽��벻ͬ���ļ������������֤
* 
* ע�⣺���txt��������ݺ������ģ���ʵ�ֵ�¼����ǰ��Ҫ
*��txt���Ϊansi�����ʽ�������ı����������vs�л�������
*
*******************************************/

void loginIn(string fileName,int type) {
//fileName�ļ�����
//type:1��2��3 �ֱ����ѧ���ͽ�ʦ�͹���Ա

	Identity* person = NULL;
	
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	string id;
	string name;
	string password;

	//ѧ���ͽ�ʦ��Ҫ��������ѧ�Ż�ְ����
	if (type == 1) {
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ������" << endl;
		cin >> id;
	}
	
	cout << "�������û�����";
	cin >> name;
	cout << "���������룺" ;
	cin >> password;

	if (type == 1) {//��֤ѧ�����
		string fid, fname, fpassword;
		//ÿ�ж�ȡѧ�š��û���������
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//���û�������Ϣ�Ա�
			if (fid == id && fname == name && fpassword == password) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//��¼�ɹ��򴴽���Ӧ��ݵĶ���ʵ�ָ����ֻ֧�ֵĹ��ܺ���
				person = new Student(id, name, password);
				studentOperMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {//��֤��ʦ���
		string fid, fname, fpassword;
		//ÿ�ж�ȡѧ�š��û���������
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//���û�������Ϣ�Ա�
			if (fid == id && fname == name && fpassword == password) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//��¼�ɹ��򴴽���Ӧ��ݵĶ���ʵ�ָ����ֻ֧�ֵĹ��ܺ���
	            //��̬����ָ�븳ֵʱ�����������вι��캯��
				person = new Teacher(id,name, password);
				teacherOperMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {//��֤����Ա���
		string fname, fpassword;
		//ÿ�ж�ȡ�û���������
		while (ifs >> fname && ifs >> fpassword) {
			//���û�������Ϣ�Ա�
			if (fname == name && fpassword == password) {
				cout << "��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				//��¼�ɹ��򴴽���Ӧ��ݵĶ���ʵ�ָ����ֻ֧�ֵĹ��ܺ���
				//��̬����ָ�븳ֵʱ�����������вι��캯��
				person = new Manager(name, password);
				managerOperMenu(person);
				return;
			}
		}
	}

	cout << "�����֤ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
}