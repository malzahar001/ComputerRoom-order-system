#include "OrderFile.h"

//���캯��
//�Ѷ����ļ�����Ϣȫ����ȡ���ŵ�������
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //����
	string interval;  //ʱ���
	string stuId;     //ѧ�����
	string stuName;   //ѧ������
	string roomId;    //�������
	string status;    //ԤԼ״̬

	m_Size = 0;

	while (ifs>>date&&ifs>>interval&&ifs>>stuId&&ifs>>stuName&&
		ifs>>roomId&&ifs>>status) {
		
		map<string, string>temp;
		string key, value;
		
		int pos = date.find(':');
		if (pos != -1) {
			key = "date";
			value = date.substr(pos + 1, date.size() - pos - 1);
			temp.insert(pair<string, string>(key, value));
		}

		pos = interval.find(':');
		if (pos != -1) {
			key = "interval";
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			temp.insert(pair<string, string>(key, value));
		}

		pos = stuId.find(':');
		if (pos != -1) {
			key = "stuId";
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			temp.insert(pair<string, string>(key, value));
		}
		
		pos = stuName.find(':');
		if (pos != -1) {
			key = "stuName";
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			temp.insert(pair<string, string>(key, value));
		}

		pos = roomId.find(':');
		if (pos != -1) {
			key = "roomId";
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			temp.insert(pair<string, string>(key, value));
		}

		pos = status.find(':');
		if (pos != -1) {
			key = "status";
			value = status.substr(pos + 1, status.size() - pos - 1);
			temp.insert(pair<string, string>(key, value));
		}

		m_orderData.insert(pair<int, map<string, string> >(m_Size, temp));
		m_Size++;
	}
	ifs.close();
}
//����ԤԼ��¼(��������ӻ�ɾ������ʱ����Ҫ�������ļ�ɾ����Ȼ������д������������)
void OrderFile::updateOrder() {
	if (m_Size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++) {
		ofs << "date:" << m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}