#include "employee.h"



//构造函数
Employee::Employee() {

	this->m_ID = 0;
	this->m_Salary = 0;

	Employee::m_EmpNum = this->getEmpNum();
	if (Employee::m_EmpNum <= 0) {
		Employee::m_EmpNum = 0;
	}

	if (Employee::m_EmpNum > 0) {		//如果职工数量>0
		//创建链表
		Employee::m_EmpArray = new Employee* [Employee::m_EmpNum];

		//读取数据
		ifstream ifs(FILENAME, ios::in);
		//ifstream ifs(FILENAME, ios::in | ios::binary);	//打开文件

		int ID;
		char name[20];
		char sex[20];
		char phoneNum[20];
		char dept[20];
		int salary;
		Employee* tmp;

		for (int i = 0; i < Employee::m_EmpNum; i++) {

			ifs >> ID >> name >> sex >> phoneNum >> dept >> salary;
			tmp = new Employee(ID, name, sex, phoneNum, dept, salary);
			this->m_EmpArray[i] = tmp;
			 
			 
			//ifs.read((char*)Employee::m_EmpArray, sizeof(Employee));

		}
		
		//关闭文件
		ifs.close();

	}
}

Employee::Employee(int id, char name[20], char sex[20], char phoneNum[20], char dept[20], int salary) {
	this->m_ID = id;
	strcpy(this->m_Name, name);
	strcpy(this->m_Sex, sex);
	strcpy(this->m_PhoneNumber, phoneNum);
	strcpy(this->m_Department, dept);
	this->m_Salary = salary;
}

//析构函数
Employee::~Employee() {
	cout << "析构" << endl;
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
		int newSize = this->getEmpNum() + addNum;

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
			char phoneNum[20];
			char dept[20];
			int salary;


			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> ID;
			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个新职工性别:" << endl;
			cin >> sex;	
			cout << "请输入第" << i + 1 << "个新职工电话号码:" << endl;
			cin >> phoneNum;			
			cout << "请输入第" << i + 1 << "个新职工部门:" << endl;
			cin >> dept;
			cout << "请输入第" << i + 1 << "个新职工工资:" << endl;
			cin >> salary;

			newSpace[this->getEmpNum() + i] = new Employee(ID, name, sex, phoneNum, dept, salary);
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


//删除职工
void Employee::delEmp() {
	//判断数据是否为空
	if (this->getEmpNum() == 0) {
		cout << "数据为空" << endl;
	}
	else {
		//输入编号
		cout << "请输入要删除的职工编号:" << endl;
		int id = 0;
		cin >> id;

		//编号不存在
		if (this->isExist(id) == -1) {
			cout << "无此编号的员工" << endl;
		}
		//编号存在
		else {
			//显示信息
			this->m_EmpArray[this->isExist(id)]->showInfo();

			//用户确认
			cout << "是否要删除此员工:1/0" << endl;
			bool choice = true;
			cin >> choice;

			if (choice) {
				//删除该员工
				//将后面员工的信息前移覆盖
				for (int i = this->isExist(id); i < this->getEmpNum() - 1; i++) {
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}

				//数组成员数量-1
				Employee::m_EmpNum--;

				//数据同步更新到文件里
				this->save();

				cout << "删除成功!" << endl;
			}
			else {
				cout << "取消操作" << endl;
			}
		}
	}
	this->cls();
}

//修改职工
void Employee::modEmp() {

	//判断数据是否为空
	if (Employee::m_EmpNum == 0) {
		cout << "数据为空" << endl;
	}
	else {
		//输入编号
		cout << "请输入要修改的职工编号:" << endl;
		int id = 0;
		cin >> id;

		//编号不存在
		if (this->isExist(id) == -1) {
			cout << "无此编号的员工" << endl;
		}
		//编号存在
		else {
			//显示信息
			this->m_EmpArray[this->isExist(id)]->showInfo();

			//用户确认
			cout << "是否要修改此员工:1/0" << endl;
			bool choice = true;
			cin >> choice;

			if (choice) {
				//修改该员工

				int newID;
				char newName[20];
				char newSex[20];
				char newPhoneNum[20];
				char newDept[20];
				int newSalary;

				//输入信息
				cout << "请输入更改后的员工编号:" << endl;
				cin >> newID;
				cout << "请输入更改后的员工姓名:" << endl;
				cin >> newName;
				cout << "请输入更改后的员工性别:" << endl;
				cin >> newName;
				cout << "请输入更改后的员工电话号码:" << endl;
				cin >> newPhoneNum;
				cout << "请输入更改后的员工部门:" << endl;
				cin >> newDept;
				cout << "请输入更改后的员工工资:" << endl;
				cin >> newSalary;

				
				Employee* tmp = NULL;
				tmp = new Employee(newID, newName, newSex, newPhoneNum, newDept, newSalary);

				//写入数组
				this->m_EmpArray[this->isExist(id)] = tmp;

				//delete tmp;

				//数据同步更新到文件里
				this->save();

				cout << "更改成功!" << endl;
			}
			else {
				cout << "取消操作" << endl;
			}
		}
	}

	this->cls();
}


//通过姓名查找
void Employee::resByName() {
	//判断数据是否为空
	if (Employee::m_EmpNum == 0) {
		cout << "数据为空" << endl;
	}
	else {
		cout << "请输入查找的职工姓名：" << endl;
		char str[20];
		cin >> str;

		bool flag = false;  //查找到的标志

		//遍历数组查找
		for (int i = 0; i < this->getEmpNum(); i++) {
			if (strcmp(str, this->m_EmpArray[i]->m_Name) == 0) {
				cout << "查找成功,信息如下：" << endl;
				flag = true;
				this->m_EmpArray[i]->showInfo();
				break;
			}
		}
		if (flag == false) {
			//查无此人
			cout << "查找失败，查无此人" << endl;
		}
	}
	this->cls();
}


//通过序号查找
void Employee::resByNum() {
	//判断数据是否为空
	if (Employee::m_EmpNum == 0) {
		cout << "数据为空" << endl;
	}
	else {
		cout << "请输入查找的职工编号：" << endl;
		int tmp = 0;
		cin >> tmp;

		bool flag = false;  //查找到的标志

		//遍历数组查找
		for (int i = 0; i < this->getEmpNum(); i++) {
			if (tmp == this->m_EmpArray[i]->m_ID) {
				cout << "查找成功,信息如下：" << endl;
				flag = true;
				this->m_EmpArray[i]->showInfo();
				break;
			}
		}
		if (flag == false) {
			//查无此人
			cout << "查找失败，查无此人" << endl;
		}
	}
	this->cls();
}

//计算部门平均工资
void Employee::calSalary() {
	//判断数据是否为空
	if (Employee::m_EmpNum == 0) {
		cout << "数据为空" << endl;
	}
	else {
		cout << "请输入要计算的的部门名称：" << endl;
		char str[20];
		cin >> str;

		bool flag = false;  //查找到的标志
		int sum = 0;
		int num = 0;

		//遍历数组查找
		for (int i = 0; i < Employee::m_EmpNum; i++) {
			if (strcmp(str, this->m_EmpArray[i]->m_Department) == 0) {

				flag = true;
				sum += this->m_EmpArray[i]->m_Salary;
				num++;
			}
		}
		if (flag == true) {
			cout << "该部门的平均工资为：" << sum/num << endl;
		}
		else {
			cout << "查找失败，部门不存在" << endl;
		}
	}
	this->cls();
}


//显示所有职工信息
void Employee::showEmp(){
	if (getEmpNum() > 0) {
		for (int i = 0; i < getEmpNum(); i++) {
			m_EmpArray[i]->showInfo();
		}
	}
	else {
		cout << "无职工信息" << endl;
	}


	this->cls();
}




//判断职工是否存在
//存在则返回其在数组中的位置，否则返回-1
int Employee::isExist(int ID) {
	int index = -1;

	for (int i = 0; i < this->getEmpNum(); i++) {
		if (ID == Employee::m_EmpArray[i]->m_ID) {
			//如果找到
			index = i;
			break;
		}
	}
	return index;
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
	ofs.open(FILENAME, ios::out);
	//ofs.open(FILENAME, ios::out | ios::binary);

	for (int i = 0; i < Employee::m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID 
			<< this->m_EmpArray[i]->m_Name 
			<< this->m_EmpArray[i]->m_Sex 
			<< this->m_EmpArray[i]->m_PhoneNumber 
			<< this->m_EmpArray[i]->m_Department 
			<< this->m_EmpArray[i]->m_Salary << endl;
		 
		//ofs.write((const char*)m_EmpArray[i], sizeof(Employee));
	}

	ofs.close();

	//写入职工人数
	ofs.open(EMPNUM, ios::binary);
	ofs.write((const char*)&m_EmpNum, sizeof(int));
	ofs.close();

}

//获取文件中的职工人数
int Employee::getEmpNum() {
	ifstream ifs(EMPNUM, ios::binary);
	int tmp;
	ifs.read((char*)&tmp, sizeof(int));
	ifs.close();
	if (tmp < 0) {
		tmp = 0;
	}
	return tmp;
}

//按任意键返回 清屏
void Employee::cls() {
	system("pause");
	system("cls");
}