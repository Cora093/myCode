#pragma once		//��ֹͷ�ļ��ظ�����
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
	//���캯��
	WorkerManager();				

	//��������
	~WorkerManager();

	//�˳�ϵͳ
	void exitSystem();

	//���ְ��
	void addEmp();

	//��ʾְ��
	void showEmp();

	//ɾ��ְ��
	void delEmp();

	//�޸�ְ��
	void modEmp();

	//����ְ��
	void findEmp();

	//����ְ��
	void sortEmp();

	//����ļ�
	void clenFile();





	//չʾ�˵�
	void showMenu();

	//�����ļ�
	void save();

	//��ȡ�ļ��е�Ա������
	int getEmpNum();

	//�ж�ְ���Ƿ����
	//�����򷵻����������е�λ�ã����򷵻�-1
	int isExist(int ID);
	
	//��ʼ��Ա��
	void initEmp();





	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};
