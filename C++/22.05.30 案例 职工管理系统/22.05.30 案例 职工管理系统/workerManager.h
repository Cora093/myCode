#pragma once		//防止头文件重复包含
#include <iostream>
using namespace std;
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager {
public:
	//构造函数
	WorkerManager();				

	//析构函数
	~WorkerManager();

	//退出系统
	void exitSystem();

	//添加职工
	void addEmp();

	//显示职工
	void showEmp();

	//删除职工
	void delEmp();

	//修改职工
	void modEmp();

	//查找职工
	void findEmp();

	//排序职工
	void sortEmp();

	//清空文件
	void clenFile();





	//展示菜单
	void showMenu();

	//保存文件
	void save();

	//读取文件中的员工人数
	int getEmpNum();

	//判断职工是否存在
	//存在则返回其在数组中的位置，否则返回-1
	int isExist(int ID);
	
	//初始化员工
	void initEmp();





	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//判断文件是否为空
	bool m_FileIsEmpty;
};
