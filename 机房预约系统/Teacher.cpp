#include "Teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher() {

}
//�вι���
Teacher::Teacher(string a, string b, string c) {
	m_EmpId = a;
	m_Name = b;
	m_password = c;
}
//�˵�����
void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//�鿴����ԤԼ
void Teacher::showAllOrder() {
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
//���ԤԼ
void Teacher::checkOrder() {
    OrderFile order;
	if (order.m_Size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "���д����ԤԼ��Ϣ����:" << endl;
	int index = 1;
	vector<int>vec;
	for (int i = 0; i < order.m_Size; i++) {
		if (order.m_orderData[i]["status"] == "1") {
			vec.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ����:  ��" << order.m_orderData[i]["date"] << " ";
			cout << "ʱ��: " << (order.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��: " << order.m_orderData[i]["stuId"] << " ";
			cout << "����: " << order.m_orderData[i]["stuName"] << " ";
			cout << "����: " << order.m_orderData[i]["roomId"] << " ";
			string status = "״̬�� �����";
			cout << status << endl;
		}
	}
	int select = 0;
	int ret = 0;
	while (true) {
		cout << "����������Ҫ��˵Ķ���" << endl;
		cin >> select;
		if (select >= 0 && select <= vec.size()) {
			if (select == 0)
				break;
			else {
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;

				if (ret == 1) {
					order.m_orderData[vec[select - 1]]["status"] = "2";
				}
				else {
					order.m_orderData[vec[select - 1]]["status"] = "-1";
				}
				order.updateOrder();
				cout << "�����ϣ�" << endl;
				cout << "�Ƿ������ˣ�" << endl;
				cout << "1������" << endl;
				cout << "2��������" << endl;
				cin >> ret;
				if (ret==2) {
					break;
				}
				else {
					continue;
				}
			}
		}
		else {
			cout << "����ѡ����������������" << endl;
		}
	}
	system("pause");
	system("cls");
}