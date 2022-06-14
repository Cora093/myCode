#pragma once
#include <iostream>
using namespace std;


class Empolyee {
public:
	//该函数添加职工信息
	void AddEmployee(); 

	//该函数删除职工信息
	void DeleteEmployee(); 
	
	//该函数修改职工信息
	void UpdateEmployee(); 
	
	//该函数用于按名字查询职工信息
	void reseachStudentByName(); 


	//该函数用于按科室查询职工信息
	void reseachStudentByOffice();
	
	//该函数统计职工的平均工资
	void add(); 

	//该函数用于对员工信息的书写。
	void SaveInfo(); 



};