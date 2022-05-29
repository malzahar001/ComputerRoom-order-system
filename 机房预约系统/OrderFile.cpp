#include "OrderFile.h"

//构造函数
//把订单文件中信息全部读取，放到容器中
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;      //日期
	string interval;  //时间段
	string stuId;     //学生编号
	string stuName;   //学生姓名
	string roomId;    //机房编号
	string status;    //预约状态

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
//更新预约记录(在容器添加或删除订单时，需要将订单文件删除，然后重新写入容器的数据)
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