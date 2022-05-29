#include "Student.h"
//默认构造
Student::Student() {

}
//有参构造
Student::Student(string a, string b, string c) {
	m_id = a;
	m_Name = b;
	m_password = c;
	loadComputerRoom();
}

//菜单界面
void Student::operMenu(){
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//申请预约
void Student::applyOrder() {
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date = 0;//星期号
	int interval = 0;//预约时间（上午下午）
	int room = 0;//机房号
	
	while (true) {
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		cout << "输入有误，请重输" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;
		cout << "输入有误，请重输" << endl;
	}

	cout << "请选择机房：" << endl;
	cout << vCom[0].m_id <<"号机房容量：" << vCom[0].m_Cap << endl;
	cout << vCom[1].m_id << "号机房容量：" << vCom[1].m_Cap << endl;
	cout << vCom[2].m_id << "号机房容量：" << vCom[2].m_Cap << endl;
	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3)
			break;
		cout << "输入有误，请重输" << endl;
	}

	cout << "预约成功！审核中" << endl;
	//将订单写入文件
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
//查看自身预约
void Student::showMyOrder() {
	OrderFile order;
	if (order.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "您的预约信息如下:" << endl;

	for (int i = 0; i < order.m_Size; i++) {
		if (order.m_orderData[i]["stuId"] == this->m_id) {

			cout << "预约日期:  周" << order.m_orderData[i]["date"] << " ";
			cout << "时段: " << (order.m_orderData[i]["interval"]=="1"?"上午":"下午") << " ";
			cout << "机房: " << order.m_orderData[i]["roomId"] << " ";
			string status = "状态： ";
			if (order.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (order.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (order.m_orderData[i]["status"] == "-1") {
				status += "审核未通过，预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status<<endl;
		}
	}
	system("pause");
	system("cls");
}
//查看所有预约
void Student::showAllOrder() {
	OrderFile order;
	if (order.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "所有预约信息如下:" << endl;
	for (int i = 0; i < order.m_Size; i++) {
		cout << "预约日期:  周" << order.m_orderData[i]["date"] << " ";
		cout << "时段: " << (order.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号: " << order.m_orderData[i]["stuId"] << " ";
		cout << "姓名: " << order.m_orderData[i]["stuName"] << " ";
		cout << "机房: " << order.m_orderData[i]["roomId"] << " ";
		string status = "状态： ";
		if (order.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (order.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (order.m_orderData[i]["status"] == "-1") {
			status += "审核未通过，预约失败";
		}
		else {
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
//取消预约
void Student::cancelOrder() {
	OrderFile order;
	if (order.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，以下是可取消的记录" << endl;

	vector<int>v;
	int index = 1;
	//输出该学生所有可以取消的订单记录的信息来参考
	for (int i =0 ; i < order.m_Size; i++) {
		if (order.m_orderData[i]["stuId"] == m_id) {
			if (order.m_orderData[i]["status"] == "1"
				|| order.m_orderData[i]["status"] == "2") {
				v.push_back(i); //将该学生所有可以取消的订单记录加入容器
				cout << index++ << "、";//表示这是第几条订单

				//输出该可以取消的订单记录的信息
				cout << "预约日期： 周" << order.m_orderData[i]["date"];
				cout << " 时段：" << (order.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房：" << order.m_orderData[i]["roomId"];
				string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约  -1 预约失败
				if (order.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (order.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0)
				break;
			else {
				order.m_orderData[v[select - 1]]["status"] = "0";
				order.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}


