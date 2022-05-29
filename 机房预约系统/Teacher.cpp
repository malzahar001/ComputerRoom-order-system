#include "Teacher.h"

//默认构造
Teacher::Teacher() {

}
//有参构造
Teacher::Teacher(string a, string b, string c) {
	m_EmpId = a;
	m_Name = b;
	m_password = c;
}
//菜单界面
void Teacher::operMenu() {
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//查看所有预约
void Teacher::showAllOrder() {
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
//审核预约
void Teacher::checkOrder() {
    OrderFile order;
	if (order.m_Size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "所有待审核预约信息如下:" << endl;
	int index = 1;
	vector<int>vec;
	for (int i = 0; i < order.m_Size; i++) {
		if (order.m_orderData[i]["status"] == "1") {
			vec.push_back(i);
			cout << index++ << "、";
			cout << "预约日期:  周" << order.m_orderData[i]["date"] << " ";
			cout << "时段: " << (order.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "学号: " << order.m_orderData[i]["stuId"] << " ";
			cout << "姓名: " << order.m_orderData[i]["stuName"] << " ";
			cout << "机房: " << order.m_orderData[i]["roomId"] << " ";
			string status = "状态： 审核中";
			cout << status << endl;
		}
	}
	int select = 0;
	int ret = 0;
	while (true) {
		cout << "请输入您想要审核的订单" << endl;
		cin >> select;
		if (select >= 0 && select <= vec.size()) {
			if (select == 0)
				break;
			else {
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;

				if (ret == 1) {
					order.m_orderData[vec[select - 1]]["status"] = "2";
				}
				else {
					order.m_orderData[vec[select - 1]]["status"] = "-1";
				}
				order.updateOrder();
				cout << "审核完毕！" << endl;
				cout << "是否继续审核？" << endl;
				cout << "1、继续" << endl;
				cout << "2、不继续" << endl;
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
			cout << "输入选择有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}