#include "employee.h"

//���캯��
Employee::Employee() {
	this->m_ID = 0;
	this->m_PhoneNumber = 0;
	this->m_Salary = 0;

	int tmpNum = 0;			//��ʱ���ְ������
	tmpNum = this->getEmpNum();
	if (tmpNum > 0) {		//���ְ������>0
		//��������
		Employee::m_EmpArray = new Employee* [tmpNum];

		//��ȡ����
		ifstream ifs(FILENAME, ios::binary);	//���ļ�

		for (int i = 0; i < tmpNum; i++) {				//��������
			ifs.read((char*)Employee::m_EmpArray[i], sizeof(Employee));
		}
		
		//�ر��ļ�
		ifs.close();

	}
}

Employee::Employee(int id, char name[20], char sex[20], long phoneNum, char dept[20], int salary) {
	this->m_ID = id;
	strcpy(this->m_Name, &name[20]);
	strcpy(this->m_Sex, &sex[20]);
	this->m_PhoneNumber = phoneNum;
	strcpy(this->m_Department, &dept[20]);
	this->m_Salary = salary;
}

//��������
Employee::~Employee() {
	if (Employee::m_EmpArray != NULL) {
		Employee::m_EmpArray = NULL;
		Employee::m_EmpNum = 0;
	}
}

//�˳�ϵͳ
void Employee::exitSys() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

//����ְ��
void Employee::addEmp() {
	cout << "���������������" << endl;
	int addNum = 0;				//�������
	cin >> addNum;

	if (addNum > 0) {			//������������ȷ
		//ʵ����ӹ���
		//������Ӻ�Ŀռ��С
		int newSize = Employee::m_EmpNum + addNum;

		//�����¿ռ�
		Employee** newSpace = new Employee* [newSize];

		//����ԭ������
		if (Employee::m_EmpArray != NULL) {
			for (int i = 0; i < newSize; i++) {
				newSpace[i] = Employee::m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int ID;
			char name[20];
			char sex[20];
			long phoneNum;
			char dept[20];
			int salary;

			char tmp[20];

			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> ID;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���Ա�:" << endl;
			cin >> tmp;	
			cout << "�������" << i + 1 << "����ְ���绰����:" << endl;
			cin >> phoneNum;			
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> tmp;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> salary;

			newSpace[Employee::m_EmpNum + i] = new Employee(ID, name, sex, phoneNum, dept, salary);
		}

		//�ͷ�ԭ�пռ�
		delete[] Employee::m_EmpArray;

		//����ָ��ָ���¿ռ�
		Employee::m_EmpArray = newSpace;

		//�����µ�ְ������
		Employee::m_EmpNum = newSize;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;


		//���浽�ļ�
		save();
	}
	else {
		cout << "�����������" << endl;
	}

	//����������� ����
	this->cls();
}

//��ʾ����ְ����Ϣ
void Employee::showEmp(){
	if (Employee::m_EmpNum > 0) {
		for (int i = 0; i < Employee::m_EmpNum; i++) {
			Employee::m_EmpArray[i]->showInfo();
		}
	}
	else {
		cout << "��ְ����Ϣ" << endl;
	}


	this->cls();
}










//��ʾ�˵�
void Employee::showMenu(){
	cout << "********************************************" << endl;
	cout << "******  ��ӭʹ�ù�˾Ա����Ϣ����ϵͳ *******" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.ɾ��ְ����Ϣ  *************" << endl;
	cout << "*************  3.�޸�ְ����Ϣ  *************" << endl;
	cout << "**********  4.����������ְ����Ϣ  **********" << endl;
	cout << "**********  5.�����Ҳ���ְ����Ϣ  **********" << endl;
	cout << "********  6.������ͳ��ְ��ƽ������  ********" << endl;
	cout << "***********  7.�鿴����ְ����Ϣ  ***********" << endl;
	cout << "*************  0.�˳�����ϵͳ  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//��ʾĳԱ����Ϣ
void Employee::showInfo() {
	cout << "���ţ� " << this->m_ID
		<< " \t������ " << this->m_Name
		<< " \t�Ա�" << this->m_Sex
		<< " \t�ֻ����룺" << this->m_PhoneNumber
		<< " \t���ң�" << this->m_Department
		<< " \t���ʣ�" << this->m_Salary
		<< endl;

}

//�����ļ�
void Employee::save() {
	//�������ļ�д��
	ofstream ofs;

	//д���Ա����
	ofs.open(FILENAME, ios::binary);
	for (int i = 0; i < Employee::m_EmpNum; i++) {
		ofs.write((const char*)Employee::m_EmpArray[i], sizeof(Employee));
	}
	ofs.close();

	//д��ְ������
	ofs.open(EMPNUM, ios::out);
	ofs << Employee::m_EmpNum;
	ofs.close();

}

//��ȡ�ļ��е�ְ������
int Employee::getEmpNum() {
	ifstream ifs(EMPNUM, ios::in);
	int tmp;
	ifs >> tmp;
	ifs.close();
	return tmp;
}

//����������� ����
void Employee::cls() {
	system("pause");
	system("cls");
}