#include "Manager.h"
//Ĭ�Ϲ���
Manager::Manager() {
	initVector();
}
//�вι���
Manager::Manager(string a, string b) {
	m_Name = a;
	m_password = b;
	loadComputerRoom();
	initVector();
}

//���ܺ���
//��������
void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����˺�
void Manager::addPerson(){
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;
	string errorTip; //�ظ�������ʾ

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "��ѧ���Ѿ��������ļ��У�����������";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "�ý�ʦ�Ѿ��������ļ��У�����������";
	}
	
	ofs.open(fileName, ios::out | ios::app);
	string id, name, password;
	while (true) {
		cout << tip;
		cin >> id;
		cout << "�������û�����" << endl;
		cin >> name;

		cout << "���������룺" << endl;
		cin >> password;
		//����ѧ�Ų���
		if (checkRepeat(id, select)) {//ʧ��
			cout << errorTip << endl;
		}
		else {
			ofs << id << " " << name << " " << password << endl;
			cout << "��ӳɹ�" << endl;
			//��Ӻ�������¼��������µ���Ϣ�������´����ʱ�Ҳ����ظ�
			initVector();
			break;
		}
	}
	system("pause");
	system("cls");
	ofs.close();
}
void printInfo1(Student s) {
	cout << "ѧ�ţ� " << s.m_id << " ������ " << s.m_Name << " ���룺" << s.m_password << endl;
}
void printInfo2(Teacher t) {
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_Name << " ���룺" << t.m_password << endl;
}
//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;
	
	int select = 0;
	cin >> select;
	if (select == 1) {
		//�鿴ѧ��
		for_each(vStu.begin(), vStu.end(), printInfo1);
	}
	else if(select==2) {
		//�鿴��ʦ
		for_each(vTea.begin(), vTea.end(), printInfo2);
	}
	else {
		cout << "�������" << endl;
	}
	system("pause");
	system("cls");
}
void printInfo3(ComputerRoom com) {
	cout << "������ţ�" << com.m_id << " �������������" << com.m_Cap << endl;
}
//�鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ����" << endl;
	for_each(vCom.begin(),vCom.end(), printInfo3);
	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	cout << "���ԤԼ��¼�ɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();
}

//����ѧ�����ʦ�ļ��е��˺���Ϣ��������
void Manager::initVector() {
	//1������ѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
		return;
	}
	//�������
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name >> s.m_password) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs>>t.m_password) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}
//������ѧ�Ż�ְ�����Ƿ�������е���Ϣ�ظ�
bool Manager::checkRepeat(string id, int type) {
	string fileName;
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (it->m_id == id)
				return true;
		}
		return false;
	}
	else if(type==2) {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (it->m_EmpId == id)
				return true;
		}
		return false;
	}
	else {
		cout << "��������������" << endl;
		return true;
	}
}
