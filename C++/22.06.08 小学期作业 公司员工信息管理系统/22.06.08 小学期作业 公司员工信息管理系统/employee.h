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

	Employee(int id, char name[20], char sex[20], long phoneNum, char dept[20], int salary);

	//析构函数
	~Employee();

	//退出系统
	void exitSys();

	//增加职工
	void addEmp();


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
	long m_PhoneNumber;

	//科室
	char m_Department[20];

	//工资
	int m_Salary;

	//职工人数
	static int m_EmpNum;

	//职工数组指针
	static Employee** m_EmpArray;


	Employee(int, int, int);
};