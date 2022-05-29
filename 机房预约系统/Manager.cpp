#include "Manager.h"
//默认构造
Manager::Manager() {
	initVector();
}
//有参构造
Manager::Manager(string a, string b) {
	m_Name = a;
	m_password = b;
	loadComputerRoom();
	initVector();
}

//功能函数
//操作界面
void Manager::operMenu() {
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//添加账号
void Manager::addPerson(){
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加教师" << endl;

	string fileName;
	string tip;
	ofstream ofs;
	string errorTip; //重复错误提示

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "该学生已经存在于文件中，请重新输入";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "该教师已经存在于文件中，请重新输入";
	}
	
	ofs.open(fileName, ios::out | ios::app);
	string id, name, password;
	while (true) {
		cout << tip;
		cin >> id;
		cout << "请输入用户名：" << endl;
		cin >> name;

		cout << "请输入密码：" << endl;
		cin >> password;
		//根据学号查重
		if (checkRepeat(id, select)) {//失败
			cout << errorTip << endl;
		}
		else {
			ofs << id << " " << name << " " << password << endl;
			cout << "添加成功" << endl;
			//添加后必须重新加载容器新的信息，否则下次添加时找不到重复
			initVector();
			break;
		}
	}
	system("pause");
	system("cls");
	ofs.close();
}
void printInfo1(Student s) {
	cout << "学号： " << s.m_id << " 姓名： " << s.m_Name << " 密码：" << s.m_password << endl;
}
void printInfo2(Teacher t) {
	cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_password << endl;
}
//查看账号
void Manager::showPerson() {
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;
	
	int select = 0;
	cin >> select;
	if (select == 1) {
		//查看学生
		for_each(vStu.begin(), vStu.end(), printInfo1);
	}
	else if(select==2) {
		//查看教师
		for_each(vTea.begin(), vTea.end(), printInfo2);
	}
	else {
		cout << "输入错误！" << endl;
	}
	system("pause");
	system("cls");
}
void printInfo3(ComputerRoom com) {
	cout << "机房编号：" << com.m_id << " 机房最大容量：" << com.m_Cap << endl;
}
//查看机房信息
void Manager::showComputer() {
	cout << "机房信息如下" << endl;
	for_each(vCom.begin(),vCom.end(), printInfo3);
	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	cout << "清空预约记录成功！" << endl;

	system("pause");
	system("cls");

	ofs.close();
}

//加载学生与教师文件中的账号信息到容器中
void Manager::initVector() {
	//1、加载学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在或为空" << endl;
		return;
	}
	//清空容器
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_id && ifs >> s.m_Name >> s.m_password) {
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs>>t.m_password) {
		vTea.push_back(t);
	}
	cout << "当前教师数量为：" << vTea.size() << endl;
	ifs.close();
}
//检查这个学号或职工号是否和容器中的信息重复
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
		cout << "输入错误身份类型" << endl;
		return true;
	}
}
