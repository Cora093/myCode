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
	//��Ա����
	//���캯��
	Employee();

	Employee(int id, char name[20], char sex[20], long phoneNum, char dept[20], int salary);

	//��������
	~Employee();

	//�˳�ϵͳ
	void exitSys();

	//����ְ��
	void addEmp();


	//��ʾ����ְ����Ϣ
	void showEmp();








	//��ʾĳԱ��
	void showInfo();

	//��ʾ�˵�
	void showMenu();

	//�����ļ�
	void save();

	//��ȡ�ļ��е�ְ������
	int getEmpNum();

	//����������� ����
	void cls();

	//��Ա����
	//����
	int m_ID;

	//����
	char m_Name[20];

	//�Ա�
	char m_Sex[20];

	//�ֻ�����
	long m_PhoneNumber;

	//����
	char m_Department[20];

	//����
	int m_Salary;

	//ְ������
	static int m_EmpNum;

	//ְ������ָ��
	static Employee** m_EmpArray;


	Employee(int, int, int);
};