#include "workerManager.h"


//构造函数
WorkerManager::WorkerManager() {

	//1.当文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//读文件
	if (!ifs.is_open()) {			//未打开成功，说明文件不存在
		this->m_EmpNum = 0;			//初始化数据
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	} 

	//2.当文件存在 但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {				//判断文件已经读完了

		this->m_EmpNum = 0;			//初始化数据
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在且不为空
	this->m_EmpNum = this->getEmpNum();

	//开辟空间
	this->m_EmpArray = new Worker* [m_EmpNum];

	//将文件中的数据读到数组中
	this->initEmp();


}

//析构函数
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0); //退出程序
}

//添加职工
void WorkerManager::addEmp() {
	cout << "请输入添加数量：" << endl;
	int addNum = 0;				//添加数量
	cin >> addNum;
	if (addNum > 0) {			//当数量输入正确
		//添加
		//计算添加后的空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//拷贝原有数据
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < newSize; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int depID;
			cout << "请输入第" << i + 1 << "个新职工编号:" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名:" << endl;
			cin >> name;

			cout << "请选择第" << i + 1 << "个新职工岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> depID;

			Worker* worker = NULL;//创建父类指针

			if (depID == 1) {
				worker = new Employee(id, name, 1);
			}
			else if (depID == 2) {
				worker = new Manager(id, name, 2);
			}
			else if (depID == 3) {
				worker = new Boss(id, name, 3);
			}

			//保存到数组中
			newSpace[this->m_EmpNum + i] = worker;


		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改指针指向新空间
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		this->save();

		//更新状态：职工文件不为空
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工!" << endl;

	}
	else {//当数量输入错误
		cout << "输入数量有误" << endl;
	}

	//按任意键清屏 返回
	system("pause");
	system("cls");
}

//显示职工
void WorkerManager::showEmp() {
	//判断数据是否为空
	if (this->m_FileIsEmpty) {
		cout << "数据为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	//按任意键清屏 返回
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::delEmp() {
	//判断数据是否为空
	if (this->m_FileIsEmpty) {
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
				for (int i = this->isExist(id); i < this->m_EmpNum - 1; i++) {
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				//数组成员数量--
				this->m_EmpNum--;
				//数据同步更新到文件里
				this->save();

				cout << "删除成功!" << endl;
			}
			else {
				cout << "取消操作" << endl;
			}
		}
	}

	//按任意键清屏 返回
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::modEmp() {
	//判断数据是否为空
	if (this->m_FileIsEmpty) {
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
				string newName;
				int newDepID;
				//输入信息
				cout << "请输入更改后的员工编号:" << endl;
				cin >> newID;
				cout << "请输入更改后的员工姓名:" << endl;
				cin >> newName;
				cout << "请输入更改后的员工部门编号:" << endl;
				cout << "1.普通职工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> newDepID;

				//创建父类指针
				Worker* worker = NULL;

				//创建子类对象
				if (newDepID == 1) {
					worker = new Employee(newID, newName, 1);
				}
				else if (newDepID == 2) {
					worker = new Manager(newID, newName, 2);
				}
				else if (newDepID == 3) {
					worker = new Boss(newID, newName, 3);
				}


				//写入数组
				this->m_EmpArray[this->isExist(id)]= worker;

				//数据同步更新到文件里
				this->save();

				cout << "更改成功!" << endl;
			}
			else {
				cout << "取消操作" << endl;
			}
		}
	}

	//按任意键清屏 返回
	system("pause");
	system("cls");
}


//查找职工
void WorkerManager::findEmp() {
	//判断数据是否为空
	if (this->m_FileIsEmpty) {
		cout << "数据为空" << endl;
	}
	else {
		//选择查找方式
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int choice = 0;
		cin >> choice;

		if (choice == 1) {		//按职工号查找
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			//判断是否存在
			int ret = isExist(id);
			if (ret != -1) {
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (choice == 2) {	//按姓名查找
			string name;
			cout << "请输入查找的职工姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			//遍历数组查找
			for (int i = 0; i < m_EmpNum; i++){
				if (m_EmpArray[i]->m_Name == name){
					cout << "查找成功,信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
			
		}
		else {
			cout << "输入错误" << endl;
		}
	}

	//按任意键清屏 返回
	system("pause");
	system("cls");
}

//排序职工
void WorkerManager::sortEmp() {
	//判断数据是否为空
	if (this->m_FileIsEmpty) {
		cout << "数据为空" << endl;

		//按任意键清屏 返回
		system("pause");
		system("cls");
	}
	else {
		//进行选择排序
		for (int i = 0; i < this->m_EmpNum; i++) {
			int min = i;//最小值下标
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (this->m_EmpArray[j]->m_ID < this->m_EmpArray[min]->m_ID) {
					min = j;
				}
			}
			if (i != min) {
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[min];
				this->m_EmpArray[min] = tmp;
			}
		}
		this->save();

		//显示排序结果
		cout << "排序成功，当前结果为：" << endl;
		this->showEmp();

	}

}


//清空文件
void WorkerManager::clenFile() {
	if (this->m_FileIsEmpty) {					//判断数据是否为空
		cout << "数据为空" << endl;
	}
	else {
		cout << "是否确认清空数据1/0" << endl;
		int choice = 0;
		cin >> choice;

		if (choice == 1) {
			//清空文件数据
			ofstream ofs(FILENAME, ios::trunc);	//删除文件后重新创建
			ofs.close();

			//清空数组数据
			if (this->m_EmpArray != NULL) {
				//删除堆区的每个职工对象
				for (int i = 0; i < this->m_EmpNum; i++) {
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}

				//删除堆区数组指针
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}

			cout << "清空成功" << endl;

		}
		else {
			cout << "取消操作" << endl;
		}
	}

	//按任意键清屏 返回
	system("pause");
	system("cls");
}








//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//写文件
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

//获取文件中的员工人数
int WorkerManager::getEmpNum() {

	int ID;
	string name;
	int dID;
	int empNum = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);						//打开文件
	while (ifs >> ID && ifs >> name && ifs >> dID) {	//读取数据
		empNum++;
	}
	ifs.close();										//关闭文件
	return empNum;
}

//初始化员工
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;

	int index = 0;							//计数	
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		//根据不同的部门Id创建不同对象
		if (dID == 1) {						//1 普通员工
			worker = new Employee(ID, name, dID);
		}
		else if (dID == 2) {				//2 经理
			worker = new Manager(ID, name, dID);
		}
		else if (dID == 3) {				//3 总裁
			worker = new Boss(ID, name, dID);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;

		index++;
	}

	ifs.close();
}

//判断职工是否存在
//存在则返回其在数组中的位置，否则返回-1
int WorkerManager::isExist(int ID) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (ID == this->m_EmpArray[i]->m_ID) {
			//如果找到
			index = i;
			break;
		}
	}
	return index;
}


//展示菜单
void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}





