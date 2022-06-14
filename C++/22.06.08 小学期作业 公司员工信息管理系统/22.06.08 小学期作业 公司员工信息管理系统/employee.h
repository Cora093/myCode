#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
#include <cstring>
#include <fstream>
#define FILENAME "empFile.txt"
#define EMPNUM "empNumber.txt"




class Employee {
public:
	//成员函数
	//构造函数
	Employee();

	Employee(int id, char name[20], char sex[20], char phoneNum[20], char dept[20], int salary);

	//析构函数
	~Employee();

	//退出系统
	void exitSys();

	//增加职工
	void addEmp();

	//删除职工
	void delEmp();

	//修改职工
	void modEmp();

	//通过姓名查找
	void resByName();

	//通过序号查找
	void resByNum();

	//计算部门平均工资
	void calSalary();

	//显示所有职工信息
	void showEmp();

	






	//显示某员工
	void showInfo();

	//显示菜单
	void showMenu();

	//保存文件
	void save();

	//获取文件中的职工人数
	int getEmpNum();

	//判断职工是否存在
	//存在则返回其在数组中的位置，否则返回-1
	int isExist(int ID);

	//按任意键返回 清屏
	void cls();

	//成员属性
	//工号
	int m_ID;

	//姓名
	char m_Name[20];

	//性别
	char m_Sex[20];

	//手机号码
	char m_PhoneNumber[20];

	//科室
	char m_Department[20];

	//工资
	int m_Salary;


	//职工人数
	static int m_EmpNum;

	//职工数组指针
	static Employee** m_EmpArray;
};


