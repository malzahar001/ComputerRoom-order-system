#include "Student.h"
//Ĭ�Ϲ���
Student::Student() {

}
//�вι���
Student::Student(string a, string b, string c) {
	m_id = a;
	m_Name = b;
	m_password = c;
	loadComputerRoom();
}

//�˵�����
void Student::operMenu(){
	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;//���ں�
	int interval = 0;//ԤԼʱ�䣨�������磩
	int room = 0;//������
	
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "��������������" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;
		cout << "��������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << vCom[0].m_id <<"�Ż���������" << vCom[0].m_Cap << endl;
	cout << vCom[1].m_id << "�Ż���������" << vCom[1].m_Cap << endl;
	cout << vCom[2].m_id << "�Ż���������" << vCom[2].m_Cap << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3)
			break;
		cout << "��������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;
	//������д���ļ�
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showMyOrder() {
	OrderFile order;
	if (order.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����ԤԼ��Ϣ����:" << endl;

	for (int i = 0; i < order.m_Size; i++) {
		if (order.m_orderData[i]["stuId"] == this->m_id) {

			cout << "ԤԼ����:  ��" << order.m_orderData[i]["date"] << " ";
			cout << "ʱ��: " << (order.m_orderData[i]["interval"]=="1"?"����":"����") << " ";
			cout << "����: " << order.m_orderData[i]["roomId"] << " ";
			string status = "״̬�� ";
			if (order.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (order.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (order.m_orderData[i]["status"] == "-1") {
				status += "���δͨ����ԤԼʧ��";
			}
			else {
				status += "ԤԼ��ȡ��";
			}
			cout << status<<endl;
		}
	}
	system("pause");
	system("cls");
}
//�鿴����ԤԼ
void Student::showAllOrder() {
	OrderFile order;
	if (order.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����ԤԼ��Ϣ����:" << endl;
	for (int i = 0; i < order.m_Size; i++) {
		cout << "ԤԼ����:  ��" << order.m_orderData[i]["date"] << " ";
		cout << "ʱ��: " << (order.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��: " << order.m_orderData[i]["stuId"] << " ";
		cout << "����: " << order.m_orderData[i]["stuName"] << " ";
		cout << "����: " << order.m_orderData[i]["roomId"] << " ";
		string status = "״̬�� ";
		if (order.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (order.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (order.m_orderData[i]["status"] == "-1") {
			status += "���δͨ����ԤԼʧ��";
		}
		else {
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//ȡ��ԤԼ
void Student::cancelOrder() {
	OrderFile order;
	if (order.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ���������ǿ�ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	//�����ѧ�����п���ȡ���Ķ�����¼����Ϣ���ο�
	for (int i =0 ; i < order.m_Size; i++) {
		if (order.m_orderData[i]["stuId"] == m_id) {
			if (order.m_orderData[i]["status"] == "1"
				|| order.m_orderData[i]["status"] == "2") {
				v.push_back(i); //����ѧ�����п���ȡ���Ķ�����¼��������
				cout << index++ << "��";//��ʾ���ǵڼ�������

				//����ÿ���ȡ���Ķ�����¼����Ϣ
				cout << "ԤԼ���ڣ� ��" << order.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (order.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << order.m_orderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (order.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (order.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0)
				break;
			else {
				order.m_orderData[v[select - 1]]["status"] = "0";
				order.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}


