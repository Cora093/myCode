#include "employee.h"

//构造函数
Employee::Employee() {
	this->m_ID = 0;
	this->m_PhoneNumber = 0;
	this->m_Salary = 0;

	int tmpNum = 0;			//临时存放职工数量
	tmpNum = this->getEmpNum();
	if (tmpNum > 0) {		//如果职工数量>0
		//创建链表
		Employee::m_EmpArray = new Employee* [tmpNum];

		//读取数据
		ifstream ifs(FILENAME, ios::binary);	//打开文件

		for (int i = 0; i < tmpNum; i++) {				//遍历输入
			ifs.read((char*)Employee::m_EmpArray[i], sizeof(Employee));
		}
		
		//关闭文件
		ifs.close();

	}
}

Employee::Employee(int id, char name[20], char sex[20], long phoneNum, char dept[20], int salary) {
	this->m_ID = id;
	strcpy(this->m_Name, &name[20]);
	strcpy(this->m_Sex, &sex[20]);
	this->m_PhoneNumber = phoneNum;
	strcpy(this->m_Department, &dept[20]);
	this->m_Salary = salary;
}

//析构函数
Employee::~Employee() {
	if (Employee::m_EmpArray != NULL) {
		Employee::m_EmpArray = NULL;
		Employee::m_EmpNum = 0;
	}
}

//退出系统
void Employee::exitSys() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
}

//增加职工
void Employee::addEmp() {
	cout << "请输入添加数量：" << endl;
	int addNum = 0;				//添加数量
	cin >> addNum;

	if (addNum > 0) {			//当数量输入正确
		//实现添加功能
		//计算添加后的空间大小
		int newSize = Employee::m_EmpNum + addNum;

		//开辟新空间
		Employee** newSpace = new Employee* [newSize];

		//拷贝原有数据
		if (Employee::m_EmpArray != NULL) {
			for (int i = 0; i < newSize; i++) {
				newSpace[i] = Employee::m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int ID;
			char name[20];
			char sex[20];
			long phoneNum;
			char dept[20];
			int salary;

			char tmp[20];

			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> ID;
			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工性别:" << endl;
			cin >> tmp;	
			cout << "请输入第" << i + 1 << "个新职工电话号码:" << endl;
			cin >> phoneNum;			
			cout << "请输入第" << i + 1 << "个新职工部门:" << endl;
			cin >> tmp;
			cout << "请输入第" << i + 1 << "个新职工工资:" << endl;
			cin >> salary;

			newSpace[Employee::m_EmpNum + i] = new Employee(ID, name, sex, phoneNum, dept, salary);
		}

		//释放原有空间
		delete[] Employee::m_EmpArray;

		//更改指针指向新空间
		Employee::m_EmpArray = newSpace;

		//更新新的职工人数
		Employee::m_EmpNum = newSize;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;


		//保存到文件
		save();
	}
	else {
		cout << "数量输入错误" << endl;
	}

	//按任意键返回 清屏
	this->cls();
}

//显示所有职工信息
void Employee::showEmp(){
	if (Employee::m_EmpNum > 0) {
		for (int i = 0; i < Employee::m_EmpNum; i++) {
			Employee::m_EmpArray[i]->showInfo();
		}
	}
	else {
		cout << "无职工信息" << endl;
	}


	this->cls();
}










//显示菜单
void Employee::showMenu(){
	cout << "********************************************" << endl;
	cout << "******  欢迎使用公司员工信息管理系统 *******" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.删除职工信息  *************" << endl;
	cout << "*************  3.修改职工信息  *************" << endl;
	cout << "**********  4.按姓名查找职工信息  **********" << endl;
	cout << "**********  5.按科室查找职工信息  **********" << endl;
	cout << "********  6.按科室统计职工平均工资  ********" << endl;
	cout << "***********  7.查看所有职工信息  ***********" << endl;
	cout << "*************  0.退出管理系统  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//显示某员工信息
void Employee::showInfo() {
	cout << "工号： " << this->m_ID
		<< " \t姓名： " << this->m_Name
		<< " \t性别：" << this->m_Sex
		<< " \t手机号码：" << this->m_PhoneNumber
		<< " \t科室：" << this->m_Department
		<< " \t工资：" << this->m_Salary
		<< endl;

}

//保存文件
void Employee::save() {
	//二进制文件写入
	ofstream ofs;

	//写入成员属性
	ofs.open(FILENAME, ios::binary);
	for (int i = 0; i < Employee::m_EmpNum; i++) {
		ofs.write((const char*)Employee::m_EmpArray[i], sizeof(Employee));
	}
	ofs.close();

	//写入职工人数
	ofs.open(EMPNUM, ios::out);
	ofs << Employee::m_EmpNum;
	ofs.close();

}

//获取文件中的职工人数
int Employee::getEmpNum() {
	ifstream ifs(EMPNUM, ios::in);
	int tmp;
	ifs >> tmp;
	ifs.close();
	return tmp;
}

//按任意键返回 清屏
void Employee::cls() {
	system("pause");
	system("cls");
}