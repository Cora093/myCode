#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker {				//抽象类，不用实现，不用创建.cpp文件
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	int m_ID;				//职工编号
	string m_Name;			//职工姓名
	int m_DeptID;			//部门编号
};
