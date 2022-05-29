#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
#include "globalFile.h"

//三个身份的总菜单接口


void managerOperMenu(Identity* manager);
void studentOperMenu(Identity* student);
void teacherOperMenu(Identity* teacher);
/******************************************
*登录模块：根据用户的选择，进入不同的文件来进行身份验证
* 
* 注意：如果txt输入的内容含有中文，则实现登录功能前需要
*将txt另存为ansi编码格式，否则文本内容输出在vs中会是乱码
*
*******************************************/

void loginIn(string fileName,int type) {
//fileName文件名，
//type:1和2和3 分别代表学生和教师和管理员

	Identity* person = NULL;
	
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	string id;
	string name;
	string password;

	//学生和教师需要额外输入学号或职工号
	if (type == 1) {
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号码" << endl;
		cin >> id;
	}
	
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：" ;
	cin >> password;

	if (type == 1) {//验证学生身份
		string fid, fname, fpassword;
		//每行读取学号、用户名和密码
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//与用户输入信息对比
			if (fid == id && fname == name && fpassword == password) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");

				//登录成功则创建对应身份的对象，实现该身份只支持的功能函数
				person = new Student(id, name, password);
				studentOperMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {//验证教师身份
		string fid, fname, fpassword;
		//每行读取学号、用户名和密码
		while (ifs >> fid && ifs >> fname && ifs >> fpassword) {
			//与用户输入信息对比
			if (fid == id && fname == name && fpassword == password) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");

				//登录成功则创建对应身份的对象，实现该身份只支持的功能函数
	            //多态父类指针赋值时会调用子类的有参构造函数
				person = new Teacher(id,name, password);
				teacherOperMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {//验证管理员身份
		string fname, fpassword;
		//每行读取用户名和密码
		while (ifs >> fname && ifs >> fpassword) {
			//与用户输入信息对比
			if (fname == name && fpassword == password) {
				cout << "登录成功" << endl;
				system("pause");
				system("cls");

				//登录成功则创建对应身份的对象，实现该身份只支持的功能函数
				//多态父类指针赋值时会调用子类的有参构造函数
				person = new Manager(name, password);
				managerOperMenu(person);
				return;
			}
		}
	}

	cout << "身份验证失败！" << endl;

	system("pause");
	system("cls");
}