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

	Employee(int id, char name[20], char sex[20], char phoneNum[20], char dept[20], int salary);

	//��������
	~Employee();

	//�˳�ϵͳ
	void exitSys();

	//����ְ��
	void addEmp();

	//ɾ��ְ��
	void delEmp();

	//�޸�ְ��
	void modEmp();

	//ͨ����������
	void resByName();

	//ͨ����Ų���
	void resByNum();

	//���㲿��ƽ������
	void calSalary();

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

	//�ж�ְ���Ƿ����
	//�����򷵻����������е�λ�ã����򷵻�-1
	int isExist(int ID);

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
	char m_PhoneNumber[20];

	//����
	char m_Department[20];

	//����
	int m_Salary;


	//ְ������
	static int m_EmpNum;

	//ְ������ָ��
	static Employee** m_EmpArray;
};


