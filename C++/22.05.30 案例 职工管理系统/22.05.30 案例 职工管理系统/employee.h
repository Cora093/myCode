//��ͨԱ����ͷ�ļ�
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Employee :public Worker {
public:
	Employee(int id,string name,int did);
	//��ʾ������Ϣ
	void showInfo();
	//��ȡ��λ����
	string getDeptName();

};